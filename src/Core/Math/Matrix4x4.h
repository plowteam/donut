// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Matrix3x3.h"
#include "Core/Math/Vector3.h"
#include "Core/Platform.h"

#include <assert.h>
#include <cstddef>

namespace Donut
{

struct Quaternion;

/*	
    [ M[0][0]  M[0][1]  M[0][2]  M[0][3] ]
    | M[1][0]  M[1][1]  M[1][2]  M[1][3] |
    | M[2][0]  M[2][1]  M[2][2]  M[2][3] |
    [ M[3][0]  M[3][1]  M[3][2]  M[3][3] ]
*/
struct Matrix4x4
{
public:
	union
	{
		float M[4][4];
		float M16[16];
	};

	MS_ALIGN(16)
	static const Matrix4x4 Zero GCC_ALIGN(16);
	MS_ALIGN(16)
	static const Matrix4x4 Identity GCC_ALIGN(16);

	/* Constructors */
	FORCEINLINE Matrix4x4();
	FORCEINLINE Matrix4x4(float xx, float xy, float xz, float xw, float yx, float yy, float yz, float yw, float zx, float zy,
	                      float zz, float zw, float wx, float wy, float wz, float ww);
	FORCEINLINE Matrix4x4(Matrix3x3 m);
	FORCEINLINE Matrix4x4(Quaternion rot);

	/* Matrix Operators */
	FORCEINLINE Matrix4x4 operator*(const Matrix4x4& m) const;
	FORCEINLINE void operator*=(const Matrix4x4& m);
	FORCEINLINE Matrix4x4 operator+(const Matrix4x4& mr) const;
	FORCEINLINE void operator+=(const Matrix4x4& m);
	FORCEINLINE Matrix4x4 operator*(float m) const;
	FORCEINLINE void operator*=(float m);

	/* Comparison operators */
	inline bool operator==(const Matrix4x4& m) const;
	inline bool operator!=(const Matrix4x4& m) const;

	/* Vector operators */
	// FORCEINLINE Matrix4x4 operator*(const Vector3& v) const;
	// FORCEINLINE Matrix4x4 operator*(const Vector4& v) const;

	/* Row access operators */
	inline float* operator[](std::size_t row);
	inline const float* operator[](std::size_t row) const;

	/* Float casting operators */
	FORCEINLINE operator float*() { return M16; }
	FORCEINLINE operator const float*() const { return M16; }

	FORCEINLINE Matrix4x4 GetTransposed() const;
	inline float Determinant() const;
	inline Matrix4x4 Inverse() const;
	Quaternion ToQuat() const;
	FORCEINLINE Vector3 Translation() const;

	std::string ToString() const;

