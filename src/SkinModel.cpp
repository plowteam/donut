#include <glm/gtx/transform.hpp>
#include <SkinModel.h>
#include <iostream>
#include <P3D/Texture.h>

namespace Donut
{

SkinModel::SkinModel(const std::string& filename):
    _filename(filename),
	_animTime(0.0f),
	_animIndex(19)
{
	_textures = std::map<std::string, std::unique_ptr<GL::Texture2D>>();

	_p3dFile = std::make_unique<P3D::P3DFile>(filename);

	const auto& root = _p3dFile->GetRoot();
	for (const auto& chunk : root.GetChildren())
	{
		switch (chunk->GetType())
		{
		case P3D::ChunkType::Shader:
		{
			auto shader = P3D::Shader::Load(*chunk);
			_shaders[shader->GetName()] = std::move(shader);
			break;
		}
		case P3D::ChunkType::Texture:
		{
			auto texture = P3D::Texture::Load(*chunk);
			auto texdata                  = texture->GetData();
			_textures[texture->GetName()] = std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, texdata.data.data());
			break;
		}
		case P3D::ChunkType::PolySkin:
			_polySkin = P3D::PolySkin::Load(*chunk);
			break;
		case P3D::ChunkType::Skeleton:
			_skeleton = P3D::Skeleton::Load(*chunk);
			break;
		default: break;
		}
	}

	createMesh();
}

void SkinModel::LoadAnimations(const std::string& filename)
{
	if (!std::filesystem::exists(filename)) return;

	_animP3D = std::make_unique<P3D::P3DFile>(filename);

	const auto& root = _animP3D->GetRoot();
	for (const auto& chunk : root.GetChildren())
	{
		switch (chunk->GetType())
		{
		case P3D::ChunkType::Animation:
		{
			CreateAnimation(*P3D::Animation::Load(*chunk.get()).get());
			break;
		}
		default: break;
		}
	}


	UpdateAnimation(_animIndex, 0.0f);
}

