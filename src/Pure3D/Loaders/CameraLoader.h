// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include "Pure3D/Camera.h"
#include "Pure3D/ChunkFile.h"
#include "Pure3D/Loaders/Loader.h"

#include <cstdint>
#include <string>

namespace Donut
{

class CameraLoader: public Loader
{
public:
	CameraLoader(): Loader(0x2200) {}
	Camera* LoadObject(ChunkFile&/*, EntityStore&*/);
};

} // namespace Donut
