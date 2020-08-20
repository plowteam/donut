// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#include "LoadManager.h"

#include "Core/Log.h"
#include "Pure3D/Loaders/Loader.h"

namespace Donut
{

LoadManager::LoadManager()
{
	// init:
	// radLoadFileLoaders hash table 0x40 200
	// radLoadDataLoaders hash table 0x100 (200
	// radLoadObjects ptr queue 0x20
	// radLoadCallback ptr queue 32

	// _loadThread = std::thread(&LoadManager::internalService, this);
}

void LoadManager::AddChunkLoader(std::unique_ptr<ChunkLoader>&& loader)
{
	const std::size_t chunkID = loader->GetChunkID();
	_dataLoaders[chunkID] = std::move(loader);
}

ChunkLoader* LoadManager::GetChunkLoader(std::size_t id)
{
	auto it = _dataLoaders.find(id);
	return it != _dataLoaders.end()
		? it->second.get()
		: nullptr;
}

void LoadManager::internalService() { }

} // namespace Donut
