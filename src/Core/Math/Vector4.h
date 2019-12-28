// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Math.h"

#include <string>

namespace Donut
{

/**
 * Represents a vector in 4D space composed of four single precision floating point values (X, Y, Z, W).
 */
struct Vector4
{
	union
	{
		struct
		{
			float X;
			float Y;
			float Z;
			float W;
		};
	};

	FORCEINLINE Vector4() noexcept;
	FORCEINLINE constexpr Vector4(const float x, const float y, const float z, const float w) noexcept;
	FORCEINLINE constexpr Vector4(const float scalar) noexcept;

	FORCEINLINE float Length() const noexcept;
	FORCEINLINE float LengthSquared() const noexcept;

	FORCEINLINE void Normalize() noexcept;
	FORCEINLINE Vector4 Normalized() const noexcept;
	FORCEINLINE bool IsNormalized() const noexcept;

	FORCEINLINE Vector4 Cross(const Vector4& a) noexcept;
	FORCEINLINE float Dot(const Vector4& a) noexcept;
	FORCEINLINE float DistanceTo(const Vector4& a) noexcept;
	FORCEINLINE float DistanceToSquared(const Vector4& a) noexcept;

	FORCEINLINE float* Data() noexcept;
	FORCEINLINE constexpr const float* Data() const noexcept;

	std::string ToString() const;

	/* Operators */
	FORCEINLINE Vector4 operator+=(const Vector4& a);
	FORCEINLINE Vector4 operator+(const Vector4& a) const;
	FORCEINLINE Vector4 operator-=(const Vector4& a);
	FORCEINLINE Vector4 operator-(const Vector4& a) const;
	FORCEINLINE Vector4 operator*=(const Vector4& a);
	FORCEINLINE Vector4 operator*(const Vector4& a) const;
	FORCEINLINE Vector4 operator/=(const Vector4& a);
	FORCEINLINE Vector4 operator/(const Vector4& a) const;
	FORCEINLINE Vector4 operator*=(float scalar);
	FORCEINLINE Vector4 operator*(float scalar) const;
	FORCEINLINE Vector4 operator/=(float scalar);
	FORCEINLINE Vector4 operator/(float scalar) const;
	FORCEINLINE Vector4 operator-() const;
	FORCEINLINE bool operator==(const Vector4& a) const;
	FORCEINLINE bool operator!=(const Vector4& a) const;
	FORCEINLINE float& operator[](std::size_t i);
	FORCEINLINE constexpr float operator[](std::size_t i) const;

	/** Zero vector (0, 0, 0) */
	static const Vector4 Zero;

