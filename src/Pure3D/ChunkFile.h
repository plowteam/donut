// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include "Core/File.h"
#include "Core/IFile.h"
#include "Pure3D/Types.h"

#include <cstddef>
#include <cstdint>
#include <stack>

namespace donut::pure3d
{

/**
 * ChunkFile provides an IFile interface around a wrapped File
 * capable of reading chunks from Pure3D (P3D) files in compressed
 * and uncompressed formats and with varying endians.
 */
class ChunkFile: public Donut::IFile
{
public:
	/**
	 * Creates a wrapper around a File capable of reading P3D chunks.
	 */
	ChunkFile(Donut::File* file);
	~ChunkFile() override;

	/**
	 * Begins the next chunk, advancing the file pointer to the chunk data.
	 * And returning the chunk type identifer.
	 *
	 * @return The new chunk type id.
	 */
	ChunkID BeginChunk();

	/**
	 * Begins the chunk GIVEN the chunk type has already been read.
	 * Only really useful at the start of the file, or if iterating children?
	 *
	 * @return The new chunk type id.
	 */
	ChunkID BeginChunk(ChunkID chunkType);

	/**
	 * Ends the current chunk and advances the file pointer beyond this chunk.
	 */
	void EndChunk();

	/**
	 * Checks if there are any chunks remaining in the current chunk.
	 */
	bool ChunksRemaining(); // AnyChunksAvailable

	/**
	 * Returns the current chunk type.
	 *
	 * @return The current chunk type.
	 */
	ChunkID GetCurrentID() const;

	/**
	 * Debug: Prints the current chunk info with indent.
	 */
	void PrintCurrentChunk(int indent) const;

public:
	// IFile overrides (simply redirect to our internal IFile pointer)
	[[nodiscard]] std::size_t GetPosition() override;
	bool Seek(std::size_t position, Donut::SeekOrigin origin) override;
	bool Read(std::uint8_t* dest, std::size_t bytesToRead) override;
	bool Write(std::uint8_t* source, std::size_t bytesToWrite) override;
	bool Flush() override;
	[[nodiscard]] std::size_t GetSize() override;

public:
	// Some templated reads for our file
	template <typename T>
	inline std::size_t Read(T* data, std::size_t length = 1)
	{
		Read(reinterpret_cast<uint8_t*>(data), sizeof(T) * length);
		return sizeof(T) * length;
	}
	template <typename T>
	T Read()
	{
		T value;
		Read<T>(&value);
		return value;
	}

private:
	ChunkFile(const ChunkFile&) = delete;
	ChunkFile& operator=(const ChunkFile&) = delete;

	// IFile* _file;
	Donut::File* _file;

	struct Chunk
	{
		ChunkID type;
		std::size_t start_position;
		std::uint32_t data_size;
		std::uint32_t total_size;
	};

	std::stack<Chunk> _chunks;
};

} // namespace Donut
