#pragma once

#include <cassert>
#include <cstdio>
#include <string>
#include <vector>

namespace Donut {

enum class SeekMode { Begin = SEEK_SET, Current = SEEK_CUR, End = SEEK_END };

class MemoryStream {
public:
	MemoryStream(const std::vector<std::uint8_t>&);
    // MemoryStream(std::uint8_t* data, std::size_t);

	void Read(void* dest, std::size_t length);

    void Seek(std::size_t position, SeekMode mode);
    std::size_t Position() { return std::distance(_data.begin(), _position); }
    // std::size_t Size() const;

protected:
	std::vector<std::uint8_t> _data;
	std::vector<std::uint8_t>::iterator _position;
};

} // namespace Donut
