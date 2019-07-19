#pragma once

#include <P3D/P3DChunk.h>
#include <string>

namespace Donut::RCL
{
	enum class FileTypes : uint32_t
	{
	};

	struct FileEntry
	{
		uint32_t crc;
		uint32_t offset;
		uint32_t size;
	};

	class RCFFile
	{
	public:

		RCFFile(const std::string& file);

		const std::string& GetFileName() const
		{
			return _filename;
		}

	protected:

		std::string _filename;
		std::vector<uint8_t> _data;
		std::vector<FileEntry> _fileEntries;
		std::vector<std::string> _filenames;
	};
} // namespace Donut::P3D
