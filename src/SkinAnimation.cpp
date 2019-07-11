#include <SkinAnimation.h>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>

namespace Donut
{
	glm::mat4 SkinAnimation::Evaluate(size_t trackIndex, float time)
	{
		const auto& track = _tracks[trackIndex];
		return track->Evaluate(time);
	}

	glm::mat4 SkinAnimation::Track::Evaluate(float time)
	{
		glm::mat4 rot = glm::toMat4(_rotationKeys[0].GetValue());
		glm::mat4 trans = glm::translate(glm::mat4(1.0f), _translationKeys[0].GetValue());
		glm::mat4 final = trans * rot;

		return final;
	}

} // namespace Donut
