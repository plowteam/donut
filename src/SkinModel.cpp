#include <iostream>
#include <SkinModel.h>
#include "glm/gtx/transform.hpp"

namespace Donut {

SkinModel::SkinModel(const std::string& filename) : _filename(filename) {
    _p3dFile = std::make_unique<P3D::P3DFile>(filename);

    const auto& root = _p3dFile->GetRoot();
    for (const auto& chunk : root.GetChildren()) {
        switch (chunk->GetType()) {
        case P3D::ChunkType::PolySkin: {
            P3D::PolySkinLoader loader;
            _polySkin = loader.Load(*chunk.get());

            break;
        }
		case P3D::ChunkType::Skeleton: {
			P3D::SkeletonLoader loader;
			_skeleton = loader.Load(*chunk.get());

			break;
		}
        default:
            break;
        }
    }

    createMesh();
}

std::string vertexShader = R"glsl(
	#version 150 core

	in vec3 position;
	in vec3 normal;
	in vec2 uv;
	in vec3 boneWeights;
	in ivec3 boneIndices;

	out vec2 texCoord;
	out vec3 Normal;

	uniform mat4 viewProj;
	uniform samplerBuffer boneBuffer;

	mat4 GetMatrix(int index)
	{
		return mat4(texelFetch(boneBuffer, (index * 4) + 0),
				    texelFetch(boneBuffer, (index * 4) + 1),
				    texelFetch(boneBuffer, (index * 4) + 2),
				    texelFetch(boneBuffer, (index * 4) + 3));
	}

	void main()
	{
		mat4 boneMatrix = GetMatrix(boneIndices[0]) * boneWeights[0];
		boneMatrix += GetMatrix(boneIndices[1]) * boneWeights[1];
		boneMatrix += GetMatrix(boneIndices[2]) * boneWeights[2];

		texCoord = uv;
		Normal = normal;
		gl_Position = viewProj * (boneMatrix * vec4(position, 1.0));
	}
)glsl";

std::string fragmentShader = R"glsl(
	#version 150 core

	uniform sampler2D diffuseTex;

	in vec2 texCoord;
	in vec3 Normal;
	out vec4 outColor;

	void main()
	{
	    vec3 n = normalize(Normal);
	    vec3 light0Position = normalize(vec3(-0.4, 0.5, -0.6));
	    float NdotL0 = clamp(dot(n, light0Position), 0.0, 1.0);
	    vec3 diffuse = vec3(NdotL0 + 0.5);
	    diffuse.rgb = clamp(diffuse.rgb, 0.0, 1.0);
        vec3 diffuseColor = texture2D(diffuseTex, texCoord).rgb;

        outColor = vec4(diffuseColor * diffuse, 1.0);
	}
)glsl";

void SkinModel::createMesh() {
    _shader = std::make_unique<GL::ShaderProgram>(vertexShader, fragmentShader);

    std::vector<Vertex> allVerts;
    std::vector<std::uint32_t> allIndices;

	auto const& joints = _skeleton->GetJoints();

	for (auto const& joint : _skeleton->GetJoints()) {
		std::cout << joint->GetName() << std::endl;
	}

    std::uint32_t vertOffset = 0;
    for (auto const& prim : _polySkin->GetPrimGroups()) {
        auto verts = prim->GetVerticies();
		auto uvs = prim->GetUV();
		auto normals = prim->GetNormals();
		auto indices = prim->GetIndices();
		auto weights = prim->GetWeights();
		auto matrixList = prim->GetMatrixList();
		auto matrixPalette = prim->GetMatrixPalette();

		bool hasBoneIndices = !matrixList.empty() && !matrixPalette.empty();
		bool hasWeights = !weights.empty();

        for (std::uint32_t i = 0; i < verts.size(); i++) {

			auto boneIndices = hasBoneIndices ? glm::ivec3(
				matrixPalette[matrixList[(i * 4) + 3]],
				matrixPalette[matrixList[(i * 4) + 2]],
				matrixPalette[matrixList[(i * 4) + 1]]
			) : glm::ivec3(0, 0, 0);

			auto weight = hasWeights ? weights[i] : glm::vec3(1, 0, 0);

            allVerts.push_back(Vertex
			{
				verts[i],
				normals[i],
				glm::vec2(uvs[i].x, 1.0f - uvs[i].y),
				weight,
				boneIndices
			});
        }

        for (std::uint32_t i = 0; i < indices.size(); i++) {
            allIndices.push_back(indices[i] + vertOffset);
        }

        vertOffset += verts.size();
    }

    glGenVertexArrays(1, &_vertexArrayObject);
    glBindVertexArray(_vertexArrayObject);

    _vertexBuffer =
        std::make_unique<GL::VertexBuffer>(allVerts.data(), allVerts.size(), sizeof(Vertex));
    _indexBuffer =
        std::make_unique<GL::IndexBuffer>(allIndices.data(), allIndices.size(), GL_UNSIGNED_INT);

	_boneBuffer = std::make_unique<GL::TextureBuffer>();
	_boneMatrices.resize(joints.size(), glm::mat4(1.0f));
	_poseMatrices.resize(joints.size(), glm::mat4(1.0f));

	for (uint32_t jointIndex = 0; jointIndex < joints.size(); ++jointIndex) {
		//_boneMatrices[jointIndex] = glm::inverse(joints[jointIndex]->GetRestPose()) * _boneMatrices[joints[jointIndex]->GetParent()];
	}

	auto translate = glm::translate(glm::vec3(0, 0.5f, 0));
	//glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), 3.14f, glm::vec3(0, 1, 0));
	//_boneMatrices[17] = translate;
	//_boneMatrices[18] = translate;
	_boneBuffer->SetBuffer(_boneMatrices.data(), _boneMatrices.size() * sizeof(glm::mat4));

	int ptr = 0;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)ptr);
    ptr += sizeof(glm::vec3);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)ptr);
	ptr += sizeof(glm::vec3);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)ptr);
    ptr += sizeof(glm::vec2);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)ptr);
    ptr += sizeof(glm::vec3);
    glVertexAttribIPointer(4, 3, GL_INT, sizeof(Vertex), (GLvoid*)ptr);
    ptr += sizeof(glm::ivec3);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	glEnableVertexAttribArray(4);

    glBindVertexArray(0);
}

void SkinModel::Draw(glm::mat4& viewProj) {
    _shader->Bind();
    _shader->SetUniformValue("viewProj", viewProj);

	glActiveTexture(GL_TEXTURE1);
	_boneBuffer->Bind();
	_shader->SetUniformValue("boneBuffer", 1);

    glBindVertexArray(_vertexArrayObject);

    std::uint32_t idxOffset = 0;
    for (auto const& prim : _polySkin->GetPrimGroups()) {
        auto indicesSize = prim->GetIndices().size();

        GLenum mode = GL_TRIANGLE_STRIP;
		switch (prim->GetPrimitiveType()) {
		case P3D::PrimGroup::PrimitiveType::TriangleStrip:
            mode = GL_TRIANGLE_STRIP;
            break;
        case P3D::PrimGroup::PrimitiveType::TriangleList:
            mode = GL_TRIANGLES;
            break;
        case P3D::PrimGroup::PrimitiveType::LineStrip:
            mode = GL_LINE_STRIP;
            break;
        case P3D::PrimGroup::PrimitiveType::LineList:
            mode = GL_LINES;
            break;
		}

        glDrawElements(mode, indicesSize, _indexBuffer->GetType(), (void*)(idxOffset * 4));
        idxOffset += indicesSize;
    }

    glBindVertexArray(0);
}

} // namespace Donut
