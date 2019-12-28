// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Platform.h"

#include <math.h>

namespace Donut
{
struct Math
{
	static const float Pi;
	static const float Pi2;
	static const float InvPi;
	static const float HalfPi;
	static const float Epsilon;

	static FORCEINLINE float CeilF(float value) { return ceilf(value); }
	static FORCEINLINE float Sin(float value) { return sinf(value); }
	static FORCEINLINE float Cos(float value) { return cosf(value); }
	static FORCEINLINE float Tan(float value) { return tanf(value); }
	static FORCEINLINE float Sqrt(float value) { return sqrtf(value); }
	static FORCEINLINE float InvSqrt(float value) { return 1.0f / sqrtf(value); }

	template <class T>
	static FORCEINLINE T Clamp(const T x, const T min, const T max)
	{
		return x < min ? min : x < max ? x : max;
	}

	template <class T>
	static FORCEINLINE T Square(const T A)
	{
		return A * A;
	}

	template <class T>
	static constexpr FORCEINLINE T Abs(const T A)
	{
		return (A >= (T)0) ? A : -A;
	}

	static FORCEINLINE float RadiansToDegrees(float rad) { return rad * (180.0f / Pi); }

	static FORCEINLINE float DegreesToRadians(float deg) { return deg * (Pi / 180.0f); }
};
} // namespace Donut
