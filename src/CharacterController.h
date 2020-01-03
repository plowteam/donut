// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Quaternion.h"
#include "Core/Math/Vector3.h"

#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include <BulletCollision/CollisionShapes/btCapsuleShape.h>
#include <BulletDynamics/Character/btKinematicCharacterController.h>

#include <memory>

class btDiscreteDynamicsWorld;

namespace Donut
{
class Character;
class WorldPhysics;

/*
 * Based off of btKinematicCharacterController
 * Uses a ghost object and convex sweep test to test for upcoming collisions.
 */
class CharacterController: public btCharacterControllerInterface
{
public:
	CharacterController(Character* character, WorldPhysics* physics);
	~CharacterController();

	// btActionInterface
	void updateAction(btCollisionWorld* collisionWorld, btScalar deltaTime) override;
	void debugDraw(btIDebugDraw* debugDrawer) override;

	// btCharacterControllerInterface
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

	const btCapsuleShape& GetShape() const { return *_physShape; }

private:
	btVector3 computeReflectionDirection(const btVector3& direction, const btVector3& normal);
	btVector3 parallelComponent(const btVector3& direction, const btVector3& normal);
	btVector3 perpendicularComponent(const btVector3& direction, const btVector3& normal);

	bool recoverFromPenetration(btCollisionWorld* collisionWorld);
	void stepUp(btCollisionWorld*);
	void stepDown(btCollisionWorld*, btScalar dt);
	void stepForwardAndStrafe(btCollisionWorld* collsionWorld, const btVector3& walkMove);

	void updateTargetPositionBasedOnCollision(const btVector3& hitNormal, btScalar tangentMag = btScalar(0.0),
	                                          btScalar normalMag = btScalar(1.0));

	Character* _character;
	WorldPhysics* _worldPhysics; // should be a weak_ptr to a shared_ptr

	btPairCachingGhostObject* _ghostObject;
	btConvexShape* _convexShape;
	btManifoldArray _manifoldArray;

	Vector3 _position;
	Quaternion _rotation;

	btVector3 _targetPosition;

	Vector3 _walkDirection;
	btScalar _verticalVelocity;
	btScalar _verticalOffset;
	btScalar _stepHeight;

	btVector3 _touchingNormal;

	std::unique_ptr<btCapsuleShape> _physShape;
	std::unique_ptr<btPairCachingGhostObject> _physGhostObject;
};
} // namespace Donut
