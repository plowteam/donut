#include <P3D/CompressedQuaternionChannel.h>
#include <MemoryStream.h>
#include <iostream>

namespace Donut::P3D {

	void CompressedQuaternionChannel::Read(MemoryStream& stream)
	{
		AnimChannel::Read(stream);

	}
} // namespace Donut::P3D
