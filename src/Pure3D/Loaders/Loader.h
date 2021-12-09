// Copyright 2019-2021 the donut authors. See COPYING.md for legal info.

#pragma once

#include "Pure3D/Types.h"

namespace donut::pure3d
{
class ChunkFile;

class ChunkLoader
{
public:
	virtual void Load(ChunkFile&, void* store) = 0;
	ChunkID GetChunkID() const { return _chunkID; }
protected:
	ChunkLoader(ChunkID chunkID) : _chunkID(chunkID) {}

	ChunkID _chunkID;
};

/*
 * SimpleLoader automatically adds a single named resource to the entity store.
 * Testing for collisions and handling name overrides.
 */
class SimpleChunkLoader: public ChunkLoader
{
public:
	virtual void Load(ChunkFile&, void* store) override = 0;
	virtual std::shared_ptr<Entity> LoadEntity(ChunkFile&, void* store) = 0;
protected:
	SimpleChunkLoader(ChunkID chunkID) : ChunkLoader(chunkID) {}
};

// impl
void SimpleChunkLoader::Load(ChunkFile& file, void* store)
{
	// check id from file with loader
	assert(file.GetCurrentID() == this->GetChunkID());
	if (file.GetCurrentID() != this->GetChunkID())
		return;



	// object = LoadObject();
	// store->TestCollision(object);
	// handle collision

	// if name override then SetText(object, this->nameOverride);
	// finally store it in the store

}

} // namespace donut::p3d
