#include <Character.h>
#include <CharacterController.h>
#include <Physics/BulletCast.h>
#include <Physics/WorldPhysics.h>
#include <btBulletDynamicsCommon.h>

namespace Donut
{

CharacterController::CharacterController(Character* character, WorldPhysics* physics):
    _character(character), _worldPhysics(physics)
{
	_walkDirection    = glm::vec3(0.0f, 0.0f, 0.0f);
	_verticalVelocity = 0.0f;
	_verticalOffset   = 0.0f;
	_stepHeight       = 0.05;

	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(BulletCast<btVector3>(character->GetPosition()));
	_position       = character->GetPosition();
	_targetPosition = BulletCast<btVector3>(character->GetPosition());

	_physShape       = std::make_unique<btCapsuleShape>(0.4, 0.95f);

	_physGhostObject = std::make_unique<btPairCachingGhostObject>();
	_physGhostObject->setWorldTransform(transform);
	_physGhostObject->setCollisionShape(_physShape.get());
	_physGhostObject->setCollisionFlags(btCollisionObject::CF_CHARACTER_OBJECT);

	// probably add these via physics so it's fuckin tracked and freed
	physics->GetDynamicsWorld()->addCollisionObject(_physGhostObject.get(),
	                                                btBroadphaseProxy::CharacterFilter,
	                                                btBroadphaseProxy::StaticFilter | btBroadphaseProxy::DefaultFilter | btBroadphaseProxy::CharacterFilter | btBroadphaseProxy::SensorTrigger);

	physics->GetDynamicsWorld()->addAction(static_cast<btActionInterface*>(this));
}

CharacterController::~CharacterController()
{
	if (_worldPhysics == nullptr)
		return;

	// _worldPhysics->GetDynamicsWorld()->removeAction(this);
	// _worldPhysics->GetDynamicsWorld()->removeCollisionObject(_physGhostObject.get());
}

void CharacterController::updateAction(btCollisionWorld* collisionWorld, btScalar dt)
{
	preStep(collisionWorld);
	playerStep(collisionWorld, dt);
}

void CharacterController::debugDraw(btIDebugDraw* debugDraw) {}
void CharacterController::reset(btCollisionWorld* collisionWorld) {}

void CharacterController::setWalkDirection(const btVector3& walkDirection)
{
	_walkDirection = BulletCast<glm::vec3>(walkDirection);
}

void CharacterController::setVelocityForTimeInterval(const btVector3& velocity, btScalar timeInterval)
{
	printf("setVelocityForTimeInterval: %f, %f, %f\n", velocity.getX(), velocity.getY(), velocity.getZ());
}

void CharacterController::warp(const btVector3& origin)
{
	btTransform transform;
	transform.setIdentity();
	transform.setOrigin(origin);

	_physGhostObject->setWorldTransform(transform);
	_position       = BulletCast<glm::vec3>(origin);
	_targetPosition = origin;
}

void CharacterController::preStep(btCollisionWorld* collisionWorld)
{
	int numPenetrationLoops = 0;
	while (recoverFromPenetration(collisionWorld) && numPenetrationLoops < 4)
		numPenetrationLoops++;

	_position       = BulletCast<glm::vec3>(_physGhostObject->getWorldTransform().getOrigin());
	_targetPosition = BulletCast<btVector3>(_position);
}

void CharacterController::playerStep(btCollisionWorld* collisionWorld, btScalar dt)
{
	// accelerate by gravity
	const float gravity = 1.0f;
	_verticalVelocity -= gravity * dt;

	// todo: cap _verticalVelocity at something sane like 3.0f

	_verticalOffset = _verticalVelocity * dt;

	btTransform transform = _physGhostObject->getWorldTransform();

	stepUp(collisionWorld);

	btVector3 walkVelocity = BulletCast<btVector3>(_walkDirection) * dt;
	stepForwardAndStrafe(collisionWorld, walkVelocity);

	// stepUp()
	// stepForwardAndStrafe()
	stepDown(collisionWorld, dt);

	_position = BulletCast<glm::vec3>(_targetPosition);
	transform.setOrigin(BulletCast<btVector3>(_position));
	_physGhostObject->setWorldTransform(transform);
	_character->SetPosition(_position);
}

bool CharacterController::canJump() const
{
	return false;
}

void CharacterController::jump(const btVector3& dir)
{
}

bool CharacterController::onGround() const
{
	return false;
}

void CharacterController::setUpInterpolate(bool)
{
}

class btKinematicClosestNotMeConvexResultCallback: public btCollisionWorld::ClosestConvexResultCallback
{
  public:
	btKinematicClosestNotMeConvexResultCallback(btCollisionObject* me, const btVector3& up, btScalar minSlopeDot):
	    btCollisionWorld::ClosestConvexResultCallback(btVector3(0.0, 0.0, 0.0), btVector3(0.0, 0.0, 0.0)), m_me(me), m_up(up), m_minSlopeDot(minSlopeDot)
	{
	}

