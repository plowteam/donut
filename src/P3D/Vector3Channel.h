#pragma once

#include "AnimChannel.h"

#include <MemoryStream.h>
#include <glm/mat4x4.hpp>
#include <memory>
#include <string>
#include <vector>

namespace Donut::P3D
{

class Vector3Channel: AnimChannel
{
  public:
	Vector3Channel() {}
	virtual void Read(MemoryStream& stream) override;

	uint32_t GetNumFrames() { return _numberOfFrames; }
	std::vector<glm::vec3>& GetValues() { return _values; }
	std::vector<uint16_t>& GetFrames() { return _frames; }

  private:
	uint32_t _numberOfFrames;
	std::vector<glm::vec3> _values;
	std::vector<uint16_t> _frames;
};

} // namespace Donut::P3D
