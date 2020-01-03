// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <string>
#include <vector>

namespace Donut
{

enum class SeekMode
{
	Begin = SEEK_SET,
	Current = SEEK_CUR,
	End = SEEK_END
};

class MemoryStream
{
public:
	MemoryStream(const std::vector<uint8_t>&);
	// MemoryStream(uint8_t* data, std::size_t);

	void ReadBytes(uint8_t* dest, std::size_t length);

	template <typename T>
	T Read()
	{
		uint8_t* ptr = &(*_position); // this looks like shit v
		T ret = *reinterpret_cast<T*>(ptr);
		std::advance(_position, sizeof(T));
		return ret;
	}

	std::string ReadString(std::size_t length);
	std::string ReadLPString();

	void Seek(std::size_t position, SeekMode mode);
	std::size_t Position() { return std::distance(_data.begin(), _position); }
	std::size_t Size() const { return _data.size(); }
	bool End() const { return _position == _data.end(); }

protected:
	std::vector<uint8_t> _data;
	std::vector<uint8_t>::iterator _position;
};

} // namespace Donut
