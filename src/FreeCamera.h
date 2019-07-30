#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

namespace Donut
{
class FreeCamera
{
  public:
	FreeCamera();

	const glm::vec3& GetPosition() const { return Position; }
	const glm::mat4 GetViewMatrix() const { return ViewMatrix; }

	void MoveTo(glm::vec3 position);
	void Move(glm::vec3 force, float dt);
	void LookDelta(float x, float y);

  private:
	void UpdateViewMatrix();
	void UpdateRotationQuat();

	float Pitch;
	float Yaw;

	glm::vec3 Position;
	glm::quat RotationQuat;
	glm::mat4 ViewMatrix;
};
} // namespace Donut