	virtual btScalar addSingleResult(btCollisionWorld::LocalConvexResult& convexResult, bool normalInWorldSpace)
	{
		if (convexResult.m_hitCollisionObject == m_me)
			return btScalar(1.0);

		if (!convexResult.m_hitCollisionObject->hasContactResponse())
			return btScalar(1.0);

		btVector3 hitNormalWorld;
		if (normalInWorldSpace)
		{
			hitNormalWorld = convexResult.m_hitNormalLocal;
		}
		else
		{
			///need to transform normal into worldspace
			hitNormalWorld = convexResult.m_hitCollisionObject->getWorldTransform().getBasis() * convexResult.m_hitNormalLocal;
		}

		btScalar dotUp = m_up.dot(hitNormalWorld);
		if (dotUp < m_minSlopeDot)
		{
			return btScalar(1.0);
		}

		return ClosestConvexResultCallback::addSingleResult(convexResult, normalInWorldSpace);
	}

  protected:
	btCollisionObject* m_me;
	const btVector3 m_up;
	btScalar m_minSlopeDot;
};

bool CharacterController::recoverFromPenetration(btCollisionWorld* collisionWorld)
{
	btVector3 minAabb, maxAabb;

	_physShape->getAabb(_physGhostObject->getWorldTransform(), minAabb, maxAabb);
	collisionWorld->getBroadphase()->setAabb(_physGhostObject->getBroadphaseHandle(),
	                                         minAabb,
	                                         maxAabb,
	                                         collisionWorld->getDispatcher());

	bool penetration = false;

	collisionWorld->getDispatcher()->dispatchAllCollisionPairs(
	    _physGhostObject->getOverlappingPairCache(),
	    collisionWorld->getDispatchInfo(),
	    collisionWorld->getDispatcher());

	_position = BulletCast<glm::vec3>(_physGhostObject->getWorldTransform().getOrigin());

	btScalar maxPenetration = 0.0;

	int overlappingPairs = _physGhostObject->getOverlappingPairCache()->getNumOverlappingPairs();
	for (int i = 0; i < overlappingPairs; i++)
	{
		_manifoldArray.resize(0);

		btBroadphasePair* collisionPair =
		    &_physGhostObject->getOverlappingPairCache()->getOverlappingPairArray()[i];

		// Does the other object respone?
		if (!((btCollisionObject*)collisionPair->m_pProxy0->m_clientObject)->hasContactResponse() ||
		    !((btCollisionObject*)collisionPair->m_pProxy1->m_clientObject)->hasContactResponse())
			continue;

		if (collisionPair->m_algorithm)
			collisionPair->m_algorithm->getAllContactManifolds(_manifoldArray);

		int manifoldArraySize = _manifoldArray.size();
		for (int j = 0; j < manifoldArraySize; j++)
		{
			btPersistentManifold* manifold = _manifoldArray[j];
			btScalar directionSign         = (manifold->getBody0() == _physGhostObject.get()) ? -1.0 : 1.0;

			int numContacts = manifold->getNumContacts();
			for (int k = 0; k < numContacts; k++)
			{
				const btManifoldPoint& pt = manifold->getContactPoint(k);

				btScalar dist = pt.getDistance();

				// if (dist < btScalar(0.0))
				if (fabs(dist) > 0.2 /* m_addedMargin */)
				{
					if (dist < maxPenetration)
					{
						maxPenetration  = dist;
						_touchingNormal = pt.m_normalWorldOnB * directionSign;
					}

					_position += BulletCast<glm::vec3>(pt.m_normalWorldOnB * directionSign * dist * 0.2);
					penetration = true;
				}
			}
		}
	}

	btTransform newTransform = _physGhostObject->getWorldTransform();
	newTransform.setOrigin(BulletCast<btVector3>(_position));
	_physGhostObject->setWorldTransform(newTransform);

	return penetration;
}

btVector3 CharacterController::computeReflectionDirection(const btVector3& direction, const btVector3& normal)
{
	return direction - (btScalar(2.0) * direction.dot(normal)) * normal;
}

btVector3 CharacterController::parallelComponent(const btVector3& direction, const btVector3& normal)
{
	btScalar magnitude = direction.dot(normal);
	return normal * magnitude;
}

btVector3 CharacterController::perpendicularComponent(const btVector3& direction, const btVector3& normal)
{
	return direction - parallelComponent(direction, normal);
}

void CharacterController::stepUp(btCollisionWorld* world)
{
	btTransform start, end;
	_targetPosition = BulletCast<btVector3>(_position + glm::vec3(0.0f, 1.0f, 0.0f) * _stepHeight);
	_position       = BulletCast<glm::vec3>(_targetPosition);
}

void CharacterController::updateTargetPositionBasedOnCollision(const btVector3& hitNormal,
                                                               btScalar tangentMag,
                                                               btScalar normalMag)
{
	btVector3 movementDirection = _targetPosition - BulletCast<btVector3>(_position);
	btScalar movementLength     = movementDirection.length();

	if (movementLength > SIMD_EPSILON)
	{
		movementDirection.normalize();

		btVector3 reflectDir = computeReflectionDirection(movementDirection, hitNormal);
		reflectDir.normalize();

		btVector3 parallelDir, perpendicularDir;

		parallelDir      = parallelComponent(reflectDir, hitNormal);
		perpendicularDir = perpendicularComponent(reflectDir, hitNormal);

		_targetPosition = BulletCast<btVector3>(_position);

		if (normalMag)
		{
			btVector3 perpComponent = perpendicularDir * btScalar(normalMag * movementLength);
			// printf("perpComponent: "); debugvec(perpComponent);
			perpComponent.setY(0);

			_targetPosition += perpComponent;
		}
	}
}

void CharacterController::stepForwardAndStrafe(btCollisionWorld* collsionWorld, const btVector3& walkMove)
{
	if (walkMove.isZero())
		return;

	_targetPosition = BulletCast<btVector3>(_position) + walkMove;

	// Check for any contacts and run updateTargetPositionBasedOnCollision if any
	int overlappingPairs = _physGhostObject->getOverlappingPairCache()->getNumOverlappingPairs();
	for (int i = 0; i < overlappingPairs; i++)
	{
		_manifoldArray.resize(0);

		btBroadphasePair* collisionPair =
		    &_physGhostObject->getOverlappingPairCache()->getOverlappingPairArray()[i];

		if (collisionPair->m_algorithm)
			collisionPair->m_algorithm->getAllContactManifolds(_manifoldArray);

		int manifoldArraySize = _manifoldArray.size();
		for (int j = 0; j < manifoldArraySize; j++)
		{
			btPersistentManifold* manifold = _manifoldArray[j];
			btScalar directionSign         = (manifold->getBody0() == _physGhostObject.get()) ? -1.0 : 1.0;

			int numContacts = manifold->getNumContacts();
			for (int k = 0; k < numContacts; k++)
			{
				const btManifoldPoint& pt = manifold->getContactPoint(k);

				btScalar dist = pt.getDistance();

				if (dist < 0)
				{
					btVector3 hitNormal = pt.m_normalWorldOnB * directionSign;

					// Determine if our desired walk direction is facing the hit normal.
					if (hitNormal.dot(walkMove.normalized()) >= 0)
						updateTargetPositionBasedOnCollision(hitNormal);
				}
			}
		}
	}
}

/* downward movement */
void CharacterController::stepDown(btCollisionWorld* collisionWorld, btScalar dt)
{
	btTransform start, end;
	btVector3 origPosition = BulletCast<btVector3>(_position);

	// going up
	if (_verticalVelocity > 0.0)
		return;

	// todo: cap downVelocity
	btScalar downVelocity = (_verticalVelocity < 0.0 ? -_verticalVelocity : 0.0) * dt;

	if (downVelocity > 0.0 && downVelocity < _stepHeight)
		downVelocity = _stepHeight;

	_targetPosition -= btVector3(0.0, downVelocity, 0.0);

	btKinematicClosestNotMeConvexResultCallback callback(_physGhostObject.get(), btVector3(0.0, 1.0, 0.0), btCos(btRadians(45.0)));
	callback.m_collisionFilterGroup = _physGhostObject->getBroadphaseHandle()->m_collisionFilterGroup;
	callback.m_collisionFilterMask  = _physGhostObject->getBroadphaseHandle()->m_collisionFilterMask;

	start.setIdentity();
	end.setIdentity();

	start.setOrigin(origPosition);
	end.setOrigin(_targetPosition);

	// this doesn't work TWAT:
	//_physGhostObject->convexSweepTest(_physShape.get(), start, end, callback, collisionWorld->getDispatchInfo().m_allowedCcdPenetration);
	collisionWorld->convexSweepTest(_physShape.get(), start, end, callback, collisionWorld->getDispatchInfo().m_allowedCcdPenetration);

	if (callback.hasHit())
	{
		_targetPosition.setInterpolate3(origPosition, _targetPosition, callback.m_closestHitFraction);

		_verticalVelocity = 0;
		_verticalOffset   = 0;
	}
}

} // namespace Donut
