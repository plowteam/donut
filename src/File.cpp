#include <File.h>
#include <cassert>
#include <sstream>
#include <stdexcept>

namespace Donut
{

File::File() : _file(nullptr) {}

File::File(const std::filesystem::path& path, FileMode mode) :
	_file(nullptr)
{
	Open(path, mode);
}

File::~File()
{
	Close();
}

void File::Open(const std::filesystem::path& path, FileMode mode)
{
	Close();

#ifdef _WIN32
	_wfopen_s(&_file, path.wstring().c_str(), L"rb");
#else
	_file = std::fopen(path.c_str(), "rb");
#endif

	if (_file == nullptr)
		throw std::runtime_error("fopen failed");
}

void File::Close()
{
	if (_file != nullptr)
		std::fclose(_file);

	_file = nullptr;
}

void File::Seek(size_t position, FileSeekMode mode) const
{
	assert(_file != nullptr);
	std::fseek(_file, static_cast<long>(position), static_cast<int>(mode));
}

size_t File::Position() const
{
	assert(_file != nullptr);
	return static_cast<size_t>(std::ftell(_file));
}

size_t File::Size() const
{
	assert(_file != nullptr);

	size_t origPos = Position();
	Seek(0, FileSeekMode::End);

	size_t size = Position();
	Seek(origPos, FileSeekMode::Begin);

	return size;
}

void File::Flush()
{
	assert(_file != nullptr);
	std::fflush(_file);
}

} // namespace Donut
