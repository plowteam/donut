#include <Core/MemoryStream.h>
#include <P3D/CompositeDrawable.h>
#include <iostream>

namespace Donut::P3D
{
	std::unique_ptr<CompositeDrawable> CompositeDrawable::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::CompositeDrawable));

		MemoryStream stream(chunk.GetData());

		std::string name = stream.ReadLPString();

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::CompositeDrawablePropList:
				break;
			case ChunkType::CompositeDrawableSkinList:
				break;
			case ChunkType::CompositeDrawableEffectList:
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<CompositeDrawable>();
	}
} // namespace Donut::P3D
