// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Matrix4x4.h"

#include <string>
#include <unordered_map>
#include <vector>

namespace Donut
{

namespace P3D
{
class Skeleton;
}

class SkinAnimation;

// Represents a Skeleton
class Skeleton
{
	struct Joint
	{
		std::string name;
		int parent;
		Matrix4x4 rest;
		Matrix4x4 restGlobalInverse;
		Matrix4x4 pose;
		Matrix4x4 finalGlobal;

		Joint(std::string pName, int pParent, Matrix4x4 pRest)
		    : name(std::move(pName)), parent(pParent), rest(pRest), restGlobalInverse(Matrix4x4::Identity),
		      pose(Matrix4x4::Identity), finalGlobal(Matrix4x4::Identity)
		{
		}
	};

public:
	Skeleton(const P3D::Skeleton& skeleton);

	void ResetPose();
	void UpdatePose(SkinAnimation& animation, double time);

	const std::string& GetName() { return _name; }
	const std::vector<Joint>& GetJoints() const { return _joints; }
	const Joint& GetJoint(const std::string& name) const { return _joints.at(_jointNameIndexMap.at(name)); }
	const Joint& GetJoint(uint32_t index) const { return _joints.at(index); }

private:
	void updateJoints();

	std::string _name;
	std::vector<Joint> _joints;
	std::unordered_map<std::string, uint32_t> _jointNameIndexMap;
};
} // namespace Donut
