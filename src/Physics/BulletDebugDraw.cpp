// Copyright 2019 the donut authors. See AUTHORS.md

#include "BulletDebugDraw.h"

#include "BulletCast.h"

namespace Donut
{
BulletDebugDraw::BulletDebugDraw(LineRenderer* lineRenderer):
    m_debugMode(DBG_NoDebug),
    m_lineRenderer(lineRenderer)
{
}

void BulletDebugDraw::drawLine(const btVector3& from, const btVector3& to, const btVector3& color)
{
	if (m_lineRenderer == nullptr) return;

	glm::vec3 c = BulletCast<glm::vec3>(color);
	glm::vec4 drawColour(c.x, c.y, c.z, 0.75f);

	m_lineRenderer->DrawLine(BulletCast<glm::vec3>(from), BulletCast<glm::vec3>(to), drawColour);
}

void BulletDebugDraw::drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime, const btVector3& color)
{
}

void BulletDebugDraw::reportErrorWarning(const char* warningString)
{
}

void BulletDebugDraw::draw3dText(const btVector3& location, const char* textString)
{
}

void BulletDebugDraw::drawTransform(const btTransform& transform, btScalar orthoLen)
{
	btIDebugDraw::drawTransform(transform, orthoLen * 0.5f);
}
} // namespace Donut
