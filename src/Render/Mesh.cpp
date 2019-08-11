// Copyright 2019 the donut authors. See AUTHORS.md

#include <Render/Mesh.h>
#include <Render/SkinModel.h>
#include <vector>

#include <Game.h>
#include <Render/Shader.h>

namespace Donut
{

Mesh::Mesh(const P3D::Mesh& mesh):
    _name(mesh.GetName())
{
	CreateMeshBuffers(mesh);
}

void Mesh::Commit()
{
	CreateVertexBinding();
}

void Mesh::CreateVertexBinding()
{
	static const size_t vertStride = sizeof(Vertex);

	GL::ArrayElement vertexLayout[] =
	{
		GL::ArrayElement(_vertexBuffer.get(), 0, 3, GL::AE_FLOAT, vertStride, 0),
		GL::ArrayElement(_vertexBuffer.get(), 1, 2, GL::AE_FLOAT, vertStride, 3 * sizeof(float)),
		GL::ArrayElement(_vertexBuffer.get(), 2, 4, GL::AE_FLOAT, vertStride, 5 * sizeof(float)),
	};

	_vertexBinding = std::make_shared<GL::VertexBinding>();
	_vertexBinding->Create(vertexLayout, 3, *_indexBuffer, GL::ElementType::AE_UINT);
}

void Mesh::CreateMeshBuffers(const P3D::Mesh& mesh)
{
	std::vector<Vertex> allVerts;
	std::vector<uint32_t> allIndices;

	size_t vertOffset = 0;
	size_t idxOffset = 0;
	for (auto const& prim : mesh.GetPrimitiveGroups())
	{
		auto verts = prim->GetVertices();
		auto uvs = prim->GetUvs(0);
		auto colors = prim->GetColors();
		auto indices = prim->GetIndices();
		bool hasColors = !colors.empty();

		for (uint32_t i = 0; i < verts.size(); i++)
		{
			allVerts.push_back(Vertex{
				verts[i],
				glm::vec2(uvs[i].x, 1.0f - uvs[i].y),
				hasColors ? P3D::P3DUtil::ConvertColor(colors[i]) : glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
				});
		}

		for (auto const& idx : prim->GetIndices())
		{
			allIndices.push_back(idx + static_cast<uint32_t>(vertOffset));
		}

		vertOffset += verts.size();

		GLenum mode = GL_TRIANGLE_STRIP;
		switch ((P3D::PrimitiveType)prim->GetPrimType())
		{
		case P3D::PrimitiveType::TriangleStrip:
			mode = GL_TRIANGLE_STRIP;
			break;
		case P3D::PrimitiveType::TriangleList:
			mode = GL_TRIANGLES;
			break;
		case P3D::PrimitiveType::LineStrip:
			mode = GL_LINE_STRIP;
			break;
		case P3D::PrimitiveType::LineList:
			mode = GL_LINES;
			break;
		}

		_primGroups.emplace_back(PrimGroup{ prim->GetShaderName(), mode, idxOffset, indices.size() });
		idxOffset += indices.size();
	}

	_vertexBuffer =
		std::make_shared<GL::VertexBuffer>(allVerts.data(), allVerts.size(), sizeof(Vertex));
	_indexBuffer =
		std::make_shared<GL::IndexBuffer>(allIndices.data(), allIndices.size(), GL_UNSIGNED_INT);
}

void Mesh::Draw(GL::ShaderProgram& shader, bool opaque)
{
	_vertexBinding->Bind();

	for (auto& prim : _primGroups)
	{
		if (prim.cacheShader == nullptr)
			prim.cacheShader = Game::GetInstance().GetResourceManager().GetShader(prim.shaderName).get();

		bool trans = (!prim.cacheShader->IsAlphaTested() && prim.cacheShader->IsTranslucent());

		if (trans && opaque)
		{
			continue;
		}

		if (!trans && !opaque)
		{
			continue;
		}

		if (!opaque)
		{
			auto blendMode = prim.cacheShader->GetBlendMode();

			if (blendMode == BlendMode::Alpha)
			{
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			}
			else if (blendMode == BlendMode::Additive)
			{
				glBlendFunc(GL_ONE, GL_ONE);
			}
		}

		shader.SetUniformValue("alphaMask", (prim.cacheShader->IsAlphaTested()) ? 0.5f : 0.0f);
		prim.cacheShader->Bind(0);

		DrawPrimGroup(prim);
	}

	_vertexBinding->Unbind();
}

void Mesh::DrawPrimGroup(const PrimGroup& primGroup)
{
	glDrawElements(
		primGroup.type,
		static_cast<GLsizei>(primGroup.indicesCount),
		_indexBuffer->GetType(),
		reinterpret_cast<void*>(primGroup.indicesOffset * 4));
}





MeshInstanced::MeshInstanced(const P3D::Mesh& mesh, const std::vector<glm::mat4>& transforms) :
	Mesh(mesh),
	_transforms(std::move(transforms))
{
}

void MeshInstanced::CreateVertexBinding()
{
	static const size_t vertStride = sizeof(Mesh::Vertex);
	static const size_t instanceStride = sizeof(glm::mat4);

	_instanceBuffer =
		std::make_shared<GL::VertexBuffer>(_transforms.data(), _transforms.size(), instanceStride);

	GL::ArrayElement vertexLayout[] =
	{
		GL::ArrayElement(_vertexBuffer.get(), 0, 3, GL::AE_FLOAT, vertStride, 0),
		GL::ArrayElement(_vertexBuffer.get(), 1, 2, GL::AE_FLOAT, vertStride, 3 * sizeof(float)),
		GL::ArrayElement(_vertexBuffer.get(), 2, 4, GL::AE_FLOAT, vertStride, 5 * sizeof(float)),

		GL::ArrayElement(_instanceBuffer.get(), 3, 4, GL::AE_FLOAT, instanceStride, 0, 1),
		GL::ArrayElement(_instanceBuffer.get(), 4, 4, GL::AE_FLOAT, instanceStride, 4 * sizeof(float), 1),
		GL::ArrayElement(_instanceBuffer.get(), 5, 4, GL::AE_FLOAT, instanceStride, 8 * sizeof(float), 1),
		GL::ArrayElement(_instanceBuffer.get(), 6, 4, GL::AE_FLOAT, instanceStride, 12 * sizeof(float), 1),
	};

	_vertexBinding = std::make_shared<GL::VertexBinding>();
	_vertexBinding->Create(vertexLayout, 7, *_indexBuffer, GL::ElementType::AE_UINT);
}

void MeshInstanced::DrawPrimGroup(const PrimGroup& primGroup)
{
	glDrawElementsInstanced(
		primGroup.type,
		static_cast<GLsizei>(primGroup.indicesCount),
		_indexBuffer->GetType(),
		reinterpret_cast<void*>(primGroup.indicesOffset * 4),
		(GLsizei)_transforms.size());
}



} // namespace Donut
