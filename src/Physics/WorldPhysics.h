#pragma once

#include <BulletCollision/CollisionDispatch/btCollisionWorld.h>
#include <BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h>
#include <Physics/BulletDebugDraw.h>
#include <CharacterController.h>

namespace Donut
{

class LineRenderer;

// forward declare some shit
namespace P3D
{
class Intersect;
class CollisionOBBoxVolume;
class CollisionSphere;
class CollisionCylinder;
class CollisionVolume;
};

class WorldPhysics
{
public:
	WorldPhysics(LineRenderer*);
	~WorldPhysics();

	void Update(float dt) const;

	void AddIntersect(const P3D::Intersect&);
	void AddCollisionVolume(const P3D::CollisionVolume&);
	void AddP3DOBBoxVolume(const P3D::CollisionOBBoxVolume&);
	void AddP3DSphere(const P3D::CollisionSphere&);
	void AddP3DCylinder(const P3D::CollisionCylinder&);

	btDiscreteDynamicsWorld* GetDynamicsWorld() const { return _dynamicsWorld; }
	
private:
	btDiscreteDynamicsWorld* _dynamicsWorld;

	btDefaultCollisionConfiguration* _collisionConfiguration;
	btSequentialImpulseConstraintSolver* _constraintSolver;
	btCollisionDispatcher* _collisionDispatcher;
	btBroadphaseInterface* _broadphase;

	std::unique_ptr<BulletDebugDraw> _debugDraw;

	// allocated objects for cleanup
	std::vector<btCollisionObject*> _allocatedCollisionObjects;
	std::vector <std::vector<uint32_t>*> _allocatedIndexArrays;
	std::vector<std::vector<glm::vec3>*> _allocatedVertexArrays;
};
} // namespace Donut
