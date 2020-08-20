// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "Physics/WorldPhysics.h"
#include "Physics/BulletCast.h"
#include "Physics/BulletDebugDraw.h"
#include "Physics/BulletFenceShape.h"

#include <BulletCollision/CollisionShapes/btBox2dShape.h>

namespace Donut
{
WorldPhysics::WorldPhysics(LineRenderer* lineRenderer)
{
	_collisionConfiguration = new btDefaultCollisionConfiguration();
	_collisionDispatcher = new btCollisionDispatcher(_collisionConfiguration);
	_broadphase = new btDbvtBroadphase();
	_constraintSolver = new btSequentialImpulseConstraintSolver();

	_dynamicsWorld = new btDiscreteDynamicsWorld(_collisionDispatcher, _broadphase, _constraintSolver, _collisionConfiguration);

	_debugDraw = std::make_unique<BulletDebugDraw>(lineRenderer);
	_debugDraw->setDebugMode(btIDebugDraw::DBG_NoDebug);

	_dynamicsWorld->setDebugDrawer(_debugDraw.get());
	_dynamicsWorld->setGravity(btVector3(0.0f, -1.0f, 0.0f));

	// _char = std::make_unique<CharacterController>(this, Vector3(Vector3(229.0f, 4.5f, -182.0f)));
}

WorldPhysics::~WorldPhysics()
{
	for (auto i = 0; i < _allocatedCollisionObjects.size(); i++)
	{
		if (_dynamicsWorld != nullptr)
			_dynamicsWorld->removeCollisionObject(_allocatedCollisionObjects[i]);

		delete _allocatedCollisionObjects[i];
	}

	_allocatedCollisionObjects.clear();

	for (auto i = 0; i < _allocatedVertexArrays.size(); i++) delete _allocatedVertexArrays[i];

	_allocatedVertexArrays.clear();

	for (auto i = 0; i < _allocatedIndexArrays.size(); i++) delete _allocatedIndexArrays[i];

	_allocatedIndexArrays.clear();

	delete _dynamicsWorld;
	delete _constraintSolver;
	delete _collisionConfiguration;
	delete _collisionDispatcher;
	delete _broadphase;
}

void WorldPhysics::Update(const float dt) const
{
	// _dynamicsWorld->stepSimulation(dt);
	_dynamicsWorld->debugDrawWorld();

	// _char->Update(_dynamicsWorld, dt);
}

} // namespace Donut
