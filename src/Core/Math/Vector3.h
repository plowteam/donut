// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Math.h"

#include <string>

namespace Donut
{

/**
 * Represents a vector in 3D space composed of three single precision floating point values (X, Y, Z).
 */
struct Vector3
{
	union
	{
		struct
		{
			float X;
			float Y;
			float Z;
		};
	};

	FORCEINLINE Vector3() noexcept;
	FORCEINLINE constexpr Vector3(const float x, const float y, const float z) noexcept;
	FORCEINLINE constexpr Vector3(const float scalar) noexcept;

	FORCEINLINE float Length() const noexcept;
	FORCEINLINE float LengthSquared() const noexcept;

	FORCEINLINE void Normalize() noexcept;
	FORCEINLINE Vector3 Normalized() const noexcept;
	FORCEINLINE bool IsNormalized() const noexcept;

	FORCEINLINE Vector3 Cross(const Vector3& a) noexcept;
	FORCEINLINE float Dot(const Vector3& a) noexcept;
	FORCEINLINE float DistanceTo(const Vector3& a) noexcept;
	FORCEINLINE float DistanceToSquared(const Vector3& a) noexcept;

	FORCEINLINE float* Data() noexcept;
	FORCEINLINE constexpr const float* Data() const noexcept;

	std::string ToString() const;

	/* Operators */
	FORCEINLINE Vector3 operator+=(const Vector3& a);
	FORCEINLINE Vector3 operator+(const Vector3& a) const;
	FORCEINLINE Vector3 operator-=(const Vector3& a);
	FORCEINLINE Vector3 operator-(const Vector3& a) const;
	FORCEINLINE Vector3 operator*=(const Vector3& a);
	FORCEINLINE Vector3 operator*(const Vector3& a) const;
	FORCEINLINE Vector3 operator/=(const Vector3& a);
	FORCEINLINE Vector3 operator/(const Vector3& a) const;
	FORCEINLINE Vector3 operator*=(float scalar);
	FORCEINLINE Vector3 operator*(float scalar) const;
	FORCEINLINE Vector3 operator/=(float scalar);
	FORCEINLINE Vector3 operator/(float scalar) const;
	FORCEINLINE Vector3 operator-() const;
	FORCEINLINE bool operator==(const Vector3& a) const;
	FORCEINLINE bool operator!=(const Vector3& a) const;
	FORCEINLINE float& operator[](std::size_t i);
	FORCEINLINE constexpr float operator[](std::size_t i) const;

	/** Zero vector (0, 0, 0) */
	static const Vector3 Zero;

	/** One vector (1, 1, 1) */
	static const Vector3 One;

	/** Up vector (0, 1, 0) */
	static const Vector3 Up;

	/** Down vector (0, -1, 0) */
	static const Vector3 Down;

	/** Forward vector (0, 0, 1) */
	static const Vector3 Forward;

	/** Backward vector (0, 0, -1) */
	static const Vector3 Backward;

	/** Right vector (1, 0, 0) */
	static const Vector3 Right;

