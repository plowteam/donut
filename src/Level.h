#pragma once

#include <Render/OpenGL/ShaderProgram.h>

#include <P3D/Intersect.h>
#include <ResourceManager.h>
#include <Render/StaticEntity.h>
#include <Render/WorldSphere.h>
#include <glm/glm.hpp>
#include <map>
#include <string>
#include <vector>

#include <BulletCollision/CollisionDispatch/btCollisionWorld.h>
#include <BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h>

namespace Donut
{

class Level
{
public:
	Level();

	void Draw(const ResourceManager&, glm::mat4& viewProj);
	void LoadP3D(const std::string& filename);

	std::vector<std::unique_ptr<P3D::Intersect>>& GetIntersects() { return _intersects; }

private:
	std::unique_ptr<ResourceManager> _resourceManager;
    std::unique_ptr<WorldSphere> _worldSphere;
	std::vector<std::unique_ptr<StaticEntity>> _staticEntities;
	std::vector<std::unique_ptr<P3D::Intersect>> _intersects;
	std::unique_ptr<GL::ShaderProgram> _worldShader;

	// physics (move to another class after poc)
	std::unique_ptr<btCollisionWorld> _collisionWorld;
	std::unique_ptr<btDefaultCollisionConfiguration> _collisionConfiguration;
	std::unique_ptr<btCollisionDispatcher> _collisionDispatcher;
	std::unique_ptr<btBroadphaseInterface> _broadphase;
};

} // namespace Donut
