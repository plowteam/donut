// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include "Core/Math/Vector3.h"

#include <cstdint>
#include <string>

namespace Donut
{

class Camera
{
public:
	// getters/setters (could be automatically generated)

	void SetFOV(float fov);
	void SetAspectRatio(float aspect_ratio);
	void SetNearClip(float near_clip);
	void SetFarClip(float far_clip);
	void SetPosition(const Vector3& position);
	void SetDirection(const Vector3& direction);
	void SetUpVector(const Vector3& up_vector);

protected:
	// std::string _name;
	// uint32_t _version;
	float _fov;
	float _aspectRatio;
	float _nearClip;
	float _farClip;
	Vector3 _position;
	Vector3 _look;
	Vector3 _up;

	friend class CameraLoader;
};

} // namespace Donut
