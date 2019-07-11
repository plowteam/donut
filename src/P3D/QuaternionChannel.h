#pragma once

#include <memory>
#include <string>
#include <vector>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include "AnimChannel.h"

namespace Donut::P3D {

class QuaternionChannel : AnimChannel {
public:
	QuaternionChannel() {}
	virtual void Read(MemoryStream& stream) override;

	uint32_t GetNumFrames() { return _numberOfFrames; }
private:
	uint32_t _numberOfFrames;
	std::vector<glm::vec4> _values;
	std::vector<uint16_t> _frames;
};

} // namespace Donut::P3D
