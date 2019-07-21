#include <Core/MemoryStream.h>
#include <P3D/SceneGraphDrawable.h>
#include <iostream>

namespace Donut::P3D
{
	std::unique_ptr<SceneGraphDrawable> SceneGraphDrawable::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::ScenegraphDrawable));

		MemoryStream stream(chunk.GetData());

		std::string name = stream.ReadLPString();

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::ScenegraphSortOrder:
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<SceneGraphDrawable>(name);
	}
} // namespace Donut::P3D
