#pragma once

#include <Render/OpenGL/IndexBuffer.h>
#include <Render/OpenGL/ShaderProgram.h>
#include <Render/OpenGL/VertexBuffer.h>
#include <Render/SkinAnimation.h>
#include <P3D/p3d.generated.h>
#include <ResourceManager.h>
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
		Shader* cacheShader;
	};

	struct Vertex
	{
		glm::vec3 pos;
		glm::vec2 uv;
		glm::vec4 co0lor;
	};

  public:
	Mesh(const P3D::Mesh& mesh);
	void Draw(bool opaque);

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
