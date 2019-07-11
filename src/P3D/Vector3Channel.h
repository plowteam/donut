#pragma once

#include <memory>
#include <string>
#include <vector>
#include <glm/mat4x4.hpp>
#include <MemoryStream.h>
#include "AnimChannel.h"

namespace Donut::P3D {

class Vector3Channel : AnimChannel {
public:
	Vector3Channel() {}
	virtual void Read(MemoryStream& stream) override;

	uint32_t GetNumFrames() { return _numberOfFrames; }
private:
	uint32_t _numberOfFrames;
	std::vector<glm::vec3> _values;
	std::vector<uint16_t> _frames;
};

} // namespace Donut::P3D
