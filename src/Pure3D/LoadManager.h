// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include <cstdint>
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <thread>
#include <unordered_map>

namespace Donut
{

class ChunkLoader;

/**
LoadManager handles all loading in the game.
DataLoader interprets the data from files.
FileLoader interprets files directly...
*/
class LoadManager
{
public:
	LoadManager();
	~LoadManager() = default;

public:
	LoadManager(const LoadManager&) = delete;
	LoadManager& operator=(const LoadManager&) = delete;

	LoadManager(LoadManager&&) = delete;
	LoadManager& operator=(LoadManager&&) = delete;

public:
	void AddChunkLoader(std::unique_ptr<ChunkLoader>&& loader);
	ChunkLoader* GetChunkLoader(std::size_t id);

	// AddCallback adds a callback everytime something is loaded?
	// void AddCallback(void* callback);
	// void AddFileLoader(ILoadFileLoader* loader, const std::string& extension);

private:
	void internalService();

	std::unordered_map<std::size_t, std::unique_ptr<ChunkLoader>> _dataLoaders;
	std::thread _loadThread;
	std::mutex _loadMutex;
};

} // namespace Donut
