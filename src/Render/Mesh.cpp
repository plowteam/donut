#include <Render/Mesh.h>
#include <Render/SkinModel.h>
#include <vector>

namespace Donut
{

static glm::vec4 ConvertColor(uint32_t v)
{	
	return glm::vec4(((v >> 16) & 255) / 255.0f,
					 ((v >> 8) & 255) / 255.0f,
					 ((v & 255)) / 255.0f,
					 ((v >> 24) & 255) / 255.0f);
}

Mesh::Mesh(const P3D::Mesh& mesh):
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

	glGenVertexArrays(1, &_vertexArrayObject);
	glBindVertexArray(_vertexArrayObject);

	_vertexBuffer =
	    std::make_unique<GL::VertexBuffer>(allVerts.data(), allVerts.size(), sizeof(Vertex));
	_indexBuffer =
	    std::make_unique<GL::IndexBuffer>(allIndices.data(), allIndices.size(), GL_UNSIGNED_INT);

	std::size_t ptr = 0;
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(ptr)); // pos
	ptr += sizeof(glm::vec3);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(ptr)); // uv
	ptr += sizeof(glm::vec2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<GLvoid*>(ptr)); // color
	ptr += sizeof(glm::vec4);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
}

void Mesh::Draw(const ResourceManager& rm)
{
	glBindVertexArray(_vertexArrayObject);

	for (auto const& prim : _primGroups)
	{
		rm.GetShaderTexture(prim.shaderName).Bind(0);
		glDrawElements(prim.type, (GLsizei)prim.indicesCount, _indexBuffer->GetType(), reinterpret_cast<void*>(prim.indicesOffset * 4));
	}

	glBindVertexArray(0);
}
} // namespace Donut
