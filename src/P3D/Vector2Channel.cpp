#include <P3D/Vector2Channel.h>
#include <MemoryStream.h>
#include <iostream>

namespace Donut::P3D {

	void Vector2Channel::Read(MemoryStream& stream)
	{
		AnimChannel::Read(stream);

	}
} // namespace Donut::P3D
