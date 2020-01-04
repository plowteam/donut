// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/FileSystem.h"

#include <cassert>
#include <cstdio>
#include <string>

namespace Donut
{

enum class FileMode
{
	Read,
	Write
};

enum class FileSeekMode
{
	Begin = SEEK_SET,
	Current = SEEK_CUR,
	End = SEEK_END
};

class File
{
public:
	File();
	File(const FileSystem::path& filename, FileMode mode);
	~File();

	void Open(const FileSystem::path& filename, FileMode mode);
	void Close();

	template <typename T>
	std::size_t Read(T* data) const
	{
		assert(_file != nullptr);
		static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable");
		return std::fread(data, sizeof(T), 1, _file);
	}

	template <typename T>
	std::size_t Read(T* data, std::size_t length) const
	{
		assert(_file != nullptr);
		static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable");
		return std::fread(data, sizeof(T), length, _file);
	}

	template <typename T>
	std::size_t ReadBytes(T* data, std::size_t length) const
	{
		assert(_file != nullptr);
		static_assert(std::is_trivially_copyable_v<T>, "T must be trivially copyable");
		return Read(reinterpret_cast<uint8_t*>(data), length);
	}

	template <typename T>
	T Read()
	{
		T data;
		Read(&data);
		return data;
	}

	void Seek(std::size_t position, FileSeekMode mode) const;
	std::size_t Position() const;
	std::size_t Size() const;
	bool IsEOF() const;

	void Flush();

	static std::string ReadAll(const FileSystem::path& filename);

	std::string ReadString(std::size_t length);

	std::string ReadLine();

protected:
	FILE* _file;
	std::size_t _size;
};

} // namespace Donut
