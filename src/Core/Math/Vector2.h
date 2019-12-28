// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Math.h"

#include <string>

namespace Donut
{

struct Vector2Int;

/**
 * Represents a vector in 2D space composed of two single precision floating point values (X, Y).
 */
struct Vector2
{
	union
	{
		struct
		{
			float X;
			float Y;
		};
	};

	FORCEINLINE Vector2() noexcept;
	FORCEINLINE constexpr Vector2(const float x, const float y) noexcept;
	FORCEINLINE constexpr Vector2(const float scalar) noexcept;
	Vector2(const Vector2Int& v);

	FORCEINLINE float Length() const noexcept;
	FORCEINLINE float LengthSquared() const noexcept;

	FORCEINLINE void Normalize() noexcept;
	FORCEINLINE Vector2 Normalized() const noexcept;
	FORCEINLINE bool IsNormalized() const noexcept;

	FORCEINLINE float Dot(const Vector2& a) noexcept;
	FORCEINLINE float DistanceTo(const Vector2& a) noexcept;
	FORCEINLINE float DistanceToSquared(const Vector2& a) noexcept;

	FORCEINLINE float* Data() noexcept;
	FORCEINLINE constexpr const float* Data() const noexcept;

	std::string ToString() const;

	/* Operators */
	FORCEINLINE Vector2 operator+=(const Vector2& a);
	FORCEINLINE Vector2 operator+(const Vector2& a) const;
	FORCEINLINE Vector2 operator-=(const Vector2& a);
	FORCEINLINE Vector2 operator-(const Vector2& a) const;
	FORCEINLINE Vector2 operator*=(const Vector2& a);
	FORCEINLINE Vector2 operator*(const Vector2& a) const;
	FORCEINLINE Vector2 operator/=(const Vector2& a);
	FORCEINLINE Vector2 operator/(const Vector2& a) const;
	FORCEINLINE Vector2 operator*=(float scalar);
	FORCEINLINE Vector2 operator*(float scalar) const;
	FORCEINLINE Vector2 operator/=(float scalar);
	FORCEINLINE Vector2 operator/(float scalar) const;
	FORCEINLINE Vector2 operator-() const;
	FORCEINLINE bool operator==(const Vector2& a) const;
	FORCEINLINE bool operator!=(const Vector2& a) const;
	FORCEINLINE float& operator[](std::size_t i);
	FORCEINLINE constexpr float operator[](std::size_t i) const;

	/** Zero vector (0, 0) */
	static const Vector2 Zero;

	/** One vector (1, 1) */
	static const Vector2 One;
};

//
// Inline implementations of Vector2
//

// deliberately avoid initialization
#pragma warning(suppress : 26495)
/**
 * Default constructor (no initalization).
 */
FORCEINLINE Vector2::Vector2() noexcept {}

/**
 * Constructor initalizing X, Y to individual given values.
 *
 * @param x X value.
 * @param y Y value.
 */
FORCEINLINE constexpr Vector2::Vector2(const float x, const float y) noexcept: X(x), Y(y) {}

/**
 * Constructor initalizing X, Y to a single float value.
 *
 * @param scalar Value to set X, Y to.
 */
FORCEINLINE constexpr Vector2::Vector2(const float scaler) noexcept: X(scaler), Y(scaler) {}

/**
 * Get the length of this vector.
 *
 * @return The length of this vector.
 */
FORCEINLINE float Vector2::Length() const noexcept
{
	return Math::Sqrt(X * X + Y * Y);
}

/**
 * Get the squared length of this vector.
 *
 * @return The squared length of this vector.
 */
FORCEINLINE float Vector2::LengthSquared() const noexcept
{
	return X * X + Y * Y;
}

/**
 * Normalizes this vector in place.
 */
FORCEINLINE void Vector2::Normalize() noexcept
{
	const float squareSum = X * X + Y * Y;

	if (squareSum == 0.0f)
	{
		X = Y = 0;
		return;
	}

	const float scale = Math::InvSqrt(squareSum);
	X *= scale;
	Y *= scale;
}

/**
 * Gets a normalized copy of the vector.
 *
 * @return Normalized copy of this vector.
 */
FORCEINLINE Vector2 Vector2::Normalized() const noexcept
{
	Vector2 v = *this;
	v.Normalize();
	return v;
}

/**
 * Determine whether this vector is normalized.
 *
 * @return true if normalized, otherwise false.
 */
FORCEINLINE bool Vector2::IsNormalized() const noexcept
{
	const float squareSum = X * X + Y * Y;

	return squareSum == 1.0f;
}

FORCEINLINE float Vector2::Dot(const Vector2& a) noexcept
{
	return X * a.X + Y * a.Y;
}

FORCEINLINE float Vector2::DistanceTo(const Vector2& a) noexcept
{
	return Math::Sqrt(DistanceToSquared(a));
}

FORCEINLINE float Vector2::DistanceToSquared(const Vector2& a) noexcept
{
	return Math::Square(a.X - X) + Math::Square(a.Y - Y);
}

FORCEINLINE float* Vector2::Data() noexcept
{
	return &X;
}

FORCEINLINE constexpr const float* Vector2::Data() const noexcept
{
	return &X;
}

FORCEINLINE Vector2 Vector2::operator+(const Vector2& a) const
{
	return Vector2(X + a.X, Y + a.Y);
}

FORCEINLINE Vector2 Vector2::operator+=(const Vector2& a)
{
	X += a.X;
	Y += a.Y;
	return *this;
}

FORCEINLINE Vector2 Vector2::operator-=(const Vector2& a)
{
	X -= a.X;
	Y -= a.Y;
	return *this;
}

FORCEINLINE Vector2 Vector2::operator-(const Vector2& a) const
{
	return Vector2(X - a.X, Y - a.Y);
}

FORCEINLINE Vector2 Vector2::operator*=(float scale)
{
	X *= scale;
	Y *= scale;
	return *this;
}

FORCEINLINE Vector2 Vector2::operator*(const float scale) const
{
	return Vector2(X * scale, Y * scale);
}

FORCEINLINE Vector2 Vector2::operator*=(const Vector2& a)
{
	X *= a.X;
	Y *= a.Y;
	return *this;
}

FORCEINLINE Vector2 Vector2::operator*(const Vector2& a) const
{
	return Vector2(X * a.X, Y * a.Y);
}

FORCEINLINE Vector2 Vector2::operator/=(float scalar)
{
	X /= scalar;
	Y /= scalar;
	return *this;
}

FORCEINLINE Vector2 Vector2::operator/(float scalar) const
{
	return Vector2(X / scalar, Y / scalar);
}

FORCEINLINE Vector2 Vector2::operator/=(const Vector2& a)
{
	X /= a.X;
	Y /= a.Y;
	return *this;
}

FORCEINLINE Vector2 Vector2::operator/(const Vector2& a) const
{
	return Vector2(X / a.X, Y / a.Y);
}

FORCEINLINE bool Vector2::operator==(const Vector2& a) const
{
	return X == a.X && Y == a.Y;
}

FORCEINLINE bool Vector2::operator!=(const Vector2& a) const
{
	return X != a.X || Y != a.Y;
}

FORCEINLINE Vector2 Vector2::operator-() const
{
	return Vector2(-X, -Y);
}

FORCEINLINE float& Vector2::operator[](std::size_t i)
{
	return (&X)[i];
}

FORCEINLINE constexpr float Vector2::operator[](std::size_t i) const
{
	return (&X)[i];
}

} // namespace Donut
