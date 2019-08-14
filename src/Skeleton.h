// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

#include <P3D/P3D.generated.h>
#include <Render/OpenGL/TextureBuffer.h>
#include <Render/SkinAnimation.h>
#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <string>
#include <unordered_map>
#include <vector>

namespace Donut
{

// Represents a Skeleton
class Skeleton
{
	struct Joint
	{
		std::string name;
		int parent;
		glm::mat4 rest;
		glm::mat4 restGlobalInverse;
		glm::mat4 pose;
		glm::mat4 finalGlobal;

		Joint(std::string pName, int pParent, glm::mat4 pRest):
		    name(std::move(pName)), parent(pParent), rest(pRest),
		    restGlobalInverse(glm::mat4(1.0f)), pose(glm::mat4(1.0f)), finalGlobal(glm::mat4(1.0f)) {}
	};

  public:
	Skeleton(const P3D::Skeleton& skeleton);

	void ResetPose();
	void UpdatePose(SkinAnimation& animation, double time);

	const std::string& GetName() { return _name; }
	const std::vector<Joint>& GetJoints() const { return _joints; }
  private:
	void updateJoints();

	std::string _name;
	std::vector<Joint> _joints;
};
} // namespace Donut
