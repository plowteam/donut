#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include <memory>

#include <BulletCollision/CollisionShapes/btCapsuleShape.h>
#include <BulletDynamics/Character/btKinematicCharacterController.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>

class btDiscreteDynamicsWorld;

namespace Donut
{
class WorldPhysics;

class CharacterController: public btCharacterControllerInterface
{
public:
	CharacterController(WorldPhysics* physics, const glm::vec3&);

	void SetPosition(const glm::vec3& position);
	void SetRotation(const glm::quat& rotation) { _rotation = rotation; }
	const glm::vec3& GetPosition() const { return _position; }
	const glm::quat& GetRotation() const { return _rotation; }

	/** from btCharacterControllerInterface */
	~CharacterController();
	void updateAction(btCollisionWorld* collisionWorld, btScalar dt) override;
	void debugDraw(btIDebugDraw* debugDraw) override;

	void setWalkDirection(const btVector3& walkDirection) override;
	void setVelocityForTimeInterval(const btVector3& velocity, btScalar timeInterval) override;

	void reset(btCollisionWorld* collisionWorld) override;
	void warp(const btVector3& origin) override;

	void preStep(btCollisionWorld* collisionWorld) override;
	void playerStep(btCollisionWorld* collisionWorld, btScalar dt) override;
	bool canJump() const override;
	void jump(const btVector3& dir) override;
	bool onGround() const override;

	void setUpInterpolate(bool) override;

  private:
	btVector3 computeReflectionDirection(const btVector3& direction, const btVector3& normal);
	btVector3 parallelComponent(const btVector3& direction, const btVector3& normal);
	btVector3 perpendicularComponent(const btVector3& direction, const btVector3& normal);

	bool recoverFromPenetration(btCollisionWorld* collisionWorld);
	void stepUp(btCollisionWorld*);
	void stepDown(btCollisionWorld*, btScalar dt);
	void stepForwardAndStrafe(btCollisionWorld* collsionWorld, const btVector3& walkMove);

	void updateTargetPositionBasedOnCollision(const btVector3& hitNormal,
	                                          btScalar tangentMag = btScalar(0.0), btScalar normalMag = btScalar(1.0));

	glm::vec3 _position;
	glm::quat _rotation;

	btVector3 _targetPosition;

	glm::vec3 _walkDirection;
	btScalar _verticalVelocity;
	btScalar _verticalOffset;
	btScalar _stepHeight;

	btVector3 _touchingNormal;

	btManifoldArray _manifoldArray;


	std::unique_ptr<btCapsuleShape> _physShape;
	std::unique_ptr<btPairCachingGhostObject> _physGhostObject;


	WorldPhysics* _worldPhysics;
};
}
