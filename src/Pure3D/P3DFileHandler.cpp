// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#include "P3DFileHandler.h"

#include "Core/Log.h"
#include "Core/File.h"
#include "Pure3D/ChunkFile.h"

namespace Donut
{

bool P3DFileHandler::CheckExtension(const std::string& extension)
{
	return extension == "p3d";
}

void P3DFileHandler::Load(File* file)
{
	ChunkFile chunkFile(file);

	while (chunkFile.ChunksRemaining())
	{
		const auto id = chunkFile.BeginChunk();
		void* loader = nullptr; // ILoadManager->GetLoadDataLoader(id);

		if (loader != nullptr)
		{
			// loader->Load(chunkFile, entityStore);
		} else {
			Log::Warn("Unrecognized chunk ({:X}) in {}\n", id, file->GetFileName());
		}

		chunkFile.EndChunk();
	}
}

} // namespace Donut
