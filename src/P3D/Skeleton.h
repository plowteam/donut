#pragma once

#include <P3D/SkeletonJoint.h>
#include <memory>
#include <string>
#include <vector>

namespace Donut::P3D
{

class Skeleton
{
  public:
	Skeleton(const std::string& name, uint32_t version, uint32_t numJoints, std::vector<std::unique_ptr<SkeletonJoint>> primGroups):
	    _name(name), _joints(std::move(primGroups)) {}

	std::vector<std::unique_ptr<SkeletonJoint>>& GetJoints() { return _joints; }

  private:
	std::string _name;
	uint32_t _version;
	uint32_t _numJoints;
	std::vector<std::unique_ptr<SkeletonJoint>> _joints;
};

} // namespace Donut::P3D
