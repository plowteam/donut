// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <BulletCollision/CollisionDispatch/btCollisionWorld.h>
#include <BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h>
#include <Physics/BulletDebugDraw.h>

namespace Donut
{

class LineRenderer;

enum class PhysicsDebugDrawMode
{
	NoDebug = 0,
	DrawWireframe = (1 << 0),
	DrawAABB = (1 << 1),
	DrawFeaturesText = (1 << 2),
	DrawContactPoints = (1 << 3),
	DrawText = (1 << 6),
	FastWireframe = (1 << 13),
	DrawNormals = (1 << 14),
	DrawFrames = (1 << 15)
};

class WorldPhysics
{
public:
	WorldPhysics(LineRenderer*);
	~WorldPhysics();

	void Update(float dt) const;

	btDiscreteDynamicsWorld* GetDynamicsWorld() const { return _dynamicsWorld; }

	void SetDebugDrawMode(PhysicsDebugDrawMode mode) const { _debugDraw->setDebugMode((int)mode); }
	PhysicsDebugDrawMode GetDebugDrawMode() const { return (PhysicsDebugDrawMode)_debugDraw->getDebugMode(); }

private:
	btDiscreteDynamicsWorld* _dynamicsWorld;

	btDefaultCollisionConfiguration* _collisionConfiguration;
	btSequentialImpulseConstraintSolver* _constraintSolver;
	btCollisionDispatcher* _collisionDispatcher;
	btBroadphaseInterface* _broadphase;

	std::unique_ptr<BulletDebugDraw> _debugDraw;

	// allocated objects for cleanup
	std::vector<btCollisionObject*> _allocatedCollisionObjects;
	std::vector<std::vector<uint32_t>*> _allocatedIndexArrays;
	std::vector<std::vector<Vector3>*> _allocatedVertexArrays;
};
} // namespace Donut
