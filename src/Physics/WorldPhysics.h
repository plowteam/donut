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
};

class WorldPhysics
{
public:
	WorldPhysics(LineRenderer*);
	~WorldPhysics();

	void Update(float dt) const;

	void AddIntersect(const P3D::Intersect&);

	btDiscreteDynamicsWorld* GetDynamicsWorld() const { return _dynamicsWorld; }
	CharacterController* GetCharacterController() const { return _char.get(); }

	
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

	std::unique_ptr<CharacterController> _char;
};
} // namespace Donut
