// Copyright 2019 the donut authors. See AUTHORS.md

#include <Skeleton.h>

namespace Donut
{
Skeleton::Skeleton(const P3D::Skeleton& skeleton):
    _name(skeleton.GetName())
{
	assert(skeleton.GetVersion() == 0);

	_joints.reserve(skeleton.GetNumJoints());
	for (const auto& joint : skeleton.GetJoints())
		_joints.emplace_back(joint->GetName(), joint->GetParent(), joint->GetRestPose());

	// calculate global transforms through the hierarchy
	for (auto i = 0; i < _joints.size(); i++)
		_joints[i].restGlobalInverse = _joints[_joints[i].parent].restGlobalInverse * _joints[i].rest;

	// inverse those globals afterwards
	for (auto i = 0; i < _joints.size(); i++)
		_joints[i].restGlobalInverse = glm::inverse(_joints[i].restGlobalInverse);
}

void Skeleton::ResetPose()
{
	for (auto& joint : _joints)
		joint.pose = glm::mat4(1.0f);

	updateJoints();
}

void Skeleton::UpdatePose(SkinAnimation& animation, double time)
{
	time *= animation.GetFrameRate();

	_joints[0].pose = glm::mat4(1.0f);

	for (auto i = 0; i < _joints.size(); i++)
		_joints[i].pose = _joints[_joints[i].parent].pose * animation.Evaluate(i, static_cast<float>(time));

	updateJoints();
}

void Skeleton::updateJoints()
{
	for (auto i = 0; i < _joints.size(); i++)
	{
		Joint& j      = _joints[i];
		j.finalGlobal = j.pose * j.restGlobalInverse;
	}
}

} // namespace Donut
