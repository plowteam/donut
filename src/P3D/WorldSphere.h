#pragma once

#include <P3D/Mesh.h>
#include <P3D/P3DChunk.h>
#include <memory>
#include <string>

namespace Donut::P3D
{

// StaticEntity only used in world files it seems
class WorldSphere
{
  public:
	WorldSphere(const std::string& name, std::vector<std::unique_ptr<Mesh>> meshes):
	    _name(name), _meshes(std::move(meshes)) {}

	static std::unique_ptr<WorldSphere> Load(const P3DChunk&);

	const std::string& GetName() const { return _name; }
	const std::vector<std::unique_ptr<Mesh>>& GetMeshes() const { return _meshes; }

  private:
	std::string _name;
	std::vector<std::unique_ptr<Mesh>> _meshes;
};

} // namespace Donut::P3D