void SkinModel::CreateAnimation(const P3D::Animation& p3dAnim)
{
	auto p3dGroupList = p3dAnim.GetGroupList();
	if (p3dGroupList == nullptr) return;

	auto animation = std::make_unique<SkinAnimation>(
		p3dAnim.GetName(),
		p3dAnim.GetNumFrames() / p3dAnim.GetFrameRate(),
		(int32_t)p3dAnim.GetNumFrames(),
		p3dAnim.GetFrameRate());

	auto const& joints = _skeleton->GetJoints();

	for (auto const& joint : _skeleton->GetJoints())
	{
		auto track = std::make_unique<SkinAnimation::Track>(joint->GetName());

		const auto& jointRestPose = joint->GetRestPose();
		const auto& jointTranslation = jointRestPose[3];
		const auto& jointRotation = glm::quat_cast(jointRestPose);

		auto p3dGroup = p3dGroupList->GetGroup(joint->GetName());
		if (p3dGroup == nullptr)
		{
			track->AddTranslationKey(0, jointTranslation);
			track->AddRotationKey(0, jointRotation);
		}
		else
		{
			auto vector2Channel = p3dGroup->GetVector2Channel();
			auto vector3Channel = p3dGroup->GetVector3Channel();
			auto quaternionChannel = p3dGroup->GetQuaternionChannel();
			auto compressedQuaternionChannel = p3dGroup->GetCompressedQuaternionChannel();

			if (vector3Channel != nullptr)
			{
				const auto& frames = vector3Channel->GetFrames();
				const auto& values = vector3Channel->GetValues();

				for (size_t i = 0; i < vector3Channel->GetNumFrames(); ++i)
				{
					track->AddTranslationKey(frames[i], values[i]);
				}
			}
			else
			{
				track->AddTranslationKey(0, jointTranslation);
			}

			if (compressedQuaternionChannel != nullptr)
			{
				const auto& frames = compressedQuaternionChannel->GetFrames();
				const auto& values = compressedQuaternionChannel->GetValues();

				for (size_t i = 0; i < compressedQuaternionChannel->GetNumFrames(); ++i)
				{
					track->AddRotationKey(frames[i], values[i]);
				}
			}
			else
			{
				track->AddRotationKey(0, jointRotation);
			}
		}

		animation->AddTrack(track);
	}

	AnimationNames.push_back(p3dAnim.GetName());
	_animations.push_back(std::move(animation));
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

void SkinModel::createMesh()
{
	_shader = std::make_unique<GL::ShaderProgram>(vertexShader, fragmentShader);

	std::vector<Vertex> allVerts;
	std::vector<uint32_t> allIndices;

	auto const& joints = _skeleton->GetJoints();

	size_t vertOffset = 0;
	for (auto const& prim : _polySkin->GetPrimGroups())
	{
		auto verts         = prim->GetVerticies();
		auto uvs           = prim->GetUV();
		auto normals       = prim->GetNormals();
		auto indices       = prim->GetIndices();
		auto weights       = prim->GetWeights();
		auto matrixList    = prim->GetMatrixList();
		auto matrixPalette = prim->GetMatrixPalette();

		bool hasBoneIndices = !matrixList.empty() && !matrixPalette.empty();
		bool hasWeights     = !weights.empty();

		for (uint32_t i = 0; i < verts.size(); i++)
		{
			auto boneIndices = hasBoneIndices
			                       ? glm::ivec3(
			                             matrixPalette[matrixList[(i * 4) + 3]],
			                             matrixPalette[matrixList[(i * 4) + 2]],
			                             matrixPalette[matrixList[(i * 4) + 1]])
			                       : glm::ivec3(0, 0, 0);

			auto weight = hasWeights ? weights[i] : glm::vec3(1, 0, 0);

			allVerts.push_back(Vertex {
			    verts[i],
			    normals[i],
			    glm::vec2(uvs[i].x, 1.0f - uvs[i].y),
			    weight,
			    boneIndices });
		}

		for (uint32_t i = 0; i < indices.size(); i++)
		{
			allIndices.push_back(indices[i] + static_cast<uint32_t>(vertOffset));
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
	_boneMatrices.resize(joints.size(), glm::mat4(1.0f));  // Skeleton matrices, these don't change
	_poseMatrices.resize(joints.size(), glm::mat4(1.0f));  // Pose matrices, these change with animation
	_finalMatrices.resize(joints.size(), glm::mat4(1.0f)); // Final matrices, rest pose matrix inverse * pose matrix

	for (uint32_t jointIndex = 0; jointIndex < joints.size(); ++jointIndex)
	{
		_boneMatrices[jointIndex] = _boneMatrices[joints[jointIndex]->GetParent()] * joints[jointIndex]->GetRestPose();
	}

	_boneBuffer->SetBuffer(_finalMatrices.data(), _finalMatrices.size() * sizeof(glm::mat4));

	size_t ptr = 0;
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

void SkinModel::Update(double dt)
{
	_animTime += dt;
	UpdateAnimation(_animIndex, _animTime);
}

void SkinModel::UpdateAnimation(size_t animIndex, double time)
{
	if (animIndex >= _animations.size()) return;

	const auto& animation = _animations[animIndex];
	auto const& joints = _skeleton->GetJoints();

	time *= animation->GetFrameRate();

	_poseMatrices[0] = glm::mat4(1.0f);

	for (uint32_t jointIndex = 0; jointIndex < joints.size(); ++jointIndex)
	{
		_poseMatrices[jointIndex] = _poseMatrices[joints[jointIndex]->GetParent()] * animation->Evaluate(jointIndex, time);
	}

	for (uint32_t jointIndex = 0; jointIndex < joints.size(); ++jointIndex)
	{
		_finalMatrices[jointIndex] = _poseMatrices[jointIndex] * glm::inverse(_boneMatrices[jointIndex]);
	}

	_boneBuffer->SetBuffer(_finalMatrices.data(), _finalMatrices.size() * sizeof(glm::mat4));
}

void SkinModel::Draw(const ResourceManager& rm, glm::mat4& viewProj)
{
	_shader->Bind();
	_shader->SetUniformValue("viewProj", viewProj);

	glActiveTexture(GL_TEXTURE1);
	_boneBuffer->Bind();
	_shader->SetUniformValue("boneBuffer", 1);

	glBindVertexArray(_vertexArrayObject);

	size_t idxOffset = 0;
	for (auto const& prim : _polySkin->GetPrimGroups())
	{
		auto indicesSize = (GLsizei)prim->GetIndices().size();

		GLenum mode = GL_TRIANGLE_STRIP;
		switch (prim->GetPrimitiveType())
		{
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

		_shader->SetUniformValue("diffuseTex", 0);

		const auto& shader = _shaders[prim->GetShaderName()];
		const auto& texName = shader->GetTexture();

		if (_textures.find(texName) == _textures.end())
			rm.GetTexture(texName).Bind(0);
		else
			_textures.at(texName)->Bind(0);

		glDrawElements(mode, indicesSize, _indexBuffer->GetType(), (void*)(idxOffset * 4));
		idxOffset += indicesSize;
	}

	glBindVertexArray(0);
}
} // namespace Donut
