#include <Core/File.h>
#include <RCL/RCFFile.h>
#include <Core/MemoryStream.h>

namespace Donut::RCL
{
	RCFFile::RCFFile(const std::string& path) :
		_filename(path)
	{
		File file;
		file.Open(path, FileMode::Read);

		const std::size_t size = file.Size();
		_data.resize(size);
		file.ReadBytes(_data.data(), size);
		file.Close();

		MemoryStream stream(_data);
		auto magic = stream.ReadString(22);
		assert(magic == "RADCORE CEMENT LIBRARY");

		stream.Seek(0x20, Donut::SeekMode::Begin);
		auto version = stream.Read<uint32_t>();
		assert(version == 16777729);

		stream.Seek(0x24, Donut::SeekMode::Begin);
		auto dataOffset = stream.Read<uint32_t>();
		stream.Seek(dataOffset, Donut::SeekMode::Begin);

		auto numFiles = stream.Read<uint32_t>();
		auto tableOffset = stream.Read<uint32_t>();
		stream.Seek(0x8, Donut::SeekMode::Current);

		_fileEntries.resize(numFiles);
		stream.ReadBytes(reinterpret_cast<uint8_t*>(_fileEntries.data()), numFiles * sizeof(FileEntry));

		stream.Seek(tableOffset, Donut::SeekMode::Begin);
		stream.Seek(0x8, Donut::SeekMode::Current);

		_filenames.resize(numFiles);

		for (size_t i = 0; i < numFiles; ++i)
		{
			auto strLen = stream.Read<uint32_t>();
			_filenames[i] = stream.ReadString(strLen);
			auto fileType = stream.Read<uint32_t>();
		}
	}
} // namespace Donut::P3D
