#pragma once

#include <P3D/P3DChunk.h>
#include <glm/mat4x4.hpp>

namespace Donut::P3D
{

class SkeletonJoint
{
  public:
	SkeletonJoint(const std::string& name, uint32_t parent, const glm::mat4 restPose):
	    _name(name), _parent(parent), _restPose(restPose) {}

	static std::unique_ptr<SkeletonJoint> Load(const P3DChunk&);

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
