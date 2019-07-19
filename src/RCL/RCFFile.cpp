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
			auto str = file.ReadString(strLen);
			_filenames[i] = str;
			_filenameMap.insert(std::pair<std::string, size_t>(str, i));
			auto fileType = file.Read<uint32_t>();
			fileType = fileType;
		}

		file.Close();
	}

	std::unique_ptr<MemoryStream> RCFFile::GetFileStream(const std::string name)
	{
		if (_filenameMap.find(name) != _filenameMap.end())
		{
			return GetFileStream(_filenameMap.at(name));
		}

		return nullptr;
	}

	std::unique_ptr<MemoryStream> RCFFile::GetFileStream(size_t index)
	{
		assert(index < _fileEntries.size());

		File file;
		file.Open(_filename, FileMode::Read);

		const FileEntry& fileEntry = _fileEntries[index];
		file.Seek(fileEntry.offset, Donut::FileSeekMode::Begin);
		std::vector<uint8_t> data(fileEntry.size);
		file.ReadBytes(data.data(), fileEntry.size);
		file.Close();

		return std::make_unique<MemoryStream>(std::move(data));
	}

} // namespace Donut::RCL
