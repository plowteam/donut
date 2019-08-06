// Copyright 2019 the donut authors. See AUTHORS.md

#include "SkinAnimation.h"
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>

namespace Donut
{
	glm::mat4 SkinAnimation::Evaluate(size_t trackIndex, float time)
	{
		const auto& track = _tracks[trackIndex];
		return track->Evaluate(time);
	}

	glm::vec3 SkinAnimation::EvaluateDirection(size_t trackIndex, float time)
	{
		const auto& track = _tracks[trackIndex];
		return track->EvaluateDirection(time);
	}

	glm::mat4 SkinAnimation::Track::Evaluate(float time)
	{
		glm::mat4 rot = glm::toMat4(_rotationKeys.Evalulate(time, glm::quat(1, 0, 0, 0)));
		glm::mat4 trans = glm::translate(glm::mat4(1.0f), _translationKeys.Evalulate(time, glm::vec3(1.0f)));
		glm::mat4 final = trans * rot;

		return final;
	}

	glm::vec3 SkinAnimation::Track::EvaluateDirection(float time)
	{
		return _directionKeys.Evalulate(time, glm::vec3(1.0f));
	}

} // namespace Donut
