#pragma once

#include "AnimChannel.h"

#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <memory>
#include <string>
#include <vector>

namespace Donut::P3D
{

class QuaternionChannel: AnimChannel
{
  public:
	QuaternionChannel() {}
	virtual void Read(MemoryStream& stream) override;

	uint32_t GetNumFrames() { return _numberOfFrames; }
	std::vector<glm::vec4>& GetValues() { return _values; }
	std::vector<uint16_t>& GetFrames() { return _frames; }

  private:
	uint32_t _numberOfFrames;
	std::vector<glm::vec4> _values;
	std::vector<uint16_t> _frames;
};

} // namespace Donut::P3D
