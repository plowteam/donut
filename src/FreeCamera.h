// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Quaternion.h"
#include "Core/Math/Vector3.h"

namespace Donut
{
class FreeCamera
{
public:
	FreeCamera();

	void SetPosition(const Vector3& position);
	const Vector3& GetPosition() const { return _position; }

	void SetQuaternion(const Quaternion& orientation);
	const Quaternion& GetOrientation() const { return _orientation; }

	void Move(const Vector3& force, float dt);
	void LookDelta(float x, float y);

	const Matrix4x4& GetViewMatrix() const { return _viewMatrix; }
	const Matrix4x4& GetProjectionMatrix() const { return _projectionMatrix; };

	float GetFOV() const { return _fov; }
	float GetZNear() const { return _znear; }
	float GetZFar() const { return _zfar; }
	float GetAspectRatio() const { return _aspectRatio; }

	void SetFOV(float fov);
	void SetZNear(float znear);
	void SetZFar(float zfar);
	void SetAspectRatio(float aspect);

private:
	void updateViewMatrix();
	void updateProjectionMatrix();

	Vector3 _position;
	Quaternion _orientation;

	Matrix4x4 _projectionMatrix;
	Matrix4x4 _viewMatrix;

	float _fov;
	float _aspectRatio;
	float _zfar;
	float _znear;
};
} // namespace Donut
