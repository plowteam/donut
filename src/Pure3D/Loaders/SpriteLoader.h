// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include "Pure3D/ChunkFile.h"
#include "Pure3D/Sprite.h"
#include "Pure3D/Texture.h"
#include "Pure3D/Loaders/Loader.h"

#include <cstdint>
#include <memory>
#include <string>

namespace Donut
{

class SpriteLoader: public ChunkLoader
{
public:
	SpriteLoader(): ChunkLoader(0x19005) {}
	virtual void* LoadObject(ChunkFile&) override; // todo: this doesn't override any virtuals.

private:
	Texture* LoadImage(ChunkFile& file);
};

} // namespace Donut
