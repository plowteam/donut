#pragma once

#include <glm/mat4x4.hpp>
#include <memory>
#include <string>

namespace Donut::P3D
{

class SkeletonJoint
{
  public:
	SkeletonJoint(const std::string& name, uint32_t parent, const glm::mat4 restPose):
	    _name(name), _parent(parent), _restPose(restPose) {}

	const std::string& GetName() { return _name; }
	uint32_t GetParent() { return _parent; }
	const glm::mat4& GetRestPose() { return _restPose; }

  private:
	std::string _name;
	uint32_t _parent;
	int32_t _dof;
	int32_t _freeAxis;
	int32_t _primaryAxis;
	int32_t _secondaryAxis;
	int32_t _twistAxis;
	glm::mat4 _restPose;
};

} // namespace Donut::P3D
