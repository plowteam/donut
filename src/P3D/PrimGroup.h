#pragma once

#include <P3D/P3DChunk.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

namespace Donut::P3D
{

class PrimGroup
{
  public:
	enum class PrimitiveType : uint32_t
	{
		TriangleList,
		TriangleStrip,
		LineList,
		LineStrip,
	};

	enum class HasData : uint32_t
	{
		UV     = 1 << 0,
		UV2    = 1 << 1,
		UV3    = 1 << 2,
		UV4    = 1 << 3,
		Normal = 1 << 4,
		Color  = 1 << 5,
		// Unknown = 1 << 6,
		Matrix = 1 << 7,
		Weight = 1 << 8,
	};

	PrimGroup(const std::string& shader, PrimGroup::PrimitiveType type):
	    _shaderName(shader), _primType(type) {}

	static std::unique_ptr<PrimGroup> Load(const P3DChunk&);

	const std::string& GetShaderName() { return _shaderName; }
	PrimGroup::PrimitiveType GetPrimitiveType() { return _primType; }
	std::vector<glm::vec3>& GetVerticies() { return _verticies; }
	std::vector<uint32_t>& GetIndices() { return _indices; }
	std::vector<glm::vec3>& GetNormals() { return _normals; }
	std::vector<glm::vec2>& GetUV() { return _uvs; }
	std::vector<glm::vec3>& GetWeights() { return _weights; }
	std::vector<uint32_t>& GetColors() { return _colors; }
	std::vector<uint8_t>& GetMatrixList() { return _matrixList; }
	std::vector<uint32_t>& GetMatrixPalette() { return _matrixPalette; }

  private:
	std::string _shaderName;
	PrimGroup::PrimitiveType _primType;
	std::vector<glm::vec3> _verticies;
	std::vector<uint32_t> _indices;
	std::vector<glm::vec3> _normals;
	std::vector<glm::vec2> _uvs;
	std::vector<glm::vec3> _weights;
	std::vector<uint32_t> _colors;
	std::vector<uint8_t> _matrixList;
	std::vector<uint32_t> _matrixPalette;
};

} // namespace Donut::P3D
