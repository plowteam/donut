#include <StaticModel.h>
#include <glm/gtx/transform.hpp>
#include <iostream>
#include <vector>
#include "SkinModel.h"

namespace Donut
{

StaticModel::StaticModel(std::unique_ptr<P3D::StaticEntity> entity):
    _name(entity->GetName()), _staticEntity(std::move(entity))
{
	std::vector<Vertex> allVerts;
	std::vector<uint32_t> allIndices;

	size_t vertOffset = 0;
	for (auto const& prim : _staticEntity->GetMesh().GetPrimGroups())
	{
		auto verts         = prim->GetVerticies();
		auto uvs           = prim->GetUV();
		//auto normals       = prim->GetNormals();
		auto indices       = prim->GetIndices();

		for (uint32_t i = 0; i < verts.size(); i++)
		{
			allVerts.push_back(Vertex {
			    verts[i],
			    glm::vec2(uvs[i].x, 1.0f - uvs[i].y),
			});
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
	size_t ptr = 0;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)ptr);
	ptr += sizeof(glm::vec3);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)ptr);
	ptr += sizeof(glm::vec2);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
}

void StaticModel::Draw(const GL::ShaderProgram& shader, const ResourceManager&)
{
	glBindVertexArray(_vertexArrayObject);

	size_t idxOffset = 0;
	for (auto const& prim : _staticEntity->GetMesh().GetPrimGroups())
	{
		const auto indicesSize = (GLsizei)prim->GetIndices().size();

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

		glDrawElements(mode, indicesSize, _indexBuffer->GetType(), (void*)(idxOffset * 4));
		idxOffset += indicesSize;
	}

	glBindVertexArray(0);
}
} // namespace Donut
