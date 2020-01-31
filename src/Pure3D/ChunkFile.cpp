// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#include "ChunkFile.h"

#include "Core/Log.h"

namespace Donut
{

constexpr const uint32_t FileType_P3D = 0xFF443350; // 'P3D'
constexpr const uint32_t FileType_P3D_Big = 0x503344FF; // 'D3P'
constexpr const uint32_t FileType_P3DZ = 0x5A443350; // 'P3DZ'
constexpr const uint32_t FileType_P3DZ_Big = 0x5033445A; // 'ZD3P'
constexpr const uint32_t FileType_RZ = 0x5A52; // 'RZ'

ChunkFile::ChunkFile(File* file): _file(file)
{
	ChunkType type = Read<ChunkType>();

	if (type == FileType_P3D_Big || type == FileType_P3DZ_Big) {
		// SetEndianSwap(true);
	}

	if (type != FileType_P3D)
	{
		Log::Error("Can't work with that file type yet.\n");
		return;
	}

	// if (type == FileType_P3DZ) {
	// 	uint32_t compressedSize = _file->Read<uint32_t>();
	// 	uint32_t uncompressedSize = _file->Read<uint32_t>();
	// 	uint32_t compressedSize2 = _file->Read<uint32_t>();
	// 	uint16_t unk3 = _file->Read<uint16_t>();
	// 	uint32_t realType = _file->Read<uint32_t>();
	// }

	BeginChunk(type);
}

ChunkFile::~ChunkFile() {}

ChunkType ChunkFile::BeginChunk(ChunkType chunkType)
{
	std::uint32_t dataSize, totalSize;

	auto startPosition = GetPosition() - 4;
	Read<uint32_t>(&dataSize);
	Read<uint32_t>(&totalSize);

	_chunks.emplace(Chunk {chunkType, startPosition, dataSize, totalSize});
	return chunkType;
}

ChunkType ChunkFile::BeginChunk()
{
	if (!_chunks.empty())
	{
		auto const& chunk = _chunks.top();
		if (GetPosition() < chunk.start_position + chunk.data_size)
			Seek(chunk.start_position + chunk.data_size, SeekOrigin::Begin);
	}

	auto startPosition = GetPosition();
	auto chunkType = Read<ChunkType>();
	auto dataSize = Read<uint32_t>();
	auto totalSize = Read<uint32_t>();

	_chunks.emplace(Chunk {chunkType, startPosition, dataSize, totalSize});
	return chunkType;
}

void ChunkFile::EndChunk()
{
	if (_chunks.empty())
		return;

	auto const& chunk = _chunks.top();
	Seek(chunk.start_position + chunk.total_size, SeekOrigin::Begin);
	_chunks.pop();
}

bool ChunkFile::ChunksRemaining()
{
	if (_chunks.empty())
		return false;

	auto const& chunk = _chunks.top();
	return GetPosition() < chunk.start_position + chunk.total_size;
}

ChunkType ChunkFile::GetCurrentID() const
{
	auto const& chunk = _chunks.top();
	return chunk.type;
}

void ChunkFile::PrintCurrentChunk(int indent) const
{
	auto const& chunk = _chunks.top();
	Log::Debug("{0}Chunk ({1:#X}) @{2:#X} (Data Size: {3:#X} Total: {4:#X})\n", std::string(indent, '\t'), chunk.type,
	           chunk.start_position, chunk.data_size, chunk.total_size);
}

/////////////////////////////////////////////
// IFile overrides                         //
// Should just redirect to _file for each. //
/////////////////////////////////////////////

std::size_t ChunkFile::GetPosition()
{
	return _file->Position();
}

bool ChunkFile::Seek(std::size_t position, SeekOrigin origin)
{
	_file->Seek(position, static_cast<FileSeekMode>(origin));
	return true;
}

bool ChunkFile::Read(std::uint8_t* dest, std::size_t bytesToRead)
{
	const auto bytesRead = _file->Read(dest, bytesToRead);
	return bytesRead == bytesToRead;
}

bool ChunkFile::Write(std::uint8_t* source, std::size_t bytesToWrite)
{
	return false;
}

bool ChunkFile::Flush()
{
	_file->Flush();
	return true;
}

std::size_t ChunkFile::GetSize()
{
	return _file->Size();
}

} // namespace Donut
