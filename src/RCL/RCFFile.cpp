#include <Core/File.h>
#include <Core/CRC32.h>
#include <RCL/RCFFile.h>

namespace Donut::RCL
{
	uint32_t StringHash(const std::string &key) {
		uint32_t hash = 0;
		for (int i = 0; i < key.size(); i++) {
			int c = (int)key[i];
			if (c < 97) c += 32;
			hash = hash * 0x1F + c;
		}

		return hash;
	}

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
		auto unknownOffset0 = file.Read<uint32_t>();
		auto unknownOffset1 = file.Read<uint32_t>();

		for (size_t i = 0; i < numFiles; ++i)
		{
			auto fileEntry = file.Read<FileEntry>();
			_fileEntries.insert(std::pair<uint32_t, FileEntry>(fileEntry.hash, fileEntry));
		}

		file.Seek(tableOffset, Donut::FileSeekMode::Begin);
		auto numFileNames = file.Read<uint32_t>();
		auto unknownOffset2 = file.Read<uint32_t>();

		_filenames.resize(numFileNames);

		for (size_t i = 0; i < numFileNames; ++i)
		{
			auto strLen = file.Read<uint32_t>();
			auto str = file.ReadString(strLen);
			_filenames[i] = str;

			uint32_t hash = StringHash(str);
			_filenameHashes.insert(std::pair<std::string, uint32_t>(str, hash));
			auto date = file.Read<uint32_t>();
		}

		file.Close();
	}

	std::unique_ptr<MemoryStream> RCFFile::GetFileStream(const std::string name)
	{
		if (_filenameHashes.find(name) != _filenameHashes.end())
		{
			return GetFileStream(_filenameHashes.at(name));
		}

		return nullptr;
	}

	std::unique_ptr<MemoryStream> RCFFile::GetFileStream(uint32_t hash)
	{
		if (_fileEntries.find(hash) == _fileEntries.end())
		{
			return nullptr;
		}

		File file;
		file.Open(_filename, FileMode::Read);

		const FileEntry& fileEntry = _fileEntries[hash];
		file.Seek(fileEntry.offset, Donut::FileSeekMode::Begin);
		std::vector<uint8_t> data(fileEntry.size);
		file.ReadBytes(data.data(), fileEntry.size);
		file.Close();

		return std::make_unique<MemoryStream>(std::move(data));
	}

} // namespace Donut::RCL
