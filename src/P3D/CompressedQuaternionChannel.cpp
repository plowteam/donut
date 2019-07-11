#include <MemoryStream.h>
#include <P3D/CompressedQuaternionChannel.h>
#include <iostream>

namespace Donut::P3D
{

void CompressedQuaternionChannel::Read(MemoryStream& stream)
{
	AnimChannel::Read(stream);

	_numberOfFrames = stream.Read<uint32_t>();

	_frames.resize(_numberOfFrames);
	stream.ReadBytes(reinterpret_cast<uint8_t*>(_frames.data()), _numberOfFrames * sizeof(uint16_t));

	_values.resize(_numberOfFrames);
	for (uint32_t i = 0; i < _numberOfFrames; ++i)
	{
		float w = (float)stream.Read<int16_t>() / (float)SHRT_MAX;
		float x = (float)stream.Read<int16_t>() / (float)SHRT_MAX;
		float y = (float)stream.Read<int16_t>() / (float)SHRT_MAX;
		float z = (float)stream.Read<int16_t>() / (float)SHRT_MAX;

		_values[i] = glm::vec4(x, y, z, w);
	}
}
} // namespace Donut::P3D
