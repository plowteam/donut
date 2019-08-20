// Copyright 2019 the donut authors. See AUTHORS.md

#include "FreeCamera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

namespace Donut
{
FreeCamera::FreeCamera():
    Pitch(0.0f), Yaw(0.0f), Position(0.0f)
{
	UpdateRotationQuat();
	UpdateViewMatrix();
}

void FreeCamera::MoveTo(glm::vec3 position)
{
	Position = position;
	UpdateViewMatrix();
}

void FreeCamera::Move(glm::vec3 force, float dt)
{
	if (glm::length2(force) > 0.0f)
	{
		Position -= (glm::inverse(RotationQuat) * force) * dt;
		UpdateViewMatrix();
	}
}

void FreeCamera::LookDelta(float x, float y)
{
	Yaw += x;
	Yaw += glm::ceil(-Yaw / 360.0f) * 360.0f;
	Pitch = glm::clamp(Pitch + y, -90.0f, 90.0f);

	UpdateRotationQuat();
	UpdateViewMatrix();
}

void FreeCamera::UpdateViewMatrix()
{
	ViewMatrix = glm::toMat4(RotationQuat) * glm::translate(glm::mat4(1.0f), -Position);
}

void FreeCamera::UpdateRotationQuat()
{
	RotationQuat = glm::inverse(glm::quat(glm::vec3(glm::radians(Pitch), glm::radians(Yaw), 0.0f)));
}
} // namespace Donut
