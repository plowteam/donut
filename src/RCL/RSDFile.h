// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <Core/MemoryStream.h>
#include <vector>

namespace Donut::RCL
{
class RSDFile
{
public:
	RSDFile(MemoryStream& stream);

	uint32_t GetNumChannels() const { return _numChannels; }
	uint32_t GetBitsPerChannel() const { return _bitsPerChannel; }
	uint32_t GetSampleRate() const { return _sampleRate; }
	const std::vector<std::byte>& GetData() const { return _data; }

private:
	uint32_t _numChannels;
	uint32_t _bitsPerChannel;
	uint32_t _sampleRate;
	std::vector<std::byte> _data;
};
} // namespace Donut::RCL
