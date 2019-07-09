#include <MemoryStream.h>
#include <cstring>

namespace Donut {

MemoryStream::MemoryStream(const std::vector<std::uint8_t>& data)
{
	_data = data;
	_position = _data.begin();
}

void MemoryStream::Read(void* dest, std::size_t length)
{
	// check cur + length doesn't exceed size

	// copy the data
	std::memcpy(dest, &(*_position), length);

	// advance our current position iterator
	std::advance(_position, length);
}

void MemoryStream::Seek(std::size_t position, SeekMode mode)
{
	switch (mode) {
		case SeekMode::Begin:
		_position = std::next(_data.begin(), position);
		break;
		case SeekMode::Current:
		std::advance(_position, position);
		break;
		case SeekMode::End:
		_position = std::next(_data.end(), -position);
		break;
	}
}


}
