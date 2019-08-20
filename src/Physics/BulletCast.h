// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

#include <btBulletDynamicsCommon.h>
#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>

namespace Donut
{
template <class T, class F>
inline T BulletCast(const F& f);

template <>
inline glm::vec3 BulletCast(const btVector3& v)
{
	return glm::vec3(v.x(), v.y(), v.z());
}

template <>
inline btVector3 BulletCast(const glm::vec3& v)
{
	return btVector3(v.x, v.y, v.z);
}

template <>
inline btVector3 BulletCast(const glm::ivec3& v)
{
	return btVector3(btScalar(v.x), btScalar(v.y), btScalar(v.z));
}

template <>
inline glm::quat BulletCast(const btQuaternion& q)
{
	return glm::quat(q.w(), q.x(), q.y(), q.z());
}

template <>
inline btQuaternion BulletCast(const glm::quat& q)
{
	return btQuaternion(q.x, q.y, q.z, q.w);
}

template <>
inline glm::mat3 BulletCast(const btMatrix3x3& m)
{
	return glm::mat3(BulletCast<glm::vec3>(m[0]),
	                 BulletCast<glm::vec3>(m[1]),
	                 BulletCast<glm::vec3>(m[2]));
}

template <>
inline btMatrix3x3 BulletCast(const glm::mat3& m)
{
	return btMatrix3x3(m[0][0], m[0][1], m[0][2],
	                   m[1][0], m[1][1], m[1][2],
	                   m[2][0], m[2][1], m[2][2]);
}
} // namespace Donut
