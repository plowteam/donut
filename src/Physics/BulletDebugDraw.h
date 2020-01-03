// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <Render/LineRenderer.h>
#include <btBulletDynamicsCommon.h>

namespace Donut
{
class BulletDebugDraw: public btIDebugDraw
{

public:
	BulletDebugDraw(LineRenderer* lineRenderer);

	virtual void drawLine(const btVector3& from, const btVector3& to, const btVector3& color);
	virtual void drawTransform(const btTransform& transform, btScalar orthoLen);
	virtual void drawContactPoint(const btVector3& PointOnB, const btVector3& normalOnB, btScalar distance, int lifeTime,
	                              const btVector3& color);
	virtual void reportErrorWarning(const char* warningString);
	virtual void draw3dText(const btVector3& location, const char* textString);

	virtual void setDebugMode(int debugMode) { m_debugMode = debugMode; }
	virtual int getDebugMode() const { return m_debugMode; }

private:
	int m_debugMode;
	LineRenderer* m_lineRenderer;
};
} // namespace Donut
