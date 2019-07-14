#pragma once

#include <BulletCollision/CollisionDispatch/btCollisionWorld.h>
#include <BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h>
#include <Physics/BulletDebugDraw.h>

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

	void DebugDraw() const;

	void AddIntersect(const P3D::Intersect&);
private:
	btCollisionWorld* _collisionWorld;
	btDefaultCollisionConfiguration* _collisionConfiguration;
	btCollisionDispatcher* _collisionDispatcher;
	btBroadphaseInterface* _broadphase;

	std::unique_ptr<BulletDebugDraw> _debugDraw;

	// allocated objects for cleanup
	std::vector<btCollisionObject*> _allocatedCollisionObjects;
	std::vector <std::vector<uint32_t>*> _allocatedIndexArrays;
	std::vector<std::vector<glm::vec3>*> _allocatedVertexArrays;
};
} // namespace Donut
