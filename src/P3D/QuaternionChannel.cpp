#include <MemoryStream.h>
#include <P3D/QuaternionChannel.h>
#include <iostream>

namespace Donut::P3D
{

void QuaternionChannel::Read(MemoryStream& stream)
{
	AnimChannel::Read(stream);

	_numberOfFrames = stream.Read<uint32_t>();

	_frames.resize(_numberOfFrames);
	stream.ReadBytes(reinterpret_cast<uint8_t*>(_frames.data()), _numberOfFrames * sizeof(uint16_t));

	_values.resize(_numberOfFrames);
	for (uint32_t i = 0; i < _numberOfFrames; ++i)
	{
		float w = stream.Read<float>();
		float x = stream.Read<float>();
		float y = stream.Read<float>();
		float z = stream.Read<float>();

		_values[i] = glm::quat(w, x, y, z);
	}
}
} // namespace Donut::P3D
