// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Matrix3x3.h"
#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Vector3.h"

#include <btBulletDynamicsCommon.h>

namespace Donut
{
template <class T, class F>
inline T BulletCast(const F& f);

template <>
inline Vector3 BulletCast(const btVector3& v)
{
	return Vector3(v.x(), v.y(), v.z());
}

template <>
inline btVector3 BulletCast(const Vector3& v)
{
	return btVector3(v.X, v.Y, v.Z);
}

/*template <>
inline btVector3 BulletCast(const glm::ivec3& v)
{
    return btVector3(btScalar(v.x), btScalar(v.y), btScalar(v.z));
}*/

template <>
inline Quaternion BulletCast(const btQuaternion& q)
{
	return Quaternion(q.w(), q.x(), q.y(), q.z());
}

template <>
inline btQuaternion BulletCast(const Quaternion& q)
{
	return btQuaternion(q.X, q.Y, q.Z, q.W);
}

template <>
inline Matrix3x3 BulletCast(const btMatrix3x3& m)
{
	return Matrix3x3(m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);
}

template <>
inline btMatrix3x3 BulletCast(const Matrix3x3& m)
{
	return btMatrix3x3(m.M[0][0], m.M[0][1], m.M[0][2], m.M[1][0], m.M[1][1], m.M[1][2], m.M[2][0], m.M[2][1], m.M[2][2]);
}
} // namespace Donut
