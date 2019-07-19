#pragma once

#include <cassert>
#include <cstdio>
#include <filesystem>
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
	Begin   = SEEK_SET,
	Current = SEEK_CUR,
	End     = SEEK_END
};

class File
{
  public:
	File();
	File(const std::filesystem::path& filename, FileMode mode);
	~File();

	void Open(const std::filesystem::path& filename, FileMode mode);
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

	void Seek(std::size_t position, FileSeekMode mode) const;
	std::size_t Position() const;
	std::size_t Size() const;
	void Flush();

	static std::string ReadAll(const std::filesystem::path& filename);

  protected:
	FILE* _file;
};

} // namespace Donut
