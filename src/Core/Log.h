// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <fmt/format.h>
#include <fmt/printf.h>

#include <string>

namespace Donut
{
namespace Log
{

template <typename... Args>
inline void Debug(std::string_view fmt, const Args&... args)
{
	fmt::print(fmt, args...);
}

template <typename... Args>
inline void Info(std::string_view fmt, const Args&... args)
{
	fmt::print(fmt, args...);
}

template <typename... Args>
inline void Warn(std::string_view fmt, const Args&... args)
{
	fmt::print(fmt, args...);
}

template <typename... Args>
inline void Error(std::string_view fmt, const Args&... args)
{
	fmt::print(fmt, args...);
}

}
} // namespace Donut
