// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "Quaternion.h"

#include "Core/Math/Math.h"
#include "Core/Math/Matrix3x3.h"
#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Vector3.h"

#include <fmt/format.h>

namespace Donut
{

const Quaternion Quaternion::Zero(0.0f, 0.0f, 0.0f, 0.0f);
const Quaternion Quaternion::Identity(0.0f, 0.0f, 0.0f, 1.0f);

Quaternion::Quaternion(const Matrix3x3& rot)
{
	FromRotationMatrix(rot);
}

Quaternion::Quaternion(const Matrix4x4& rot)
{
	FromRotationMatrix(rot);
}

Quaternion::Quaternion(Vector3 axis, float angle)
{
	// Check whether the angle is 0, in that case we do not need to calculate sin/cos stuff...
	if (Math::Abs(angle) < Math::Epsilon)
	{
		X = 0.0f;
		Y = 0.0f;
		Z = 0.0f;
		W = 1.0f;
		return;
	}

	float sinAngle = Math::Sin(angle * 0.5f);

	X = axis.X * sinAngle;
	Y = axis.Y * sinAngle;
	Z = axis.Z * sinAngle;
	W = Math::Cos(angle * 0.5f);
}

void Quaternion::ToRotationMatrix(Matrix3x3& m) const
{
	float qxx = X * X, qyy = Y * Y, qzz = Z * Z;
	float qxz = X * Z, qxy = X * Y, qyz = Y * Z;
	float qwx = W * X, qwy = W * Y, qwz = W * Z;

	m.M[0][0] = 1.0f - 2.0f * (qyy + qzz);
	m.M[0][1] = 2.0f * (qxy + qwz);
	m.M[0][2] = 2.0f * (qxz - qwy);

	m.M[1][0] = 2.0f * (qxy - qwz);
	m.M[1][1] = 1.0f - 2.0f * (qxx + qzz);
	m.M[1][2] = 2.0f * (qyz + qwx);

	m.M[2][0] = 2.0f * (qxz + qwy);
	m.M[2][1] = 2.0f * (qyz - qwx);
	m.M[2][2] = 1.0f - 2.0f * (qxx + qyy);
}

void Quaternion::ToRotationMatrix(Matrix4x4& m) const
{
	const float x2 = X + X;
	const float y2 = Y + Y;
	const float z2 = Z + Z;
	const float xx = X * x2;
	const float xy = X * y2;
	const float xz = X * z2;
	const float yy = Y * y2;
	const float yz = Y * z2;
	const float zz = Z * z2;
	const float wx = W * x2;
	const float wy = W * y2;
	const float wz = W * z2;

	m.M[0][0] = 1.0f - (yy + zz);
	m.M[1][0] = xy - wz;
	m.M[2][0] = xz + wy;
	m.M[3][0] = 0.0f;
	m.M[0][1] = xy + wz;
	m.M[1][1] = 1.0f - (xx + zz);
	m.M[2][1] = yz - wx;
	m.M[3][1] = 0.0f;
	m.M[0][2] = xz - wy;
	m.M[1][2] = yz + wx;
	m.M[2][2] = 1.0f - (xx + yy);
	m.M[3][2] = 0.0f;
	m.M[0][3] = 0.0f;
	m.M[1][3] = 0.0f;
	m.M[2][3] = 0.0f;
	m.M[3][3] = 1.0f;
}

Quaternion& Quaternion::FromRotationMatrix(const Matrix3x3& m)
{
	return *this; // TODO
}

Quaternion& Quaternion::FromRotationMatrix(const Matrix4x4& m)
{
	// todo: IF NULL RETURN IDENTITY QUAT
	// todo: MAKE SURE ROTATION PART IS UNIT LENGTH

	float s;
	const float tr = m.M[0][0] + m.M[1][1] + m.M[2][2];

	if (tr > 0.0f)
	{
		float InvS = Math::InvSqrt(tr + 1.f);
		this->W = 0.5f * (1.f / InvS);
		s = 0.5f * InvS;

		this->X = (m.M[1][2] - m.M[2][1]) * s;
		this->Y = (m.M[2][0] - m.M[0][2]) * s;
		this->Z = (m.M[0][1] - m.M[1][0]) * s;
	}
	else
	{
		// diagonal is negative
		int32_t i = 0;

		if (m.M[1][1] > m.M[0][0])
			i = 1;

		if (m.M[2][2] > m.M[i][i])
			i = 2;

		static const int32_t nxt[3] = {1, 2, 0};
		const int32_t j = nxt[i];
		const int32_t k = nxt[j];

		s = m.M[i][i] - m.M[j][j] - m.M[k][k] + 1.0f;

		float InvS = Math::InvSqrt(s);

		float qt[4];
		qt[i] = 0.5f * (1.f / InvS);

		s = 0.5f * InvS;

		qt[3] = (m.M[j][k] - m.M[k][j]) * s;
		qt[j] = (m.M[i][j] + m.M[j][i]) * s;
		qt[k] = (m.M[i][k] + m.M[k][i]) * s;

		this->X = qt[0];
		this->Y = qt[1];
		this->Z = qt[2];
		this->W = qt[3];
	}

	return *this;
}

/**
 *  @brief
 *    Returns the x (left) axis
 */
Vector3 Quaternion::GetXAxis() const
{
	float ty = 2.0f * Y;
	float tz = 2.0f * Z;
	float twy = ty * W;
	float twz = tz * W;
	float txy = ty * X;
	float txz = tz * X;
	float tyy = ty * Y;
	float tzz = tz * Z;

	return Vector3(1.0f - (ty + tz), txy + twz, txz - twy);
}

/**
 *  @brief
 *    Returns the y (up) axis
 */
Vector3 Quaternion::GetYAxis() const
{
	float tx = 2.0f * X;
	float ty = 2.0f * Y;
	float tz = 2.0f * Z;
	float twx = tx * W;
	float twz = tz * W;
	float txx = tx * X;
	float txy = ty * X;
	float tyz = tz * Y;
	float tzz = tz * Z;

	return Vector3(txy - twz, 1.0f - (txx + tzz), tyz + twx);
}

/**
 *  @brief
 *    Returns the z (forward) axis
 */
Vector3 Quaternion::GetZAxis() const
{
	float tx = 2.0f * X;
	float ty = 2.0f * Y;
	float tz = 2.0f * Z;
	float twx = tx * W;
	float twy = ty * W;
	float txx = tx * X;
	float txz = tz * X;
	float tyy = ty * Y;
	float tyz = tz * Y;
	return Vector3(txz + twy, tyz - twx, 1.0f - (txx + tyy));
}

Quaternion Quaternion::MakeFromEuler(const Vector3& euler)
{
	return Quaternion(0, 0, 0, 1);
}

std::string Quaternion::ToString() const
{
	return fmt::format("X={:3.3f} Y={:3.3f} Z={:3.3f} W={:3.3f}", X, Y, Z, W);
}

} // namespace Donut
