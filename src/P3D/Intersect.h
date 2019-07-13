#pragma once

#include <P3D/P3DChunk.h>
#include <memory>
#include <glm/vec3.hpp>
#include <AABB.h>

namespace Donut::P3D
{
class Intersect
{
public:
	Intersect(std::vector<glm::vec3> positions, std::vector<uint32_t> indices, std::vector<glm::vec3> normals, AABB aabb):
	  _positions(std::move(positions)), _indices(std::move(indices)), _normals(std::move(normals)), _aabb(aabb)
	{
	}

	static std::unique_ptr<Intersect> Load(const P3DChunk&);

	const std::vector<glm::vec3>& GetPositions() const { return _positions; }
	const std::vector<uint32_t>& GetIndices() const { return _indices; }
	const std::vector<glm::vec3>& GetNormals() const { return _normals; }
	const AABB& GetAABB() const { return _aabb; }

private:
	std::vector<glm::vec3> _positions;
	std::vector<uint32_t> _indices;
	std::vector<glm::vec3> _normals;
	AABB _aabb;
};
} // namespace Donut::P3D
