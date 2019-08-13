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

	// create global inverses for each joint
	updateRestGlobals();

	_finalMatrices.resize(_joints.size(), glm::mat4(1.0f));
	_textureBuffer = std::make_unique<GL::TextureBuffer>();
	updateTextureBuffer();

	/*_boneBuffer = std::make_unique<GL::TextureBuffer>();

	for (uint32_t jointIndex = 0; jointIndex < joints.size(); ++jointIndex)
		_boneMatrices[jointIndex] = _boneMatrices[joints[jointIndex]->GetParent()] * joints[jointIndex]->GetRestPose();

	_boneBuffer->SetBuffer(_finalMatrices.data(), _finalMatrices.size() * sizeof(glm::mat4));*/
}

void Skeleton::ResetPose()
{
	for (auto& joint : _joints)
		joint.pose        = glm::mat4(1.0f);

	updateJoints();
	updateTextureBuffer();
}

// create rest global inverses, only needs to be run once
void Skeleton::updateRestGlobals()
{
	// calculate global transforms through the hierarchy
	for (auto i = 0; i < _joints.size(); i++)
		_joints[i].restGlobalInverse = _joints[_joints[i].parent].restGlobalInverse * _joints[i].rest;

	// inverse those globals afterwards
	for (auto i = 0; i < _joints.size(); i++)
		_joints[i].restGlobalInverse = glm::inverse(_joints[i].restGlobalInverse);
}

void Skeleton::updateJoints()
{
	for (auto i = 0; i < _joints.size(); i++)
	{
		Joint& j      = _joints[i];
		j.poseGlobal  = _joints[j.parent].poseGlobal * (j.rest * j.pose);
		j.finalGlobal = j.poseGlobal * j.restGlobalInverse;
	}
}

void Skeleton::updateTextureBuffer()
{
	for (auto i = 0; i < _joints.size(); i++)
	{
		auto const& joint = _joints[i];
		_finalMatrices[i] = joint.restGlobalInverse;
		// _finalMatrices[i] = joint.finalGlobal;
		// _finalMatrices[jointIndex] = _poseMatrices[jointIndex] * glm::inverse(_boneMatrices[jointIndex]);
	}

	_textureBuffer->SetBuffer(_finalMatrices.data(), _finalMatrices.size() * sizeof(glm::mat4));
}

} // namespace Donut
