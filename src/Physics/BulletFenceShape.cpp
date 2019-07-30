#include <Physics/BulletFenceShape.h>

namespace Donut
{

BulletFenceShape::BulletFenceShape(const btVector3& start, const btVector3& end, const btVector3& normal):
    btConcaveShape(), m_start(start), m_end(end), m_normal(normal.normalized())
{
	m_shapeType = BroadphaseNativeTypes::STATIC_PLANE_PROXYTYPE;
}

void BulletFenceShape::getAabb(const btTransform& t, btVector3& aabbMin, btVector3& aabbMax) const
{
	const btScalar yMin(-100.f); // BT_LARGE_FLOAT
	const btScalar yMax(100.f); // BT_LARGE_FLOAT

	aabbMin.setValue(m_start.getX(), yMin, m_start.getZ());
	aabbMax.setValue(m_end.getX(), yMax, m_end.getZ());
}

void BulletFenceShape::processAllTriangles(btTriangleCallback* callback, const btVector3& aabbMin, const btVector3& aabbMax) const
{
	btVector3 triangle[3];
	triangle[0] = m_start + btVector3(0, 100.0f, 0);
	triangle[1] = m_start - btVector3(0, 100.0f, 0);
	triangle[2] = m_end - btVector3(0, 100.0f, 0);

	callback->processTriangle(triangle, 0, 0);

	triangle[0] = m_start + btVector3(0, 100.0f, 0);
	triangle[1] = m_end + btVector3(0, 100.0f, 0);
	triangle[2] = m_end - btVector3(0, 100.0f, 0);

	callback->processTriangle(triangle, 0, 1);
}

void BulletFenceShape::calculateLocalInertia(btScalar mass, btVector3& inertia) const
{
	inertia.setValue(btScalar(0.), btScalar(0.), btScalar(0.));
}

void BulletFenceShape::setLocalScaling(const btVector3& scaling)
{
	m_localScaling = scaling;
}

const btVector3& BulletFenceShape::getLocalScaling() const
{
	return m_localScaling;
}

}
