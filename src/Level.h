// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

#include <glm/glm.hpp>
#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

#include <Render/WorldSphere.h>
#include <Render/CompositeModel.h>
#include <Render/BillboardBatch.h>
#include <Entity.h>

namespace Donut
{

namespace GL
{
class ShaderProgram;
}

class ResourceManager;
class LineRenderer;

class Level
{
public:
	Level();

	void Update(double deltatime);
	void Draw(glm::mat4& viewProj);
	void LoadP3D(const std::string& filename);

	void DynaLoadData(const std::string& dynaLoadData);

	void ImGuiDebugWindow(bool* p_open) const;

  private:
	void loadRegion(const std::string& filename);
	void unloadRegion(const std::string& filename);

    std::unique_ptr<WorldSphere> _worldSphere;
	std::vector<std::unique_ptr<Entity>> _entities;
	std::vector<std::unique_ptr<Entity>> _instances;
	std::vector<std::unique_ptr<BillboardBatch>> _billboardBatches;
	std::unique_ptr<GL::ShaderProgram> _worldShader;
	std::unique_ptr<GL::ShaderProgram> _worldInstancedShader;
	std::unique_ptr<GL::ShaderProgram> _billboardBatchShader;

	std::vector<std::unique_ptr<CompositeModel>> _compositeModels;

	class Path
	{
	public:

		std::vector<glm::vec3> points;
	};

	std::vector<Path> _paths;
	std::unique_ptr<LineRenderer> _lineRenderer;
};

} // namespace Donut
