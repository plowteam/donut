#pragma once

#include <memory>
#include <string>
#include <P3D/PrimGroup.h>

namespace Donut::P3D {

class PolySkin {
public:
	PolySkin(const std::string& name, const std::string& skeletonName, std::vector<std::unique_ptr<PrimGroup>> primGroups) :
		_name(name), _skeletonName(skeletonName), _primGroups(std::move(primGroups)) {}

	std::string& GetName() { return _name; }
	std::string& GetSkeletonName() { return _skeletonName; }
    std::vector<std::unique_ptr<PrimGroup>>& GetPrimGroups() { return _primGroups; }
private:
	std::string _name;
	std::string _skeletonName;
    std::vector<std::unique_ptr<PrimGroup>> _primGroups;
};

} // namespace Donut::P3D
