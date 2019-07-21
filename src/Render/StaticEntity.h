#pragma once

#include <Render/Mesh.h>
#include <P3D/StaticEntity.h>
#include <ResourceManager.h>
#include <string>

namespace Donut
{

// StaticEntity is just a Mesh wrapper, maybe replace it?
class StaticEntity
{
  public:
	  StaticEntity(const P3D::StaticEntity&);
	  StaticEntity(const std::string& name, const P3D::Mesh&, const glm::mat4&);

	void Draw(const GL::ShaderProgram&, const ResourceManager&) const;

	const glm::mat4& GetTransform() const { return _transform; }
  private:
	std::string _name;
	std::unique_ptr<Mesh> _mesh;
	glm::mat4 _transform;
};

} // namespace Donut
