// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include <cstdint>
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <thread>
#include <queue>
#include <unordered_map>

namespace Donut
{

class ChunkLoader;
class LoadCallback;

enum class LoadState
{
	State1 = 1,
	State2 = 2,
	State3 = 3,
};

struct LoadOptions
{
	std::string name;
	void* stream;
	bool syncLoad;
};

struct LoadRequest
{
	int startTime;
	LoadState state;
	LoadOptions loadOptions;

	void SetState(LoadState state);
};

/**
LoadManager handles all loading in the game.
DataLoader interprets the data from files.
FileLoader interprets files directly...
*/
class LoadManager
{
	using LoadRequestPtr = std::shared_ptr<LoadRequest>;

public:
	LoadManager();
	~LoadManager() = default;

	LoadManager(const LoadManager&) = delete;
	LoadManager& operator=(const LoadManager&) = delete;

public:
	void AddChunkLoader(std::unique_ptr<ChunkLoader>&& loader);
	ChunkLoader* GetChunkLoader(std::size_t id);

	// AddCallback adds a callback everytime something is loaded?
	// void AddCallback(void* callback);
	// void AddFileLoader(ILoadFileLoader* loader, const std::string& extension);

	std::shared_ptr<LoadRequest> Load(const std::string& name);
	void Load(LoadOptions* options, LoadRequest* outRequest);

protected:
	void WorkerThreadEntryPoint();

private:
	bool _syncLoading;
	std::queue<LoadCallback> *_loadCallbacks;

	void internalService();

	// std::unordered_map<std::size_t, std::unique_ptr<ChunkLoader>> _fileLoaders;
	std::unordered_map<std::size_t, std::unique_ptr<ChunkLoader>> _dataLoaders;

	std::thread _workerThread;
	//std::vector<std::thread> _workerThreads;
	std::queue<LoadRequestPtr> _loadRequests;
	std::mutex _loadRequestLock;
};

} // namespace Donut
