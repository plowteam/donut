#pragma once

#include <File.h>
#include <memory>
#include <vector>

namespace Donut::Pure3D
{

class Chunk
{
public:
	Chunk();
	~Chunk();
	void Read(File&, int indentLevel);
protected:
	void readChildren(File&, int indentLevel);

	uint32_t _type;
	uint32_t _dataSize;
	uint32_t _totalSize;

	Chunk* _parent;
	std::vector<std::unique_ptr<Chunk>> _children;
};

} // namespace Donut::Pure3D
