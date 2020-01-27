// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include "ChunkFile.h"
#include "Loader.h"
#include "Texture.h"

#include <cstdint>
#include <string>

namespace Donut
{

class TextureLoader: public Loader
{
public:
	TextureLoader(): Loader(0x19000) {}
	P3DTexture* LoadObject(ChunkFile&);

private:
	P3DTexture* LoadImage(ChunkFile& file);
};

} // namespace Donut
