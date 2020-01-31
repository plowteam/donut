// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#include "CameraLoader.h"

namespace Donut
{
Camera* CameraLoader::LoadObject(ChunkFile& file/*, EntityStore& store*/)
{
	uint8_t length;
	uint32_t version;

	file.Read(&length);
	std::string name = file.ReadString(length);
	file.Read(&version);

	assert(version == 0);

	Camera* camera = new Camera();
	// camera->SetName(name);
	file.Read(&camera->_fov);
	file.Read(&camera->_aspectRatio);
	file.Read(&camera->_nearClip);
	file.Read(&camera->_farClip);
	file.Read(&camera->_position);
	file.Read(&camera->_look);
	file.Read(&camera->_up);

	return camera;
}
} // namespace Donut
