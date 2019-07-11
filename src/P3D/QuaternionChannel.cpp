#include <P3D/QuaternionChannel.h>
#include <MemoryStream.h>
#include <iostream>

namespace Donut::P3D {

	void QuaternionChannel::Read(MemoryStream& stream)
	{
		AnimChannel::Read(stream);

	}
} // namespace Donut::P3D
