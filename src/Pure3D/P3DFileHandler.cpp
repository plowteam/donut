// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#include "P3DFileHandler.h"

#include "Core/Log.h"
#include "Core/File.h"
#include "Pure3D/ChunkFile.h"

// temp
#include "Pure3D/LoadManager.h"
#include "Pure3D/Loaders/SpriteLoader.h"
#include "Pure3D/Loaders/TextureLoader.h"

namespace Donut
{

bool P3DFileHandler::CheckExtension(const std::string& extension)
{
	return extension == "p3d";
}

void P3DFileHandler::Load(File* file)
{
	ChunkFile chunkFile(file);

	LoadManager manager;
	manager.AddChunkLoader(std::unique_ptr<ChunkLoader>(new TextureLoader));
	manager.AddChunkLoader(std::unique_ptr<ChunkLoader>(new SpriteLoader));

	while (chunkFile.ChunksRemaining())
	{
		const auto id = chunkFile.BeginChunk();
		auto loader = manager.GetChunkLoader(id);
		if (loader != nullptr)
		{
			loader->LoadObject(chunkFile);
			// loader->LoadObject();
			// loader->get()
			// loader->Load(chunkFile, entityStore);
		} else {
			Log::Warn("Unrecognized chunk ({:X}) in {}\n", id, file->GetFileName());
		}

		chunkFile.EndChunk();
	}
}

} // namespace Donut