	/** Left vector (-1, 0, 0) */
	static const Vector3 Left;
};

//
// Inline implementations of Vector3
//

// deliberately avoid initialization
#pragma warning(suppress : 26495)
/**
 * Default constructor (no initalization).
 */
FORCEINLINE Vector3::Vector3() noexcept {}

/**
 * Constructor initalizing X, Y, Z to individual given values.
 *
 * @param x X value.
 * @param y Y value.
 * @param z Z value.
 */
FORCEINLINE constexpr Vector3::Vector3(const float x, const float y, const float z) noexcept: X(x), Y(y), Z(z) {}

/**
 * Constructor initalizing X, Y, Z to a single float value.
 *
 * @param scalar Value to set X, Y, Z to.
 */
FORCEINLINE constexpr Vector3::Vector3(const float scaler) noexcept: X(scaler), Y(scaler), Z(scaler) {}

/**
 * Get the length of this vector.
 *
 * @return The length of this vector.
 */
FORCEINLINE float Vector3::Length() const noexcept
{
	return Math::Sqrt(X * X + Y * Y + Z * Z);
}

/**
 * Get the squared length of this vector.
 *
 * @return The squared length of this vector.
 */
FORCEINLINE float Vector3::LengthSquared() const noexcept
{
	return X * X + Y * Y + Z * Z;
}

/**
 * Normalizes this vector in place.
 */
FORCEINLINE void Vector3::Normalize() noexcept
{
	const float squareSum = X * X + Y * Y + Z * Z;

	if (squareSum == 0.0f)
	{
		X = Y = Z = 0;
		return;
	}

	const float scale = Math::InvSqrt(squareSum);
	X *= scale;
	Y *= scale;
	Z *= scale;
}

/**
 * Gets a normalized copy of the vector.
 *
 * @return Normalized copy of this vector.
 */
FORCEINLINE Vector3 Vector3::Normalized() const noexcept
{
	Vector3 v = *this;
	v.Normalize();
	return v;
}

/**
 * Determine whether this vector is normalized.
 *
 * @return true if normalized, otherwise false.
 */
FORCEINLINE bool Vector3::IsNormalized() const noexcept
{
	const float squareSum = X * X + Y * Y + Z * Z;

	return squareSum == 1.0f;
}

FORCEINLINE Vector3 Vector3::Cross(const Vector3& a) noexcept
{
	return Vector3((Y * a.Z) - (Z * a.Y), (Z * a.X) - (X * a.Z), (X * a.Y) - (Y * a.X));
}

FORCEINLINE float Vector3::Dot(const Vector3& a) noexcept
{
	return X * a.X + Y * a.Y + Z * a.Z;
}

FORCEINLINE float Vector3::DistanceTo(const Vector3& a) noexcept
{
	return Math::Sqrt(DistanceToSquared(a));
}

FORCEINLINE float Vector3::DistanceToSquared(const Vector3& a) noexcept
{
	return Math::Square(a.X - X) + Math::Square(a.Y - Y) + Math::Square(a.Z - Z);
}

FORCEINLINE float* Vector3::Data() noexcept
{
	return &X;
}

FORCEINLINE constexpr const float* Vector3::Data() const noexcept
{
	return &X;
}

FORCEINLINE Vector3 Vector3::operator+(const Vector3& a) const
{
	return Vector3(X + a.X, Y + a.Y, Z + a.Z);
}

FORCEINLINE Vector3 Vector3::operator+=(const Vector3& a)
{
	X += a.X;
	Y += a.Y;
	Z += a.Z;
	return *this;
}

FORCEINLINE Vector3 Vector3::operator-=(const Vector3& a)
{
	X -= a.X;
	Y -= a.Y;
	Z -= a.Z;
	return *this;
}

FORCEINLINE Vector3 Vector3::operator-(const Vector3& a) const
{
	return Vector3(X - a.X, Y - a.Y, Z - a.Z);
}

FORCEINLINE Vector3 Vector3::operator*=(float scale)
{
	X *= scale;
	Y *= scale;
	Z *= scale;
	return *this;
}

FORCEINLINE Vector3 Vector3::operator*(const float scale) const
{
	return Vector3(X * scale, Y * scale, Z * scale);
}

FORCEINLINE Vector3 Vector3::operator*=(const Vector3& a)
{
	X *= a.X;
	Y *= a.Y;
	Z *= a.Z;
	return *this;
}

FORCEINLINE Vector3 Vector3::operator*(const Vector3& a) const
{
	return Vector3(X * a.X, Y * a.Y, Z * a.Z);
}

FORCEINLINE Vector3 Vector3::operator/=(float scalar)
{
	X /= scalar;
	Y /= scalar;
	Z /= scalar;
	return *this;
}

FORCEINLINE Vector3 Vector3::operator/(float scalar) const
{
	return Vector3(X / scalar, Y / scalar, Z / scalar);
}

FORCEINLINE Vector3 Vector3::operator/=(const Vector3& a)
{
	X /= a.X;
	Y /= a.Y;
	Z /= a.Z;
	return *this;
}

FORCEINLINE Vector3 Vector3::operator/(const Vector3& a) const
{
	return Vector3(X / a.X, Y / a.Y, Z / a.Z);
}

FORCEINLINE bool Vector3::operator==(const Vector3& a) const
{
	return X == a.X && Y == a.Y && Z == a.Z;
}

FORCEINLINE bool Vector3::operator!=(const Vector3& a) const
{
	return X != a.X || Y != a.Y || Z != a.Z;
}

FORCEINLINE Vector3 Vector3::operator-() const
{
	return Vector3(-X, -Y, -Z);
}

FORCEINLINE float& Vector3::operator[](std::size_t i)
{
	return (&X)[i];
}

FORCEINLINE constexpr float Vector3::operator[](std::size_t i) const
{
	return (&X)[i];
}

} // namespace Donut
