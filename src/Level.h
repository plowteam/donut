// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Fwd.h"

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace Donut
{

namespace GL
{
class ShaderProgram;
}

class BillboardBatch;
class CompositeModel;
class LineRenderer;
class Entity;
class ResourceManager;
class WorldSphere;

class Level
{
public:
	Level();
	~Level();

	void Update(double deltatime);
	void Draw(Matrix4x4& viewProj);
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
		std::vector<Vector3> points;
	};

	std::vector<Path> _paths;
};

} // namespace Donut
