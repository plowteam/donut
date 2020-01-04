// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Math.h"
#include "Core/Math/Vector3.h"
#include "Core/Math/Vector4.h"
#include "Core/Platform.h"

namespace Donut
{

struct Matrix3x3;
struct Matrix4x4;

struct Quaternion
{
public:
	float X, Y, Z, W;

public:
	static const Quaternion Zero;
	static const Quaternion Identity;

public:
	// constructors
	FORCEINLINE Quaternion();
	FORCEINLINE Quaternion(float x, float y, float z, float w);
	Quaternion(Vector3 axis, float angle);
	Quaternion(const Matrix3x3& rot);
	Quaternion(const Matrix4x4& rot);

	// operators
	FORCEINLINE Quaternion operator+(const Quaternion& qQ) const;
	FORCEINLINE Quaternion& operator+=(const Quaternion& qQ);
	FORCEINLINE Quaternion operator-() const;
	FORCEINLINE Quaternion operator-(const Quaternion& qQ) const;
	FORCEINLINE Quaternion& operator-=(const Quaternion& qQ);
	FORCEINLINE Quaternion operator*(float f) const;
	FORCEINLINE Quaternion& operator*=(float f);
	FORCEINLINE Quaternion operator*(const Quaternion& qQ) const;
	FORCEINLINE Quaternion& operator*=(const Quaternion& qQ);
	FORCEINLINE Vector3 operator*(const Vector3& vV) const;
	FORCEINLINE Vector4 operator*(const Vector4& vV) const;
	FORCEINLINE Quaternion operator/(float f) const;
	FORCEINLINE Quaternion& operator/=(float f);
	FORCEINLINE Quaternion& operator=(const Quaternion& qQ);
	FORCEINLINE bool operator==(const Quaternion& qQ) const;
	FORCEINLINE bool operator!=(const Quaternion& qQ) const;

	Vector3 Euler() const;
	FORCEINLINE Quaternion Inverse() const;
	FORCEINLINE Quaternion Normal() const;

	Quaternion& FromRotationMatrix(const Matrix3x3& rot);
	Quaternion& FromRotationMatrix(const Matrix4x4& rot);
	void ToRotationMatrix(Matrix3x3& rot) const;
	void ToRotationMatrix(Matrix4x4& rot) const;

	Vector3 GetXAxis() const;
	Vector3 GetYAxis() const;
	Vector3 GetZAxis() const;

	static Quaternion MakeFromEuler(const Vector3& euler);

