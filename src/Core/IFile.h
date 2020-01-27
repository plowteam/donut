// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <cstddef>
#include <string>

namespace Donut
{

enum class FileMode
{
	Read,
	Write
};

enum class SeekOrigin
{
	Begin,
	Current,
	End
};

/**
 * File interface.
 */
class IFile
{
public:
	/** Destructor, for closing the file. */
	virtual ~IFile() = default;

	/**
	 * Read bytes from the file into the destination.
	 *
	 * @param dest        Destinatation for the bytes read.
	 * @param bytesToRead Number of bytes to read into dest.
	 * @return            True if successful.
	 */
	virtual bool Read(std::uint8_t* dest, std::size_t bytesToRead) = 0;

	/**
	 * Write bytes to the file from source.
	 *
	 * @param source      Source buffer to read from.
	 * @param bytesToRead Number of bytes to write to the file from source.
	 * @return            True if successful.
	 */
	virtual bool Write(std::uint8_t* source, std::size_t bytesToWrite) = 0;

	/**
	 * Flushes file to disk.
	 */
	virtual bool Flush() = 0;

	/**
	 * Set the current read or write position to as specified.
	 *
	 * @param position New read or write position.
	 * @param origin   From where to base the new position from.
	 * @return True if successful.
	 */
	virtual bool Seek(std::size_t position, SeekOrigin origin) = 0;

	/**
	 * Get the current read or write position.
	 */
	[[nodiscard]] virtual std::size_t GetPosition() = 0;

	// ?
	void SetEndianSwap(bool swap) { _endianSwap = swap; }
	bool GetEndianSwap() const { return _endianSwap; }

public:
	// Utility functions that have default implementations based on virtual operations.

	/** Total size of the file. */
	[[nodiscard]] virtual std::size_t GetSize();

	/** Dunno where to put these */
	uint16_t ReadUInt16();
	uint32_t ReadUInt32();

	// i hate that these are here.
	std::string ReadString(std::size_t length);
	std::string ReadU8String();

protected:
	constexpr IFile() = default;

	unsigned long _endianSwap = false;
};

} // namespace Donut
