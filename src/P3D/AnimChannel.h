#pragma once

#include <Core/MemoryStream.h>
#include <string>

namespace Donut::P3D
{

class AnimChannel
{
  public:
	AnimChannel() {}
	virtual void Read(MemoryStream& stream);

  protected:
	uint32_t _version;
	std::string _parameter;
};

} // namespace Donut::P3D