	std::string ToString() const;
};

#pragma warning(suppress : 26495) // don't initalize for speed
Quaternion::Quaternion() {}

Quaternion::Quaternion(float x, float y, float z, float w): X(x), Y(y), Z(z), W(w) {}

// operators
FORCEINLINE Quaternion Quaternion::operator+(const Quaternion& q) const
{
	return Quaternion(X + q.X, Y + q.Y, Z + q.Z, W + q.W);
}

FORCEINLINE Quaternion& Quaternion::operator+=(const Quaternion& qQ)
{
	X += qQ.X;
	Y += qQ.Y;
	Z += qQ.Z;
	W += qQ.W;

	return *this;
}

FORCEINLINE Quaternion Quaternion::operator-() const
{
	const float norm = X * X + Y * Y + Z * Z + W * W;
	if (norm == 0.0f)
		return Quaternion::Zero;

	const float invNorm = 1.0f / norm;
	return Quaternion(-X * invNorm, -Y * invNorm, -Z * invNorm, W * invNorm);
}

FORCEINLINE Quaternion Quaternion::operator-(const Quaternion& q) const
{
	return Quaternion(X - q.X, Y - q.Y, Z - q.Z, W - q.W);
}

FORCEINLINE Quaternion& Quaternion::operator-=(const Quaternion& q)
{
	X -= q.X;
	Y -= q.Y;
	Z -= q.Z;
	W -= q.W;

	return *this;
}

FORCEINLINE Quaternion Quaternion::operator*(float f) const
{
	return Quaternion(X * f, Y * f, Z * f, W * f);
}

FORCEINLINE Quaternion& Quaternion::operator*=(float f)
{
	X *= f;
	Y *= f;
	Z *= f;
	W *= f;

	return *this;
}

FORCEINLINE Quaternion Quaternion::operator*(const Quaternion& q) const
{
	return Quaternion(W * q.X + X * q.W + Y * q.Z - Z * q.Y, W * q.Y + Y * q.W + Z * q.X - X * q.Z,
	                  W * q.Z + Z * q.W + X * q.Y - Y * q.X, W * q.W - X * q.X - Y * q.Y - Z * q.Z);
}

FORCEINLINE Quaternion& Quaternion::operator*=(const Quaternion& q)
{
	const float qx = X, qy = Y, qz = Z, qw = W;
	X = qw * q.X + qx * q.W + qy * q.Z - qz * q.Y;
	Y = qw * q.Y + qy * q.W + qz * q.X - qx * q.Z;
	Z = qw * q.Z + qz * q.W + qx * q.Y - qy * q.X;
	W = qw * q.W - qx * q.X - qy * q.Y - qz * q.Z;

	return *this;
}

FORCEINLINE Vector3 Quaternion::operator*(const Vector3& v) const
{
	const float x2 = X * X;
	const float y2 = Y * Y;
	const float z2 = Z * Z;
	const float w2 = W * W;
	const float xa = X * v.X;
	const float yb = Y * v.Y;
	const float zc = Z * v.Z;
	return Vector3(v.X * (x2 - y2 - z2 + w2) + 2 * (W * (Y * v.Z - Z * v.Y) + X * (yb + zc)),
	               v.Y * (-x2 + y2 - z2 + w2) + 2 * (W * (Z * v.X - X * v.Z) + Y * (xa + zc)),
	               v.Z * (-x2 - y2 + z2 + w2) + 2 * (W * (X * v.Y - Y * v.X) + Z * (xa + yb)));
}

FORCEINLINE Vector4 Quaternion::operator*(const Vector4& v) const
{
	const float x2 = X * X;
	const float y2 = Y * Y;
	const float z2 = Z * Z;
	const float w2 = W * W;
	const float xa = X * v.X;
	const float yb = Y * v.Y;
	const float zc = Z * v.Z;
	return Vector4(v.X * (x2 - y2 - z2 + w2) + 2 * (W * (Y * v.Z - Z * v.Y) + X * (yb + zc)),
	               v.Y * (-x2 + y2 - z2 + w2) + 2 * (W * (Z * v.X - X * v.Z) + Y * (xa + zc)),
	               v.Z * (-x2 - y2 + z2 + w2) + 2 * (W * (X * v.Y - Y * v.X) + Z * (xa + yb)), 1.0f);
}

FORCEINLINE Quaternion Quaternion::operator/(float f) const
{
	return Quaternion(X / f, Y / f, Z / f, W / f);
}

FORCEINLINE Quaternion& Quaternion::operator/=(float f)
{
	X /= f;
	Y /= f;
	Z /= f;
	W /= f;

	return *this;
}

FORCEINLINE Quaternion& Quaternion::operator=(const Quaternion& q)
{
	X = q.X;
	Y = q.Y;
	Z = q.Z;
	W = q.W;

	return *this;
}

FORCEINLINE bool Quaternion::operator==(const Quaternion& q) const
{
	return (X == q.X && Y == q.Y && Z == q.Z && W == q.W);
}

FORCEINLINE bool Quaternion::operator!=(const Quaternion& q) const
{
	return (X != q.X || Y != q.Y || Z != q.Z || W != q.W);
}

FORCEINLINE Quaternion Quaternion::Inverse() const
{
	const float norm = X * X + Y * Y + Z * Z + W * W;

	if (norm == 0.0f)
		return Quaternion::Zero;

	const float invNorm = 1.0f / norm;
	return Quaternion(-X * invNorm, -Y * invNorm, -Z * invNorm, W * invNorm);
}

FORCEINLINE Quaternion Quaternion::Normal() const
{
	const float u = X * X + Y * Y + Z * Z + W * W;
	if (u == 0.0f)
		return Quaternion::Zero;

	const float factor = Math::InvSqrt(u);
	return Quaternion(X * factor, Y * factor, Z * factor, W * factor);
}

} // namespace Donut
