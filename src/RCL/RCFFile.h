// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <Core/MemoryStream.h>
#include <map>
#include <memory>
#include <string>

namespace Donut::RCL
{
struct FileEntry
{
	uint32_t hash;
	uint32_t offset;
	uint32_t size;
};

class RCFFile
{
public:
	RCFFile(const std::string& file);

	std::unique_ptr<MemoryStream> GetFileStream(const std::string name);
	std::unique_ptr<MemoryStream> GetFileStream(uint32_t hash);

	const std::string& GetFileName() const { return _filename; }
	const std::vector<std::string>& GetFilenames() const { return _filenames; }

protected:
	std::string _filename;
	std::map<uint32_t, FileEntry> _fileEntries;
	std::vector<std::string> _filenames;
	std::map<std::string, uint32_t> _filenameHashes;
};
} // namespace Donut::RCL
