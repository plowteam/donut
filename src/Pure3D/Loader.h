// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include <cstdint>

namespace Donut
{

class radLoadObject;

class Loader
{
public:
	Loader(uint32_t chunkID): _chunkID(chunkID) {}

	virtual bool tP3DLoaderIsType(uint32_t type) { return false; } // = 0;
	virtual uint32_t GetTypeID() { return 0; }                     // = 0;            // doesn't need to be priv?
	virtual radLoadObject* LoadObject() { return nullptr; }        // = 0;

protected:
	uint32_t _chunkID;
};

} // namespace Donut
