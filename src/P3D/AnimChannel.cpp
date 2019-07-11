#include <P3D/AnimChannel.h>
#include <iostream>

namespace Donut::P3D {

	void AnimChannel::Read(MemoryStream& stream)
	{
		_version = stream.Read<std::uint32_t>();

		uint8_t parameter[4];
		stream.ReadBytes(parameter, 4);
		_parameter = std::string(reinterpret_cast<char*>(parameter), 4);
	}
} // namespace Donut::P3D
