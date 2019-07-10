#include <P3D/P3DFile.h>
#include <File.h>

namespace Donut::P3D {

P3DFile::P3DFile(const std::string& path) : _filename(path) {
    File file;
    file.Open(path, FileMode::Read);

	std::uint32_t type;
    file.Read(&type, 1);

    // cba reading the other formats
    assert(type == static_cast<uint32_t>(FileTypes::P3D));

    // rewind to the start, the file type is the root chunk type
    file.Seek(0, FileSeekMode::Begin);

    const std::size_t size = file.Size();
    _data.resize(size);

    file.ReadBytes(_data.data(), size);
    file.Close();

    _root = std::make_unique<P3DChunk>(_data);
}


} // namespace Donut::P3D
