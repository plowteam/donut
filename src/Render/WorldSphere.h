#pragma once

#include <Render/Mesh.h>
#include <P3D/p3d.generated.h>
#include <ResourceManager.h>
#include <string>
#include <vector>

namespace Donut
{

class WorldSphere
{
  public:
	WorldSphere(const P3D::WorldSphere&);

	void Draw(bool opaque) const;
  private:
	std::string _name;
	std::vector<std::unique_ptr<Mesh>> _meshes;
};

} // namespace Donut
