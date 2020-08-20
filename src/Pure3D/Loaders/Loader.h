// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include <cstdint>

namespace Donut
{

class ChunkFile;

class ChunkLoader
{
public:
	ChunkLoader(std::size_t chunkID): _chunkID(chunkID) {}
	// virtual ~ChunkLoader() = default;

	virtual std::size_t GetChunkID() { return _chunkID; } 
	virtual void* LoadObject(ChunkFile&) = 0;

	//virtual void LoadData() = 0;

protected:
	std::size_t _chunkID;
};

} // namespace Donut
