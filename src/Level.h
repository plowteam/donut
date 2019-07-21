#pragma once

#include <glm/glm.hpp>
#include <string>
#include <memory>
#include <vector>

#include <Render/StaticEntity.h>
#include <Render/WorldSphere.h>
#include <Render/CompositeModel.h>

namespace Donut
{

namespace GL
{
class ShaderProgram;
}

class ResourceManager;
class WorldPhysics;


class Level
{
public:
	Level(WorldPhysics*);

	void Draw(const ResourceManager&, glm::mat4& viewProj);
	void LoadP3D(const std::string& filename);
private:
	WorldPhysics* _worldPhysics;

	std::unique_ptr<ResourceManager> _resourceManager;
    std::unique_ptr<WorldSphere> _worldSphere;
	std::vector<std::unique_ptr<StaticEntity>> _staticEntities;
	std::unique_ptr<GL::ShaderProgram> _worldShader;

	std::vector<std::unique_ptr<CompositeModel>> _cars;
};

} // namespace Donut
