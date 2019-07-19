#include <Core/File.h>
#include <RCL/RCFFile.h>

namespace Donut::RCL
{
	RCFFile::RCFFile(const std::string& path) :
		_filename(path)
	{
		File file;
		file.Open(path, FileMode::Read);

		auto magic = file.ReadString(22);
		assert(magic == "RADCORE CEMENT LIBRARY");

		file.Seek(0x20, Donut::FileSeekMode::Begin);
		auto version = file.Read<uint32_t>();
		assert(version == 16777729);

		file.Seek(0x24, Donut::FileSeekMode::Begin);
		auto dataOffset = file.Read<uint32_t>();
		file.Seek(dataOffset, Donut::FileSeekMode::Begin);

		auto numFiles = file.Read<uint32_t>();
		auto tableOffset = file.Read<uint32_t>();
		file.Seek(0x8, Donut::FileSeekMode::Current);

		_fileEntries.resize(numFiles);
		file.ReadBytes(reinterpret_cast<uint8_t*>(_fileEntries.data()), numFiles * sizeof(FileEntry));

		file.Seek(tableOffset, Donut::FileSeekMode::Begin);
		file.Seek(0x8, Donut::FileSeekMode::Current);

		_filenames.resize(numFiles);

		for (size_t i = 0; i < numFiles; ++i)
		{
			auto strLen = file.Read<uint32_t>();
			_filenames[i] = file.ReadString(strLen);
			auto fileType = file.Read<uint32_t>();
		}

		file.Close();
	}
} // namespace Donut::P3D
