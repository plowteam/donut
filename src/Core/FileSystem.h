// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#if defined(DONUT_HAS_FILESYSTEM)
#include <filesystem>
#elif defined(DONUT_HAS_FILESYSTEM_EXPERIMENTAL)
#include <experimental/filesystem>
#endif

namespace Donut
{
namespace FileSystem
{
#if defined(DONUT_HAS_FILESYSTEM)
	using namespace std::filesystem;
#elif defined(DONUT_HAS_FILESYSTEM_EXPERIMENTAL)
	using namespace std::experimental::filesystem;
#endif
    }

} // namespace Donut
