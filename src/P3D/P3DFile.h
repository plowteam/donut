// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Donut::P3D
{

class P3DChunk;

enum class FileTypes : uint32_t
{
	P3D = 0xFF443350,  // 'P3D'
	P3DZ = 0x5A443350, // 'P3DZ' proprietary compression
	RZ = 0x5A52,       // 'RZ' (zlib deflate)
};

class P3DFile
{
public:
	P3DFile(const std::string& file);
	~P3DFile();

	const P3DChunk& GetRoot() const { return *_root.get(); }
	const std::string& GetFileName() const { return _filename; }

protected:
	std::string _filename;
	std::unique_ptr<P3DChunk> _root;
	std::vector<uint8_t> _data;
};

} // namespace Donut::P3D
