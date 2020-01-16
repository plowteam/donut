// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "RSDFile.h"

#include <array>
#include <fmt/format.h>
#include <iostream>

namespace Donut::RCL
{
std::array<int, 16> indexTable = {-1, -1, -1, -1, 2, 4, 6, 8, -1, -1, -1, -1, 2, 4, 6, 8};
std::array<int, 89> stepTable = {
    7,    8,    9,    10,   11,    12,    13,    14,    16,    17,    19,    21,    23,    25,    28,    31,    34,   37,
    41,   45,   50,   55,   60,    66,    73,    80,    88,    97,    107,   118,   130,   143,   157,   173,   190,  209,
    230,  253,  279,  307,  337,   371,   408,   449,   494,   544,   598,   658,   724,   796,   876,   963,   1060, 1166,
    1282, 1411, 1552, 1707, 1878,  2066,  2272,  2499,  2749,  3024,  3327,  3660,  4026,  4428,  4871,  5358,  5894, 6484,
    7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899, 15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767};

static void DecodeNibble(int32_t nibble, int32_t& nibbleDecoded, int32_t& stepIndex)
{
	int32_t step = stepTable[stepIndex];
	int32_t delta = step >> 3;
	if (nibble & 1)
		delta += step >> 2;
	if (nibble & 2)
		delta += step >> 1;
	if (nibble & 4)
		delta += step;
	if (nibble & 8)
		delta = -delta;

	nibbleDecoded += delta;
	if (nibbleDecoded > 32767)
		nibbleDecoded = 32767;
	else if (nibbleDecoded < -32768)
		nibbleDecoded = -32768;

	stepIndex += indexTable[nibble];
	if (stepIndex < 0)
		stepIndex = 0;
	else if (stepIndex > 88)
		stepIndex = 88;
}

static void DecodeRADP(MemoryStream& stream, int16_t* outBuffer, int32_t numBlocks, int32_t numChannels)
{
	const size_t blockSize = numChannels * 20;
	const size_t numBlockSamples = 32;
	size_t offset = 0x800;
	size_t firstSample = 0;

	for (size_t block = 0; block < numBlocks; ++block, firstSample += numBlockSamples)
	{
		for (size_t channel = 0; channel < numChannels; ++channel)
		{
			stream.Seek(offset + (channel * 4), Donut::SeekMode::Begin);
			int32_t stepIndex = (int32_t)stream.Read<int16_t>();
			int32_t nibbleDecoded = (int32_t)stream.Read<int16_t>();

			if (stepIndex < 0)
				stepIndex = 0;
			else if (stepIndex > 88)
				stepIndex = 88;

			for (size_t i = 0; i < numBlockSamples; ++i)
			{
				size_t byteOffset = offset + 4 * numChannels + channel + i / 2 * numChannels;
				stream.Seek(byteOffset, Donut::SeekMode::Begin);
				int8_t byte = stream.Read<int8_t>();
				int32_t nibble = (byte >> (i & 1 ? 4 : 0)) & 0xF;
				DecodeNibble(nibble, nibbleDecoded, stepIndex);
				outBuffer[((firstSample + i) * numChannels) + channel] = (int16_t)nibbleDecoded;
			}

			offset += blockSize;
		}
	}
}

RSDFile::RSDFile(MemoryStream& stream)
{
	stream.Seek(0, Donut::SeekMode::Begin);
	auto magic = stream.ReadString(8);
	_numChannels = stream.Read<uint32_t>();
	_bitsPerChannel = stream.Read<uint32_t>();
	_sampleRate = stream.Read<uint32_t>();

	stream.Seek(0x800, Donut::SeekMode::Begin);

	if (magic == "RSD4PCM ")
	{
		_data.resize(stream.Size() - stream.Position());
		stream.ReadBytes((uint8_t*)_data.data(), _data.size());
	}
	else if (magic == "RSD4RADP")
	{
		uint32_t encodedLength = (uint32_t)(stream.Size() - stream.Position());
		uint32_t encodedBlockSize = _numChannels * 20;
		uint32_t numBlocks = encodedLength / encodedBlockSize;
		uint32_t numSamples = (numBlocks / _numChannels) * 32;

		_data.resize(numSamples * sizeof(int16_t));

		DecodeRADP(stream, (int16_t*)_data.data(), numBlocks, _numChannels);
	}
}
} // namespace Donut::RCL