	// Static factory methods (do these belong here?)
	static Matrix4x4 MakeTranslate(const Vector3& v);
	static Matrix4x4 MakeOrtho(float left, float right, float bottom, float top);
};

// disable clang-format for matrix methods
// clang-format off

#pragma warning(suppress : 26495) // don't initalize for speed
FORCEINLINE Matrix4x4::Matrix4x4()
{
}

FORCEINLINE Matrix4x4::Matrix4x4(float xx, float xy, float xz, float xw,
                                 float yx, float yy, float yz, float yw,
                                 float zx, float zy, float zz, float zw,
                                 float wx, float wy, float wz, float ww)
{
	M[0][0] = xx; M[0][1] = xy; M[0][2] = xz; M[0][3] = xw;
	M[1][0] = yx; M[1][1] = yy; M[1][2] = yz; M[1][3] = yw;
	M[2][0] = zx; M[2][1] = zy; M[2][2] = zz; M[2][3] = zw;
	M[3][0] = wx; M[3][1] = wy; M[3][2] = wz; M[3][3] = ww;
}

FORCEINLINE Matrix4x4::Matrix4x4(Matrix3x3 m)
{
	M[0][0] = m.M[0][0]; M[0][1] = m.M[0][1]; M[0][2] = m.M[0][2]; M[0][3] = 0.0f;
    M[1][0] = m.M[1][0]; M[1][1] = m.M[1][1]; M[1][2] = m.M[1][2]; M[1][3] = 0.0f;
    M[2][0] = m.M[2][0]; M[2][1] = m.M[2][1]; M[2][2] = m.M[2][2]; M[2][3] = 0.0f;
    M[3][0] = 0.0f;      M[3][1] = 0.0f;      M[3][2] = 0.0f;      M[3][3] = 1.0f;
}

FORCEINLINE Matrix4x4::Matrix4x4(Quaternion q)
{
	operator=(Identity);

	float qxx = q.X * q.X, qyy = q.Y * q.Y, qzz = q.Z * q.Z;
	float qxz = q.X * q.Z, qxy = q.X * q.Y, qyz = q.Y * q.Z;
	float qwx = q.W * q.X, qwy = q.W * q.Y, qwz = q.W * q.Z;

	M[0][0] = 1.0f - 2.0f * (qyy + qzz);
	M[0][1] = 2.0f * (qxy + qwz);
	M[0][2] = 2.0f * (qxz - qwy);

	M[1][0] = 2.0f * (qxy - qwz);
	M[1][1] = 1.0f - 2.0f * (qxx + qzz);
	M[1][2] = 2.0f * (qyz + qwx);

	M[2][0] = 2.0f * (qxz + qwy);
	M[2][1] = 2.0f * (qyz - qwx);
	M[2][2] = 1.0f - 2.0f * (qxx + qyy);
}

FORCEINLINE Matrix4x4 Matrix4x4::operator*(const Matrix4x4& m) const
{
	return Matrix4x4(
	    M[0][0] * m.M[0][0] + M[1][0] * m.M[0][1] + M[2][0] * m.M[0][2] + M[3][0] * m.M[0][3],
	    M[0][1] * m.M[0][0] + M[1][1] * m.M[0][1] + M[2][1] * m.M[0][2] + M[3][1] * m.M[0][3],
	    M[0][2] * m.M[0][0] + M[1][2] * m.M[0][1] + M[2][2] * m.M[0][2] + M[3][2] * m.M[0][3],
	    M[0][3] * m.M[0][0] + M[1][3] * m.M[0][1] + M[2][3] * m.M[0][2] + M[3][3] * m.M[0][3],

	    M[0][0] * m.M[1][0] + M[1][0] * m.M[1][1] + M[2][0] * m.M[1][2] + M[3][0] * m.M[1][3],
	    M[0][1] * m.M[1][0] + M[1][1] * m.M[1][1] + M[2][1] * m.M[1][2] + M[3][1] * m.M[1][3],
	    M[0][2] * m.M[1][0] + M[1][2] * m.M[1][1] + M[2][2] * m.M[1][2] + M[3][2] * m.M[1][3],
	    M[0][3] * m.M[1][0] + M[1][3] * m.M[1][1] + M[2][3] * m.M[1][2] + M[3][3] * m.M[1][3],

	    M[0][0] * m.M[2][0] + M[1][0] * m.M[2][1] + M[2][0] * m.M[2][2] + M[3][0] * m.M[2][3],
	    M[0][1] * m.M[2][0] + M[1][1] * m.M[2][1] + M[2][1] * m.M[2][2] + M[3][1] * m.M[2][3],
	    M[0][2] * m.M[2][0] + M[1][2] * m.M[2][1] + M[2][2] * m.M[2][2] + M[3][2] * m.M[2][3],
	    M[0][3] * m.M[2][0] + M[1][3] * m.M[2][1] + M[2][3] * m.M[2][2] + M[3][3] * m.M[2][3],

	    M[0][0] * m.M[3][0] + M[1][0] * m.M[3][1] + M[2][0] * m.M[3][2] + M[3][0] * m.M[3][3],
	    M[0][1] * m.M[3][0] + M[1][1] * m.M[3][1] + M[2][1] * m.M[3][2] + M[3][1] * m.M[3][3],
	    M[0][2] * m.M[3][0] + M[1][2] * m.M[3][1] + M[2][2] * m.M[3][2] + M[3][2] * m.M[3][3],
	    M[0][3] * m.M[3][0] + M[1][3] * m.M[3][1] + M[2][3] * m.M[3][2] + M[3][3] * m.M[3][3]);
}

FORCEINLINE void Matrix4x4::operator*=(const Matrix4x4& m)
{
	*this = *this * m;
}


FORCEINLINE Matrix4x4 Matrix4x4::operator+(const Matrix4x4& m) const
{
	Matrix4x4 result;
	for (auto x = 0; x < 4; x++)
		for (auto y = 0; y < 4; y++)
			result.M[x][y] = M[x][y] + m.M[x][y];

	return result;
}

FORCEINLINE void Matrix4x4::operator+=(const Matrix4x4& m)
{
	*this = *this + m;
}

FORCEINLINE Matrix4x4 Matrix4x4::operator*(float m) const
{
	Matrix4x4 result;
	for (auto x = 0; x < 4; x++)
		for (auto y = 0; y < 4; y++)
			result.M[x][y] = M[x][y] * m;

	return result;
}

FORCEINLINE void Matrix4x4::operator*=(float m)
{
	*this = *this * m;
}

inline bool Matrix4x4::operator==(const Matrix4x4& m) const
{
	for (auto x = 0; x < 4; x++)
		for (auto y = 0; y < 4; y++)
			if (M[x][y] != m.M[x][y])
				return false;

	return true;
}

inline bool Matrix4x4::operator!=(const Matrix4x4& m) const
{
	return !(*this == m);
}

inline float* Matrix4x4::operator[](std::size_t row)
{
	assert(row < 4);
	return M[row];
}

inline const float* Matrix4x4::operator[](std::size_t row) const
{
	assert(row < 4);
	return M[row];
}

Matrix4x4 Matrix4x4::GetTransposed() const
{
	return Matrix4x4(M[0][0], M[1][0], M[2][0], M[3][0],
	                 M[0][1], M[1][1], M[2][1], M[3][1],
	                 M[0][2], M[1][2], M[2][2], M[3][2],
	                 M[0][3], M[1][3], M[2][3], M[3][3]);
}

inline float Matrix4x4::Determinant() const
{
	return (M[0][0] * M[1][1] - M[1][0] * M[0][1]) * (M[2][2] * M[3][3] - M[3][2] * M[2][3]) - (M[0][0] * M[2][1] - M[2][0] * M[0][1]) * (M[1][2] * M[3][3] - M[3][2] * M[1][3]) +
	       (M[0][0] * M[3][1] - M[3][0] * M[0][1]) * (M[1][2] * M[2][3] - M[2][2] * M[1][3]) + (M[1][0] * M[2][1] - M[2][0] * M[1][1]) * (M[0][2] * M[3][3] - M[3][2] * M[0][3]) -
	       (M[1][0] * M[3][1] - M[3][0] * M[1][1]) * (M[0][2] * M[2][3] - M[2][2] * M[0][3]) + (M[2][0] * M[3][1] - M[3][0] * M[2][1]) * (M[0][2] * M[1][3] - M[1][2] * M[0][3]);
}

inline Matrix4x4 Matrix4x4::Inverse() const
{
	float det = Determinant();

	if (det)
	{
		det = 1.0f / det;

		return Matrix4x4(det * (M[1][1] * (M[2][2] * M[3][3] - M[3][2] * M[2][3]) + M[2][1] * (M[3][2] * M[1][3] - M[1][2] * M[3][3]) + M[3][1] * (M[1][2] * M[2][3] - M[2][2] * M[1][3])), det * (M[2][1] * (M[0][2] * M[3][3] - M[3][2] * M[0][3]) + M[3][1] * (M[2][2] * M[0][3] - M[0][2] * M[2][3]) + M[0][1] * (M[3][2] * M[2][3] - M[2][2] * M[3][3])), det * (M[3][1] * (M[0][2] * M[1][3] - M[1][2] * M[0][3]) + M[0][1] * (M[1][2] * M[3][3] - M[3][2] * M[1][3]) + M[1][1] * (M[3][2] * M[0][3] - M[0][2] * M[3][3])), det * (M[0][1] * (M[2][2] * M[1][3] - M[1][2] * M[2][3]) + M[1][1] * (M[0][2] * M[2][3] - M[2][2] * M[0][3]) + M[2][1] * (M[1][2] * M[0][3] - M[0][2] * M[1][3])),
		                 det * (M[1][2] * (M[2][0] * M[3][3] - M[3][0] * M[2][3]) + M[2][2] * (M[3][0] * M[1][3] - M[1][0] * M[3][3]) + M[3][2] * (M[1][0] * M[2][3] - M[2][0] * M[1][3])), det * (M[2][2] * (M[0][0] * M[3][3] - M[3][0] * M[0][3]) + M[3][2] * (M[2][0] * M[0][3] - M[0][0] * M[2][3]) + M[0][2] * (M[3][0] * M[2][3] - M[2][0] * M[3][3])), det * (M[3][2] * (M[0][0] * M[1][3] - M[1][0] * M[0][3]) + M[0][2] * (M[1][0] * M[3][3] - M[3][0] * M[1][3]) + M[1][2] * (M[3][0] * M[0][3] - M[0][0] * M[3][3])), det * (M[0][2] * (M[2][0] * M[1][3] - M[1][0] * M[2][3]) + M[1][2] * (M[0][0] * M[2][3] - M[2][0] * M[0][3]) + M[2][2] * (M[1][0] * M[0][3] - M[0][0] * M[1][3])),
		                 det * (M[1][3] * (M[2][0] * M[3][1] - M[3][0] * M[2][1]) + M[2][3] * (M[3][0] * M[1][1] - M[1][0] * M[3][1]) + M[3][3] * (M[1][0] * M[2][1] - M[2][0] * M[1][1])), det * (M[2][3] * (M[0][0] * M[3][1] - M[3][0] * M[0][1]) + M[3][3] * (M[2][0] * M[0][1] - M[0][0] * M[2][1]) + M[0][3] * (M[3][0] * M[2][1] - M[2][0] * M[3][1])), det * (M[3][3] * (M[0][0] * M[1][1] - M[1][0] * M[0][1]) + M[0][3] * (M[1][0] * M[3][1] - M[3][0] * M[1][1]) + M[1][3] * (M[3][0] * M[0][1] - M[0][0] * M[3][1])), det * (M[0][3] * (M[2][0] * M[1][1] - M[1][0] * M[2][1]) + M[1][3] * (M[0][0] * M[2][1] - M[2][0] * M[0][1]) + M[2][3] * (M[1][0] * M[0][1] - M[0][0] * M[1][1])),
		                 det * (M[1][0] * (M[3][1] * M[2][2] - M[2][1] * M[3][2]) + M[2][0] * (M[1][1] * M[3][2] - M[3][1] * M[1][2]) + M[3][0] * (M[2][1] * M[1][2] - M[1][1] * M[2][2])), det * (M[2][0] * (M[3][1] * M[0][2] - M[0][1] * M[3][2]) + M[3][0] * (M[0][1] * M[2][2] - M[2][1] * M[0][2]) + M[0][0] * (M[2][1] * M[3][2] - M[3][1] * M[2][2])), det * (M[3][0] * (M[1][1] * M[0][2] - M[0][1] * M[1][2]) + M[0][0] * (M[3][1] * M[1][2] - M[1][1] * M[3][2]) + M[1][0] * (M[0][1] * M[3][2] - M[3][1] * M[0][2])), det * (M[0][0] * (M[1][1] * M[2][2] - M[2][1] * M[1][2]) + M[1][0] * (M[2][1] * M[0][2] - M[0][1] * M[2][2]) + M[2][0] * (M[0][1] * M[1][2] - M[1][1] * M[0][2])));
	}

	return Identity;
}

FORCEINLINE Vector3 Matrix4x4::Translation() const
{
	return Vector3(M[0][3], M[1][3], M[2][3]);
}

// clang-format on

} // namespace Donut
