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

	_loadCallbacks = new std::queue<LoadCallback>();
	_loadRequests = new std::queue<LoadRequest>();

	// Use at least one thread
	unsigned int num_workers = 1;

	// Deduce how many more threads we can use
	const auto thread_count = std::thread::hardware_concurrency();

	_workerThread = std::thread(&LoadManager::WorkerThreadEntryPoint, this);
}

void LoadManager::Load(const std::string& name, LoadRequest* outRequest)
{
	LoadOptions options;
	options.name = name;
	this->Load(&options, outRequest);
}

void LoadManager::Load(LoadOptions* options, LoadRequest* outRequest)
{
	if (_syncLoading)
		options->syncLoad = true;

	auto loadRequest = std::make_shared<LoadRequest>();
	loadRequest->SetState(LoadState::State1);
	// loadRequest->SetStream(options->stream);

	// outRequest = loadRequest;

	if (options->syncLoad)
	{
		while (loadRequest->state != LoadState::State3)
		{
			// while loop this shit
		}
	}
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
