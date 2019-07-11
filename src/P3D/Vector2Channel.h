#pragma once

#include <memory>
#include <string>
#include <vector>
#include <glm/mat4x4.hpp>

namespace Donut::P3D {

class Vector2Channel {
public:
	Vector2Channel() {}
private:
	uint32_t _version;
	uint32_t _numberOfFrames;
	uint16_t _mapping;
	std::string _parameter;
	std::vector<glm::vec2> _values;
	std::vector<uint16_t> _frames;
	glm::vec3 _constants;
};

} // namespace Donut::P3D
