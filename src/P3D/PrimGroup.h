#pragma once

#include <string>
#include <glm/vec3.hpp>

namespace Donut::P3D {

class PrimGroup {
public:
	enum class PrimitiveType : std::uint32_t {
		TriangleList,
		TriangleStrip,
		LineList,
		LineStrip,
	};

	enum class HasData : std::uint32_t {
		UV = 1 << 0,
		UV2 = 1 << 1,
		UV3 = 1 << 2,
		UV4 = 1 << 3,
		Normal = 1 << 4,
		Color = 1 << 5,
		// Unknown = 1 << 6,
		Matrix = 1 << 7,
		Weight = 1 << 8,
	};

    PrimGroup(const std::string& shader, PrimGroup::PrimitiveType type)
        : _shaderName(shader), _primType(type) {}

	const std::string& GetShaderName() { return _shaderName; }
    PrimGroup::PrimitiveType GetPrimitiveType() { return _primType; }
	std::vector<glm::vec3>& GetVerticies() { return _verticies; }
	std::vector<uint32_t>& GetIndices() { return _indices; }
	std::vector<glm::vec3>& GetNormals() { return _normals; }

private:
    std::string _shaderName;
    PrimGroup::PrimitiveType _primType; 
    std::vector<glm::vec3> _verticies;
    std::vector<uint32_t> _indices;
    std::vector<glm::vec3> _normals;
};

} // namespace Donut::P3D
