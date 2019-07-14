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

	void Draw(const GL::ShaderProgram&, const ResourceManager&) const;
  private:
	std::string _name;
	std::unique_ptr<Mesh> _mesh;
};

} // namespace Donut
