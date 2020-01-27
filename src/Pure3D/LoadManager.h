// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include <cstdint>
#include <string>

namespace Donut
{

class ILoadDataLoader;
class ILoadFileLoader;

// shouldn't be in Pure3D?
class LoadManager
{
public:
	LoadManager() = default;
	~LoadManager() = default;

	void AddCallback(void* callback);
	void AddDataLoader(ILoadDataLoader* loader);
	void AddFileLoader(ILoadFileLoader* loader, const std::string& extension);
};

} // namespace Donut
