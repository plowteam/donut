// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include <cstdint>

namespace Donut
{

class radLoadObject
{
};

class ChunkFile;
class EntityStore;

class CLASS_NAME // : radLoadObject
{
public:
protected:
	uint32_t properties;

	friend class CLASS_NAMELoader;
};

class CLASS_NAMELoader
{
public:
	CLASS_NAMELoader(): chunkID(0x00) {}
	CLASS_NAME* LoadObject(const ChunkFile&, EntityStore&); // maybe return a shared_ptr?

protected:
	uint32_t chunkID;
};

} // namespace Donut
