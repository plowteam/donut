// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <BulletCollision/CollisionShapes/btConcaveShape.h>

namespace Donut
{

ATTRIBUTE_ALIGNED16(class)
BulletFenceShape: public btConcaveShape
{
protected:
	btVector3 m_start;
	btVector3 m_end;
	btVector3 m_normal;

	btVector3 m_localScaling;

public:
	BT_DECLARE_ALIGNED_ALLOCATOR();

	BulletFenceShape(const btVector3& start, const btVector3& end, const btVector3& normal);

	virtual ~BulletFenceShape() = default;

	virtual void getAabb(const btTransform& t, btVector3& aabbMin, btVector3& aabbMax) const;

	virtual void processAllTriangles(btTriangleCallback * callback, const btVector3& aabbMin, const btVector3& aabbMax) const;

	virtual void calculateLocalInertia(btScalar mass, btVector3 & inertia) const;

	virtual void setLocalScaling(const btVector3& scaling);
	virtual const btVector3& getLocalScaling() const;

	const btVector3& getNormal() const { return m_normal; }

	// debugging
	virtual const char* getName() const { return "DONUTFENCE"; }
	// virtual int calculateSerializeBufferSize() const;
	// virtual const char* serialize(void* dataBuffer, btSerializer* serializer) const;
};
} // namespace Donut
