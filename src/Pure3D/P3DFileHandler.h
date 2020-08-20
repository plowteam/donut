// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include <cstdint>
#include <string>

namespace Donut
{

// P3DCallback
// P3DEntityStoreWrapperBank
// P3DFileReader
// P3DInventoryWrapperBank

// tChunkHandler:
// IRefCount* __thiscall tChunkHandler::LoadData(tChunkHandler* this, radLoadStream* param_1, int param_2, radLoadInventory* param_3, IRefCount* param_4)
// tChunkHandler::SetNameOverride(char const *)

// tTextureLoader : tSimpleChunkHandler, tChunkHandler
// tChunkHandler::LoadData // creates a tTempStore: tEntityStore, radLoadHashedStore - loads into it, then returns it.
// tSimpleChunkHandler::HandleCollision(tEntity* param1); (Collision = 2 entities same name?)
// LoadObject(ChunkFile* EntityStore*);

// SetHandler is interesting:
// does all it's shit and then basically throws it back
// BeginChunk
// tLoadManager::GetP3DHandler()
// tP3DFileHandler::GetHandler() (texture handler or image handler??)
// then loads or some shit
// EndChunk

class File;

class P3DFileHandler
{
public:
	P3DFileHandler() = default;
	~P3DFileHandler() = default;

	// radLoadOptions { char* file_name, int, int, int, int, ... }
	// radLoadUpdatableRequest ( stream, inventory )
	void LoadFile(void* load_options, void* load_updatable_request); // ASYNC
	void Load(File* file); // File, EntityStore ( return type? ) ((shouldn't be public?))



	void AddHandler(); // tChunkHandler*
	virtual bool CheckExtension(const std::string& extension);


	// Done(tLoadStatus param_1,tLoadRequest *param_2)
	// LoadFile(P3DFileHandler *this,char *param_1,LoadFileCallback *param_2,void *param_3, GameMemoryAllocator param_4)
	// LoadFileSync(P3DFileHandler *this,char *param_1)
	// Release
	// SetSectionName

	// contains a tInventory? think this might keep refs to everything
};

} // namespace Donut
