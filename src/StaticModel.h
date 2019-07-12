#pragma once

#include <GL/IndexBuffer.h>
#include <GL/ShaderProgram.h>
#include <GL/VertexBuffer.h>
#include <P3D/StaticEntity.h>
#include <GL/ShaderProgram.h>
#include <ResourceManager.h>
#include <SkinAnimation.h>
#include <glm/glm.hpp>
#include <string>

namespace Donut
{

class StaticModel
{
	struct Vertex
	{
		glm::vec3 pos;
		glm::vec2 uv;
	};

  public:
	StaticModel(std::unique_ptr<P3D::StaticEntity>);

	void Draw(const GL::ShaderProgram&, const ResourceManager&);
  private:
	std::string _name;
	std::unique_ptr<P3D::StaticEntity> _staticEntity;

	GLuint _vertexArrayObject;
	std::unique_ptr<GL::VertexBuffer> _vertexBuffer;
	std::unique_ptr<GL::IndexBuffer> _indexBuffer;
};

} // namespace Donut
