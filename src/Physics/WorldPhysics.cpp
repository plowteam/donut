// Copyright 2019 the donut authors. See AUTHORS.md

#include <P3D/P3D.generated.h>
#include <Physics/BulletCast.h>
#include <Physics/BulletDebugDraw.h>
#include <Physics/WorldPhysics.h>

#include <BulletCollision/CollisionShapes/btBox2dShape.h>
#include <Physics/BulletFenceShape.h>

#include <glm/gtx/quaternion.hpp>

namespace Donut
{
WorldPhysics::WorldPhysics(LineRenderer* lineRenderer)
{
	_collisionConfiguration = new btDefaultCollisionConfiguration();
	_collisionDispatcher    = new btCollisionDispatcher(_collisionConfiguration);
	_broadphase             = new btDbvtBroadphase();
	_constraintSolver       = new btSequentialImpulseConstraintSolver();

	_dynamicsWorld = new btDiscreteDynamicsWorld(_collisionDispatcher, _broadphase, _constraintSolver, _collisionConfiguration);

	_debugDraw = std::make_unique<BulletDebugDraw>(lineRenderer);
	_debugDraw->setDebugMode(btIDebugDraw::DBG_NoDebug);

	_dynamicsWorld->setDebugDrawer(_debugDraw.get());
	_dynamicsWorld->setGravity(btVector3(0.0f, -1.0f, 0.0f));

	// _char = std::make_unique<CharacterController>(this, glm::vec3(glm::vec3(229.0f, 4.5f, -182.0f)));
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

	for (auto i = 0; i < _allocatedVertexArrays.size(); i++)
		delete _allocatedVertexArrays[i];

	_allocatedVertexArrays.clear();

	for (auto i = 0; i < _allocatedIndexArrays.size(); i++)
		delete _allocatedIndexArrays[i];

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

void WorldPhysics::AddIntersect(const P3D::Intersect& intersect)
{
	// copy this shit over first (todo: free it?)
	auto verts   = new std::vector<glm::vec3>(intersect.GetPositions());
	auto indices = new std::vector<uint32_t>(intersect.GetIndices());

	btIndexedMesh indexedMesh;
	indexedMesh.m_vertexBase          = reinterpret_cast<const unsigned char*>(verts->data());
	indexedMesh.m_vertexStride        = sizeof(glm::vec3);
	indexedMesh.m_numVertices         = (int)verts->size();
	indexedMesh.m_triangleIndexBase   = reinterpret_cast<const unsigned char*>(indices->data());
	indexedMesh.m_triangleIndexStride = sizeof(uint32_t) * 3;
	indexedMesh.m_numTriangles        = (int)indices->size() / 3;

	auto meshInterface = new btTriangleIndexVertexArray();
	meshInterface->addIndexedMesh(indexedMesh, PHY_INTEGER);

	auto trimeshShape = new btBvhTriangleMeshShape(meshInterface, true);

	auto colObj = new btCollisionObject();
	colObj->setCollisionShape(trimeshShape);

	_dynamicsWorld->addCollisionObject(colObj);

	// add for cleanup
	_allocatedCollisionObjects.push_back(colObj);
	_allocatedVertexArrays.push_back(verts);
	_allocatedIndexArrays.push_back(indices);
}

void WorldPhysics::AddCollisionVolume(const P3D::CollisionVolume& volume)
{
	// process subvolumes
	if (volume.GetNumSubVolumes() > 0)
	{
		for (auto const& subvolume : volume.GetSubVolumes())
			AddCollisionVolume(*subvolume);

		// if it has sub volumes it probably doesn't have an actual volume so just return
		return;
	}

	// process volume
	auto const& obbox  = volume.GetObBox();
	auto const& sphere = volume.GetSphere();
	auto const& cylinder = volume.GetCylinder();

	if (obbox != nullptr)
		AddP3DOBBoxVolume(*obbox);
	else if (sphere != nullptr)
		AddP3DSphere(*sphere);
	else if (cylinder != nullptr)
		AddP3DCylinder(*cylinder);

}

void WorldPhysics::AddP3DOBBoxVolume(const P3D::CollisionOBBoxVolume& volume)
{
	const auto centre = volume.GetVectors()[0];
	const auto rotX   = volume.GetVectors()[1];
	const auto rotY   = volume.GetVectors()[2];
	const auto rotZ   = volume.GetVectors()[3];

	const glm::quat rotation = glm::toQuat(glm::mat3(
	    rotX.x, rotX.y, rotX.z,
	    rotY.x, rotY.y, rotY.z,
	    rotZ.x, rotZ.y, rotZ.z));

	const auto he          = volume.GetHalfExtents();
	const auto bulletShape = new btBoxShape(BulletCast<btVector3>(volume.GetHalfExtents()));

	btTransform worldTransform;
	worldTransform.setIdentity();
	worldTransform.setOrigin(BulletCast<btVector3>(centre));
	worldTransform.setRotation(BulletCast<btQuaternion>(rotation));

	auto colObj = new btCollisionObject();
	colObj->setCollisionShape(bulletShape);
	colObj->setWorldTransform(worldTransform);

	_dynamicsWorld->addCollisionObject(colObj);

	_allocatedCollisionObjects.push_back(colObj);
}

void WorldPhysics::AddP3DSphere(const P3D::CollisionSphere& sphere)
{
	const auto bulletSphere = new btSphereShape(sphere.GetRadius());

	btTransform worldTransform;
	worldTransform.setIdentity();
	worldTransform.setOrigin(BulletCast<btVector3>(sphere.GetVectors()[0]));

	auto colObj = new btCollisionObject();
	colObj->setCollisionShape(bulletSphere);
	colObj->setWorldTransform(worldTransform);

	_dynamicsWorld->addCollisionObject(colObj);

	_allocatedCollisionObjects.push_back(colObj);
}

void WorldPhysics::AddP3DCylinder(const P3D::CollisionCylinder& cylinder)
{
	const float radius = cylinder.GetRadius();
	const float halfLength = cylinder.GetLength();
	const glm::quat rotation = glm::rotation(glm::vec3(0.0f, 1.0f, 0.0f), cylinder.GetVectors()[1]);

	btConvexShape* shape = nullptr;
	if (cylinder.GetFlatEnd() == 1)
		shape = new btCylinderShape(btVector3(radius, halfLength, radius));
	else
		shape = new btCapsuleShape(radius, halfLength * 2);

	btTransform worldTransform;
	worldTransform.setIdentity();
	worldTransform.setOrigin(BulletCast<btVector3>(cylinder.GetVectors()[0]));
	worldTransform.setRotation(BulletCast<btQuaternion>(rotation));

	auto colObj = new btCollisionObject();
	colObj->setCollisionShape(shape);
	colObj->setWorldTransform(worldTransform);

	_dynamicsWorld->addCollisionObject(colObj);

	_allocatedCollisionObjects.push_back(colObj);
}

void WorldPhysics::AddP3DFence(const P3D::Fence& fence)
{
	glm::vec3 start = fence.GetStart();
	glm::vec3 end   = fence.GetEnd();
	glm::vec3 normal      = fence.GetNormal();
	glm::vec3 center = end + (start - end)*0.5f;

	const float length = glm::distance(start, end);
	const glm::quat rotation = glm::rotation(glm::vec3(0.0f, 0.0f, 1.0f), normal);

	// tall box, very little thickness, might turn into a plane if possible
	const btVector3 boxHalfExtents(length / 2, 50.0f, .0125f);

	auto box = new btBoxShape(boxHalfExtents);
	const float angle = atan2f(normal.x, normal.z);

	btTransform worldTransform;
	worldTransform.setIdentity();
	worldTransform.setOrigin(BulletCast<btVector3>(center));
	worldTransform.setRotation(BulletCast<btQuaternion>(rotation));

	auto colObj = new btCollisionObject();
	colObj->setCollisionShape(box);
	colObj->setWorldTransform(worldTransform);

	_dynamicsWorld->addCollisionObject(colObj);

	_allocatedCollisionObjects.push_back(colObj);
}

} // namespace Donut
