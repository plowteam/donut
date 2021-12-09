// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include "Pure3D/ChunkFile.h"
#include "Pure3D/Texture.h"
#include "Pure3D/Loaders/Loader.h"

#include <cstdint>
#include <memory>
#include <string>

namespace donut::pure3d
{

class TextureLoader: public SimpleChunkLoader
{
public:
	TextureLoader(): SimpleChunkLoader(ChunkID::Texture) {}
	virtual std::shared_ptr<Entity> LoadEntity(ChunkFile&, void* store) override;

private:
	std::shared_ptr<Texture> LoadImage(ChunkFile& file);
};

} // namespace Donut
