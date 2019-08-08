// Copyright 2019 the donut authors. See AUTHORS.md

#include <Render/Mesh.h>
#include <Render/SkinModel.h>
#include <vector>

#include <Game.h>
#include <Render/Shader.h>

namespace Donut
{

static glm::vec4 ConvertColor(uint32_t v)
{	
	return glm::vec4(((v >> 16) & 255) / 255.0f,
					 ((v >> 8) & 255) / 255.0f,
					 ((v & 255)) / 255.0f,
					 ((v >> 24) & 255) / 255.0f);
}

Mesh::Mesh(const P3D::Mesh& mesh, bool instanced):
    _name(mesh.GetName())
{
	std::vector<Vertex> allVerts;
	std::vector<uint32_t> allIndices;

	size_t vertOffset = 0;
	size_t idxOffset = 0;
	for (auto const& prim : mesh.GetPrimitiveGroups())
	{
		auto verts         = prim->GetVertices();
		auto uvs           = prim->GetUvs(0);
		auto colors        = prim->GetColors();
		auto indices       = prim->GetIndices();
		bool hasColors = !colors.empty();

		for (uint32_t i = 0; i < verts.size(); i++)
		{
			allVerts.push_back(Vertex {
			    verts[i],
			    glm::vec2(uvs[i].x, 1.0f - uvs[i].y),
				hasColors ? ConvertColor(colors[i]) : glm::vec4(1.0f, 1.0f, 1.0f, 1.0f),
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

		_primGroups.emplace_back(PrimGroup { prim->GetShaderName(), mode, idxOffset, indices.size()});
		idxOffset += indices.size();
	}

	_vertexBuffer =
	    std::make_unique<GL::VertexBuffer>(allVerts.data(), allVerts.size(), sizeof(Vertex));
	_indexBuffer =
	    std::make_unique<GL::IndexBuffer>(allIndices.data(), allIndices.size(), GL_UNSIGNED_INT);
	_instanceBuffer =
		std::make_unique<GL::VertexBuffer>(allVerts.data(), 10, sizeof(glm::mat4));

	static const size_t vertStride = sizeof(Vertex);

	GL::ArrayElement vertexLayout[] =
	{
		GL::ArrayElement(_vertexBuffer.get(), 0, 3, GL::AE_FLOAT, vertStride, 0),
		GL::ArrayElement(_vertexBuffer.get(), 1, 2, GL::AE_FLOAT, vertStride, 3 * sizeof(float)),
		GL::ArrayElement(_vertexBuffer.get(), 2, 4, GL::AE_FLOAT, vertStride, 5 * sizeof(float)),
	};

	_vertexBinding = std::make_unique<GL::VertexBinding>();
	_vertexBinding->Create(vertexLayout, 3, *_indexBuffer, GL::ElementType::AE_UINT);
}

void Mesh::Draw(bool opaque)
{
	_vertexBinding->Bind();

	for (auto& prim : _primGroups)
	{
		if (prim.cacheShader == nullptr)
			prim.cacheShader = Game::GetInstance().GetResourceManager().GetShader(prim.shaderName).get();

		if ((prim.cacheShader->IsAlphaTested() || prim.cacheShader->IsTranslucent()) && opaque)
			continue;

		prim.cacheShader->Bind(0);
		glDrawElements(prim.type, static_cast<GLsizei>(prim.indicesCount), _indexBuffer->GetType(), reinterpret_cast<void*>(prim.indicesOffset * 4));
	}

	_vertexBinding->Unbind();
}
} // namespace Donut
