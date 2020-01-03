// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "BulletDebugDraw.h"

#include "BulletCast.h"
#include "Core/Math/Vector4.h"

namespace Donut
{
BulletDebugDraw::BulletDebugDraw(LineRenderer* lineRenderer): m_debugMode(DBG_NoDebug), m_lineRenderer(lineRenderer) {}

void BulletDebugDraw::drawLine(const btVector3& from, const btVector3& to, const btVector3& color)
{
	if (m_lineRenderer == nullptr)
		return;

	Vector3 c = BulletCast<Vector3>(color);
	Vector4 drawColour(c.X, c.Y, c.Z, 0.75f);

	m_lineRenderer->DrawLine(BulletCast<Vector3>(from), BulletCast<Vector3>(to), drawColour);
}

void BulletDebugDraw::drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime,
                                       const btVector3& color)
{
}

void BulletDebugDraw::reportErrorWarning(const char* warningString) {}

void BulletDebugDraw::draw3dText(const btVector3& location, const char* textString) {}

void BulletDebugDraw::drawTransform(const btTransform& transform, btScalar orthoLen)
{
	btIDebugDraw::drawTransform(transform, orthoLen * 0.5f);
}
} // namespace Donut
