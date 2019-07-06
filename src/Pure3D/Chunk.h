#pragma once

#include <File.h>
#include <memory>
#include <vector>

namespace Donut::Pure3D
{

enum class ChunkType : uint32_t {
	P3DRoot   = 0xFF443350,
	Texture   = 0x19000,
	Image	  = 0x19001,
	ImageData = 0x19002,
};

class Chunk
{
public:
	Chunk();
	~Chunk();
	void Read(File&, int indentLevel);
protected:
	void readChildren(File&, int indentLevel);

	std::uint32_t _type;
	std::uint32_t _dataSize;
	std::uint32_t _totalSize;

	Chunk* _parent;
	std::vector<std::unique_ptr<Chunk>> _children;
};

} // namespace Donut::Pure3D
