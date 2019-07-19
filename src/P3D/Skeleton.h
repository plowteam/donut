#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/SkeletonJoint.h>

namespace Donut::P3D
{

class Skeleton
{
  public:
	Skeleton(const std::string& name, uint32_t version, uint32_t numJoints, std::vector<std::unique_ptr<SkeletonJoint>> primGroups):
	    _name(name), _joints(std::move(primGroups)) {}

	static std::unique_ptr<Skeleton> Load(const P3DChunk&);

	const std::vector<std::unique_ptr<SkeletonJoint>>& GetJoints() const { return _joints; }

  private:
	std::string _name;
	uint32_t _version;
	uint32_t _numJoints;
	std::vector<std::unique_ptr<SkeletonJoint>> _joints;
};

} // namespace Donut::P3D
