#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/PrimGroup.h>
#include <memory>
#include <string>
#include <vector>

namespace Donut::P3D
{

class Mesh
{
  public:
	Mesh(const std::string& name, std::vector <std::unique_ptr<PrimGroup>> primGroups):
	    _name(name), _primGroups(std::move(primGroups)) {}

	static std::unique_ptr<Mesh> Load(const P3DChunk&);

	const std::string& GetName() const { return _name; }
	const std::vector<std::unique_ptr<PrimGroup>>& GetPrimGroups() const { return _primGroups; }

  private:
	std::string _name;
	std::vector<std::unique_ptr<PrimGroup>> _primGroups;
};

} // namespace Donut::P3D
