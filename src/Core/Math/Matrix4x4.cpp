// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "Matrix4x4.h"

#include "Core/Math/Math.h"
#include "Core/Math/Matrix3x3.h"
#include "Core/Math/Quaternion.h"

namespace Donut
{

const Matrix4x4 Matrix4x4::Zero(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
const Matrix4x4 Matrix4x4::Identity(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                                    1.0f);

Quaternion Matrix4x4::ToQuat() const
{
	return Quaternion(*this);
}

/**
 * Makes a translation matrix from a Vector3.
 */
Matrix4x4 Matrix4x4::MakeTranslate(const Vector3& v)
{
	Matrix4x4 m;

	m.M[0][0] = 1.0f;
	m.M[0][1] = 0.0f;
	m.M[0][2] = 0.0f;
	m.M[0][3] = 0.0f;
	m.M[1][0] = 0.0f;
	m.M[1][1] = 1.0f;
	m.M[1][2] = 0.0f;
	m.M[1][3] = 0.0f;
	m.M[2][0] = 0.0f;
	m.M[2][1] = 0.0f;
	m.M[2][2] = 1.0f;
	m.M[2][3] = 0.0f;
	m.M[3][0] = v.X;
	m.M[3][1] = v.Y;
	m.M[3][2] = v.Z;
	m.M[3][3] = 1.0f;

	return m;
}

Matrix4x4 Matrix4x4::MakeOrtho(float left, float right, float bottom, float top)
{
	Matrix4x4 m(2.0f / (right - left), 0.0f, 0.0f, 0.0f, 0.0f, 2.0f / (top - bottom), 0.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f,
	            -(right + left) / (right - left), -(top + bottom) / (top - bottom), 0.0f, 1.0f);

	return m;
}

} // namespace Donut
