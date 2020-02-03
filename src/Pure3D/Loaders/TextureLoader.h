// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include "Pure3D/ChunkFile.h"
#include "Pure3D/Texture.h"
#include "Pure3D/Loaders/Loader.h"

#include <cstdint>
#include <memory>
#include <string>

namespace Donut
{

class TextureLoader: public Loader
{
public:
	TextureLoader(): Loader(0x19000) {}
	std::shared_ptr<Texture> LoadObject(ChunkFile&); // todo: this doesn't override any virtuals.

private:
	std::shared_ptr<Texture> LoadImage(ChunkFile& file);
};

} // namespace Donut
