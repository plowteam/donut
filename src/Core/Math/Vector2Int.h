// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Math.h"

#include <string>

namespace Donut
{

/**
 * Represents a vector in 2D space composed of two integer point values (X, Y).
 */
struct Vector2Int
{
	union
	{
		struct
		{
			int X;
			int Y;
		};
	};

	FORCEINLINE Vector2Int() noexcept;
	FORCEINLINE constexpr Vector2Int(const int x, const int y) noexcept;
	FORCEINLINE constexpr Vector2Int(const int scalar) noexcept;

	FORCEINLINE int Length() const noexcept;
	FORCEINLINE int LengthSquared() const noexcept;

	FORCEINLINE int DistanceTo(const Vector2Int& a) noexcept;
	FORCEINLINE int DistanceToSquared(const Vector2Int& a) noexcept;

	FORCEINLINE int* Data() noexcept;
	FORCEINLINE constexpr const int* Data() const noexcept;

	std::string ToString() const;

	/* Operators */
	FORCEINLINE Vector2Int operator+=(const Vector2Int& a);
	FORCEINLINE Vector2Int operator+(const Vector2Int& a) const;
	FORCEINLINE Vector2Int operator-=(const Vector2Int& a);
	FORCEINLINE Vector2Int operator-(const Vector2Int& a) const;
	FORCEINLINE Vector2Int operator*=(const Vector2Int& a);
	FORCEINLINE Vector2Int operator*(const Vector2Int& a) const;
	FORCEINLINE Vector2Int operator/=(const Vector2Int& a);
	FORCEINLINE Vector2Int operator/(const Vector2Int& a) const;
	FORCEINLINE Vector2Int operator*=(int scalar);
	FORCEINLINE Vector2Int operator*(int scalar) const;
	FORCEINLINE Vector2Int operator/=(int scalar);
	FORCEINLINE Vector2Int operator/(int scalar) const;
	FORCEINLINE Vector2Int operator-() const;
	FORCEINLINE bool operator==(const Vector2Int& a) const;
	FORCEINLINE bool operator!=(const Vector2Int& a) const;
	FORCEINLINE int& operator[](std::size_t i);
	FORCEINLINE constexpr int operator[](std::size_t i) const;

	/** Zero vector (0, 0) */
	static const Vector2Int Zero;

	/** One vector (1, 1) */
	static const Vector2Int One;
};

//
// Inline implementations of Vector2Int
//

// deliberately avoid initialization
#pragma warning(suppress : 26495)
/**
 * Default constructor (no initalization).
 */
FORCEINLINE Vector2Int::Vector2Int() noexcept {}

/**
 * Constructor initalizing X, Y to individual given values.
 *
 * @param x X value.
 * @param y Y value.
 */
FORCEINLINE constexpr Vector2Int::Vector2Int(const int x, const int y) noexcept: X(x), Y(y) {}

/**
 * Constructor initalizing X, Y to a single int value.
 *
 * @param scalar Value to set X, Y to.
 */
FORCEINLINE constexpr Vector2Int::Vector2Int(const int scaler) noexcept: X(scaler), Y(scaler) {}

/**
 * Get the length of this vector.
 *
 * @return The length of this vector.
 */
FORCEINLINE int Vector2Int::Length() const noexcept
{
	return Math::Sqrt(X * X + Y * Y);
}

/**
 * Get the squared length of this vector.
 *
 * @return The squared length of this vector.
 */
FORCEINLINE int Vector2Int::LengthSquared() const noexcept
{
	return X * X + Y * Y;
}

FORCEINLINE int Vector2Int::DistanceTo(const Vector2Int& a) noexcept
{
	return Math::Sqrt(DistanceToSquared(a));
}

FORCEINLINE int Vector2Int::DistanceToSquared(const Vector2Int& a) noexcept
{
	return Math::Square(a.X - X) + Math::Square(a.Y - Y);
}

FORCEINLINE int* Vector2Int::Data() noexcept
{
	return &X;
}

FORCEINLINE constexpr const int* Vector2Int::Data() const noexcept
{
	return &X;
}

FORCEINLINE Vector2Int Vector2Int::operator+(const Vector2Int& a) const
{
	return Vector2Int(X + a.X, Y + a.Y);
}

FORCEINLINE Vector2Int Vector2Int::operator+=(const Vector2Int& a)
{
	X += a.X;
	Y += a.Y;
	return *this;
}

FORCEINLINE Vector2Int Vector2Int::operator-=(const Vector2Int& a)
{
	X -= a.X;
	Y -= a.Y;
	return *this;
}

FORCEINLINE Vector2Int Vector2Int::operator-(const Vector2Int& a) const
{
	return Vector2Int(X - a.X, Y - a.Y);
}

FORCEINLINE Vector2Int Vector2Int::operator*=(int scale)
{
	X *= scale;
	Y *= scale;
	return *this;
}

FORCEINLINE Vector2Int Vector2Int::operator*(const int scale) const
{
	return Vector2Int(X * scale, Y * scale);
}

FORCEINLINE Vector2Int Vector2Int::operator*=(const Vector2Int& a)
{
	X *= a.X;
	Y *= a.Y;
	return *this;
}

FORCEINLINE Vector2Int Vector2Int::operator*(const Vector2Int& a) const
{
	return Vector2Int(X * a.X, Y * a.Y);
}

FORCEINLINE Vector2Int Vector2Int::operator/=(int scalar)
{
	X /= scalar;
	Y /= scalar;
	return *this;
}

FORCEINLINE Vector2Int Vector2Int::operator/(int scalar) const
{
	return Vector2Int(X / scalar, Y / scalar);
}

FORCEINLINE Vector2Int Vector2Int::operator/=(const Vector2Int& a)
{
	X /= a.X;
	Y /= a.Y;
	return *this;
}

FORCEINLINE Vector2Int Vector2Int::operator/(const Vector2Int& a) const
{
	return Vector2Int(X / a.X, Y / a.Y);
}

FORCEINLINE bool Vector2Int::operator==(const Vector2Int& a) const
{
	return X == a.X && Y == a.Y;
}

FORCEINLINE bool Vector2Int::operator!=(const Vector2Int& a) const
{
	return X != a.X || Y != a.Y;
}

FORCEINLINE Vector2Int Vector2Int::operator-() const
{
	return Vector2Int(-X, -Y);
}

FORCEINLINE int& Vector2Int::operator[](std::size_t i)
{
	return (&X)[i];
}

FORCEINLINE constexpr int Vector2Int::operator[](std::size_t i) const
{
	return (&X)[i];
}

} // namespace Donut
