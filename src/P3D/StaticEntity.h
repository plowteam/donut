#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/Mesh.h>
#include <memory>
#include <string>

namespace Donut::P3D
{

// StaticEntity only used in world files it seems
class StaticEntity
{
  public:
	StaticEntity(const std::string& name, std::unique_ptr<Mesh> mesh):
	    _name(name), _mesh(std::move(mesh)) {}

	static std::unique_ptr<StaticEntity> Load(const P3DChunk&);

	const std::string& GetName() const { return _name; }
	const Mesh& GetMesh() const { return *_mesh; }

  private:
	std::string _name;
	std::unique_ptr<Mesh> _mesh;
};

} // namespace Donut::P3D
