#include <Pure3D/Pure3D.h>

namespace Donut::Pure3D
{

Pure3D::Pure3D() {

}

void Pure3D::LoadFromFile(File& file)
{
	uint32_t type;
	file.Read<uint32_t>(&type, 1);

	// cba reading the other formats
	assert(type == static_cast<uint32_t>(FileTypes::P3D));

	// rewind to the start, the file type is the root chunk type
	file.Seek(0, FileSeekMode::Begin);

	_root.Read(file);
}

}
