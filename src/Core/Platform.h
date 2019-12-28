// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

// Platform
#ifdef _WIN32
#define DONUT_PLATFORM_WINDOWS
#elif __linux
#define DONUT_PLATFORM_LINUX
#endif

// Force Inline
#if defined(__clang__) || defined(__GNUC__)
#	define FORCEINLINE inline __attribute__((always_inline))
#elif defined(_MSC_VER)
#	define FORCEINLINE __forceinline
#else
#	define FORCEINLINE inline
#endif

// Alignment
#ifdef _MSC_VER
#define MS_ALIGN(n) __declspec(align(n))
#define GCC_PACK(n)
#define GCC_ALIGN(n)
#else
#define MS_ALIGN(n)
#define GCC_PACK(n) __attribute__((packed, aligned(n)))
#define GCC_ALIGN(n) __attribute__((aligned(n)))
#endif
