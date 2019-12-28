// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Math.h"

#include <string>

namespace Donut
{

/**
 * Represents a vector in 3D space composed of three integer point values (X, Y, Z).
 */
struct Vector3Int
{
	union
	{
		struct
		{
			int X;
			int Y;
			int Z;
		};
	};

	FORCEINLINE Vector3Int() noexcept;
	FORCEINLINE constexpr Vector3Int(const int x, const int y, const int z) noexcept;
	FORCEINLINE constexpr Vector3Int(const int scalar) noexcept;

	FORCEINLINE int Length() const noexcept;
	FORCEINLINE int LengthSquared() const noexcept;

	FORCEINLINE int DistanceTo(const Vector3Int& a) noexcept;
	FORCEINLINE int DistanceToSquared(const Vector3Int& a) noexcept;

	FORCEINLINE int* Data() noexcept;
	FORCEINLINE constexpr const int* Data() const noexcept;

	std::string ToString() const;

	/* Operators */
	FORCEINLINE Vector3Int operator+=(const Vector3Int& a);
	FORCEINLINE Vector3Int operator+(const Vector3Int& a) const;
	FORCEINLINE Vector3Int operator-=(const Vector3Int& a);
	FORCEINLINE Vector3Int operator-(const Vector3Int& a) const;
	FORCEINLINE Vector3Int operator*=(const Vector3Int& a);
	FORCEINLINE Vector3Int operator*(const Vector3Int& a) const;
	FORCEINLINE Vector3Int operator/=(const Vector3Int& a);
	FORCEINLINE Vector3Int operator/(const Vector3Int& a) const;
	FORCEINLINE Vector3Int operator*=(int scalar);
	FORCEINLINE Vector3Int operator*(int scalar) const;
	FORCEINLINE Vector3Int operator/=(int scalar);
	FORCEINLINE Vector3Int operator/(int scalar) const;
	FORCEINLINE Vector3Int operator-() const;
	FORCEINLINE bool operator==(const Vector3Int& a) const;
	FORCEINLINE bool operator!=(const Vector3Int& a) const;
	FORCEINLINE int& operator[](std::size_t i);
	FORCEINLINE constexpr int operator[](std::size_t i) const;

	/** Zero vector (0, 0, 0) */
	static const Vector3Int Zero;

	/** One vector (1, 1, 1) */
	static const Vector3Int One;

	/** Up vector (0, 1, 0) */
	static const Vector3Int Up;

	/** Down vector (0, -1, 0) */
	static const Vector3Int Down;

	/** Forward vector (0, 0, 1) */
	static const Vector3Int Forward;

	/** Backward vector (0, 0, -1) */
	static const Vector3Int Backward;

	/** Right vector (1, 0, 0) */
	static const Vector3Int Right;

	/** Left vector (-1, 0, 0) */
	static const Vector3Int Left;
};

//
// Inline implementations of Vector3Int
//

// deliberately avoid initialization
#pragma warning(suppress : 26495)
/**
 * Default constructor (no initalization).
 */
FORCEINLINE Vector3Int::Vector3Int() noexcept {}

/**
 * Constructor initalizing X, Y, Z to individual given values.
 *
 * @param x X value.
 * @param y Y value.
 * @param z Z value.
 */
FORCEINLINE constexpr Vector3Int::Vector3Int(const int x, const int y, const int z) noexcept: X(x), Y(y), Z(z) {}

/**
 * Constructor initalizing X, Y, Z to a single int value.
 *
 * @param scalar Value to set X, Y, Z to.
 */
FORCEINLINE constexpr Vector3Int::Vector3Int(const int scaler) noexcept: X(scaler), Y(scaler), Z(scaler) {}

/**
 * Get the length of this vector.
 *
 * @return The length of this vector.
 */
FORCEINLINE int Vector3Int::Length() const noexcept
{
	return Math::Sqrt(X * X + Y * Y + Z * Z);
}

/**
 * Get the squared length of this vector.
 *
 * @return The squared length of this vector.
 */
FORCEINLINE int Vector3Int::LengthSquared() const noexcept
{
	return X * X + Y * Y + Z * Z;
}

FORCEINLINE int Vector3Int::DistanceTo(const Vector3Int& a) noexcept
{
	return Math::Sqrt(DistanceToSquared(a));
}

FORCEINLINE int Vector3Int::DistanceToSquared(const Vector3Int& a) noexcept
{
	return Math::Square(a.X - X) + Math::Square(a.Y - Y) + Math::Square(a.Z - Z);
}

FORCEINLINE int* Vector3Int::Data() noexcept
{
	return &X;
}

FORCEINLINE constexpr const int* Vector3Int::Data() const noexcept
{
	return &X;
}

FORCEINLINE Vector3Int Vector3Int::operator+(const Vector3Int& a) const
{
	return Vector3Int(X + a.X, Y + a.Y, Z + a.Z);
}

FORCEINLINE Vector3Int Vector3Int::operator+=(const Vector3Int& a)
{
	X += a.X;
	Y += a.Y;
	Z += a.Z;
	return *this;
}

FORCEINLINE Vector3Int Vector3Int::operator-=(const Vector3Int& a)
{
	X -= a.X;
	Y -= a.Y;
	Z -= a.Z;
	return *this;
}

FORCEINLINE Vector3Int Vector3Int::operator-(const Vector3Int& a) const
{
	return Vector3Int(X - a.X, Y - a.Y, Z - a.Z);
}

FORCEINLINE Vector3Int Vector3Int::operator*=(int scale)
{
	X *= scale;
	Y *= scale;
	Z *= scale;
	return *this;
}

FORCEINLINE Vector3Int Vector3Int::operator*(const int scale) const
{
	return Vector3Int(X * scale, Y * scale, Z * scale);
}

FORCEINLINE Vector3Int Vector3Int::operator*=(const Vector3Int& a)
{
	X *= a.X;
	Y *= a.Y;
	Z *= a.Z;
	return *this;
}

FORCEINLINE Vector3Int Vector3Int::operator*(const Vector3Int& a) const
{
	return Vector3Int(X * a.X, Y * a.Y, Z * a.Z);
}

FORCEINLINE Vector3Int Vector3Int::operator/=(int scalar)
{
	X /= scalar;
	Y /= scalar;
	Z /= scalar;
	return *this;
}

FORCEINLINE Vector3Int Vector3Int::operator/(int scalar) const
{
	return Vector3Int(X / scalar, Y / scalar, Z / scalar);
}

FORCEINLINE Vector3Int Vector3Int::operator/=(const Vector3Int& a)
{
	X /= a.X;
	Y /= a.Y;
	Z /= a.Z;
	return *this;
}

FORCEINLINE Vector3Int Vector3Int::operator/(const Vector3Int& a) const
{
	return Vector3Int(X / a.X, Y / a.Y, Z / a.Z);
}

FORCEINLINE bool Vector3Int::operator==(const Vector3Int& a) const
{
	return X == a.X && Y == a.Y && Z == a.Z;
}

FORCEINLINE bool Vector3Int::operator!=(const Vector3Int& a) const
{
	return X != a.X || Y != a.Y || Z != a.Z;
}

FORCEINLINE Vector3Int Vector3Int::operator-() const
{
	return Vector3Int(-X, -Y, -Z);
}

FORCEINLINE int& Vector3Int::operator[](std::size_t i)
{
	return (&X)[i];
}

FORCEINLINE constexpr int Vector3Int::operator[](std::size_t i) const
{
	return (&X)[i];
}

} // namespace Donut