	/** One vector (1, 1, 1) */
	static const Vector4 One;
};

//
// Inline implementations of Vector4
//

// deliberately avoid initialization
#pragma warning(suppress : 26495)
/**
 * Default constructor (no initalization).
 */
FORCEINLINE Vector4::Vector4() noexcept {}

/**
 * Constructor initalizing X, Y, Z, W to individual given values.
 *
 * @param x X value.
 * @param y Y value.
 * @param z Z value.
 * @param w W value.
 */
FORCEINLINE constexpr Vector4::Vector4(const float x, const float y, const float z, const float w) noexcept
    : X(x), Y(y), Z(z), W(w)
{
}

/**
 * Constructor initalizing X, Y, Z, W to a single float value.
 *
 * @param scalar Value to set X, Y, Z, W to.
 */
FORCEINLINE constexpr Vector4::Vector4(const float scaler) noexcept: X(scaler), Y(scaler), Z(scaler), W(scaler) {}

/**
 * Get the length of this vector.
 *
 * @return The length of this vector.
 */
FORCEINLINE float Vector4::Length() const noexcept
{
	return Math::Sqrt(X * X + Y * Y + Z * Z + W * W);
}

/**
 * Get the squared length of this vector.
 *
 * @return The squared length of this vector.
 */
FORCEINLINE float Vector4::LengthSquared() const noexcept
{
	return X * X + Y * Y + Z * Z + W * W;
}

/**
 * Normalizes this vector in place.
 */
FORCEINLINE void Vector4::Normalize() noexcept
{
	const float squareSum = X * X + Y * Y + Z * Z + W * W;

	if (squareSum == 0.0f)
	{
		X = Y = Z = W = 0;
		return;
	}

	const float scale = Math::InvSqrt(squareSum);
	X *= scale;
	Y *= scale;
	Z *= scale;
	W *= scale;
}

/**
 * Gets a normalized copy of the vector.
 *
 * @return Normalized copy of this vector.
 */
FORCEINLINE Vector4 Vector4::Normalized() const noexcept
{
	Vector4 v = *this;
	v.Normalize();
	return v;
}

/**
 * Determine whether this vector is normalized.
 *
 * @return true if normalized, otherwise false.
 */
FORCEINLINE bool Vector4::IsNormalized() const noexcept
{
	const float squareSum = X * X + Y * Y + Z * Z + W * W;

	return squareSum == 1.0f;
}

FORCEINLINE float Vector4::Dot(const Vector4& a) noexcept
{
	return X * a.X + Y * a.Y + Z * a.Z + W * a.W;
}

FORCEINLINE float Vector4::DistanceTo(const Vector4& a) noexcept
{
	return Math::Sqrt(DistanceToSquared(a));
}

FORCEINLINE float Vector4::DistanceToSquared(const Vector4& a) noexcept
{
	return Math::Square(a.X - X) + Math::Square(a.Y - Y) + Math::Square(a.Z - Z) + Math::Square(a.W - W);
}

FORCEINLINE float* Vector4::Data() noexcept
{
	return &X;
}

FORCEINLINE constexpr const float* Vector4::Data() const noexcept
{
	return &X;
}

FORCEINLINE Vector4 Vector4::operator+(const Vector4& a) const
{
	return Vector4(X + a.X, Y + a.Y, Z + a.Z, W + a.W);
}

FORCEINLINE Vector4 Vector4::operator+=(const Vector4& a)
{
	X += a.X;
	Y += a.Y;
	Z += a.Z;
	W += a.W;
	return *this;
}

FORCEINLINE Vector4 Vector4::operator-=(const Vector4& a)
{
	X -= a.X;
	Y -= a.Y;
	Z -= a.Z;
	W -= a.W;
	return *this;
}

FORCEINLINE Vector4 Vector4::operator-(const Vector4& a) const
{
	return Vector4(X - a.X, Y - a.Y, Z - a.Z, W - a.W);
}

FORCEINLINE Vector4 Vector4::operator*=(float scale)
{
	X *= scale;
	Y *= scale;
	Z *= scale;
	W *= scale;
	return *this;
}

FORCEINLINE Vector4 Vector4::operator*(const float scale) const
{
	return Vector4(X * scale, Y * scale, Z * scale, W * scale);
}

FORCEINLINE Vector4 Vector4::operator*=(const Vector4& a)
{
	X *= a.X;
	Y *= a.Y;
	Z *= a.Z;
	W *= a.W;
	return *this;
}

FORCEINLINE Vector4 Vector4::operator*(const Vector4& a) const
{
	return Vector4(X * a.X, Y * a.Y, Z * a.Z, W * a.W);
}

FORCEINLINE Vector4 Vector4::operator/=(float scalar)
{
	X /= scalar;
	Y /= scalar;
	Z /= scalar;
	W /= scalar;
	return *this;
}

FORCEINLINE Vector4 Vector4::operator/(float scalar) const
{
	return Vector4(X / scalar, Y / scalar, Z / scalar, W / scalar);
}

FORCEINLINE Vector4 Vector4::operator/=(const Vector4& a)
{
	X /= a.X;
	Y /= a.Y;
	Z /= a.Z;
	W /= a.Z;
	return *this;
}

FORCEINLINE Vector4 Vector4::operator/(const Vector4& a) const
{
	return Vector4(X / a.X, Y / a.Y, Z / a.Z, W / a.W);
}

FORCEINLINE bool Vector4::operator==(const Vector4& a) const
{
	return X == a.X && Y == a.Y && Z == a.Z && W == a.W;
}

FORCEINLINE bool Vector4::operator!=(const Vector4& a) const
{
	return X != a.X || Y != a.Y || Z != a.Z || W != a.W;
}

FORCEINLINE Vector4 Vector4::operator-() const
{
	return Vector4(-X, -Y, -Z, -Z);
}

FORCEINLINE float& Vector4::operator[](std::size_t i)
{
	return (&X)[i];
}

FORCEINLINE constexpr float Vector4::operator[](std::size_t i) const
{
	return (&X)[i];
}

} // namespace Donut
