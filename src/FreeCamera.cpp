// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "FreeCamera.h"

#include "Core/Math/Math.h"

namespace Donut
{
FreeCamera::FreeCamera()
    : _position(Vector3::Zero), _orientation(Quaternion::Identity), _fov(70.0f), _aspectRatio(1.0f), _znear(1.0f), _zfar(10000.0f),
      _projectionMatrix(Matrix4x4::Zero), _viewMatrix(Matrix4x4::Identity)
{
	updateProjectionMatrix();
	updateViewMatrix();
}

void FreeCamera::SetPosition(const Vector3& position)
{
	_position = position;
	updateViewMatrix();
}

void FreeCamera::SetQuaternion(const Quaternion& orientation)
{
	_orientation = orientation;
	updateViewMatrix();
}

void FreeCamera::Move(const Vector3& force, float dt)
{
	if (force.LengthSquared() == 0)
		return;

	_position += _orientation.Inverse() * force * dt;
	updateViewMatrix();
}

void FreeCamera::LookDelta(float x, float y)
{
	Quaternion quatPitch(Vector3::Right, Math::DegreesToRadians(-y));
	Quaternion quatYaw(Vector3::Up, Math::DegreesToRadians(-x));
	_orientation = quatPitch * _orientation * quatYaw;

	updateViewMatrix();
}

void FreeCamera::updateProjectionMatrix()
{
	float tanHalfFovY = Math::Tan(Math::DegreesToRadians(_fov) / 2.0f);

	_projectionMatrix = Matrix4x4::Zero;
	_projectionMatrix[0][0] = 1.0f / (_aspectRatio * tanHalfFovY);
	_projectionMatrix[1][1] = 1.0f / (tanHalfFovY);
	_projectionMatrix[2][2] = (_zfar + _znear) / (_zfar - _znear);
	_projectionMatrix[2][3] = 1.0f;
	_projectionMatrix[3][2] = -(2.0f * _zfar * _znear) / (_zfar - _znear);
}

void FreeCamera::updateViewMatrix()
{
	Matrix4x4 rotM(_orientation);
	Matrix4x4 transM = Matrix4x4::MakeTranslate(-_position);
	_viewMatrix = rotM * transM;
}

void FreeCamera::SetFOV(float fov)
{
	_fov = fov;
	updateProjectionMatrix();
}

void FreeCamera::SetZNear(float znear)
{
	_znear = znear;
	updateProjectionMatrix();
}

void FreeCamera::SetZFar(float zfar)
{
	_zfar = zfar;
	updateProjectionMatrix();
}

void FreeCamera::SetAspectRatio(float aspect)
{
	_aspectRatio = aspect;
	updateProjectionMatrix();
}

} // namespace Donut
