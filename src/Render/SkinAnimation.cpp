// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "SkinAnimation.h"

namespace Donut
{
Matrix4x4 SkinAnimation::Evaluate(size_t trackIndex, float time)
{
	const auto& track = _tracks[trackIndex];
	return track->Evaluate(time);
}

Matrix4x4 SkinAnimation::Track::Evaluate(float time)
{
	// Matrix4x4 rot   = glm::toMat4(_rotationKeys.Evalulate(time, Quaternion(1, 0, 0, 0)));
	// Matrix4x4 trans = glm::translate(Matrix(1.0f), _translationKeys.Evalulate(time, Vector3(1.0f)));
	// Matrix4x4 final = trans * rot;
	// return final;
	return Matrix4x4::Identity;
}

} // namespace Donut
