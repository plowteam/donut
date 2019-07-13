#pragma once

#include <GL/IndexBuffer.h>
#include <GL/ShaderProgram.h>
#include <GL/VertexBuffer.h>
#include <P3D/Mesh.h>
#include <ResourceManager.h>
#include <SkinAnimation.h>
#include <glm/glm.hpp>
#include <string>

namespace Donut
{

class Mesh
{
	struct PrimGroup
	{
		std::string shaderName;
		GLenum type;
		std::size_t indicesOffset;
		std::size_t indicesCount;
	};

	struct Vertex
	{
		glm::vec3 pos;
		glm::vec2 uv;
		glm::vec4 co0lor;
	};

  public:
	Mesh(const P3D::Mesh& mesh);
	void Draw(const GL::ShaderProgram&, const ResourceManager&);

  private:
	std::string _name;
	std::vector<PrimGroup> _primGroups;

	GLuint _vertexArrayObject;
	std::unique_ptr<GL::VertexBuffer> _vertexBuffer;
	std::unique_ptr<GL::IndexBuffer> _indexBuffer;

	glm::vec3 _boundingBoxMin;
	glm::vec3 _boundingBoxMax;
};

} // namespace Donut
