#include <P3D/AnimationGroupList.h>
#include <MemoryStream.h>
#include <iostream>

namespace Donut::P3D {

	std::unique_ptr<AnimationGroupList> AnimationGroupList::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::AnimationGroupList));

		MemoryStream stream(chunk.GetData());

		uint32_t version = stream.Read<uint32_t>();
		uint32_t numGroups = stream.Read<uint32_t>();

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::AnimationGroup:
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<AnimationGroupList>();
	}

} // namespace Donut::P3D
