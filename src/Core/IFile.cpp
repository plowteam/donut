// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "IFile.h"

namespace Donut
{

std::size_t IFile::GetSize()
{
	std::size_t current = GetPosition();
	Seek(0, SeekOrigin::End);
	std::size_t size = GetPosition();
	Seek(current, SeekOrigin::Begin);
	return size;
}

std::string IFile::ReadString(std::size_t length)
{
	char* str = new char[length];
	Read(reinterpret_cast<uint8_t*>(str), length);

	// Bullshit null terminate
	uint32_t l = 0;
	for (; l < length; ++l)
	{
		if (str[l] == 0)
			break;
	}

	std::string ret(str, l);
	delete[] str;

	return ret;
}

std::string IFile::ReadU8String()
{
	uint8_t length;
	Read(&length, 1);
	return (length == 0) ? std::string() : ReadString(length);
}

} // namespace Donut
