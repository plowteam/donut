#include <MemoryStream.h>
#include <P3D/AnimationGroup.h>
#include <P3D/AnimationGroupList.h>
#include <iostream>

namespace Donut::P3D
{

std::unique_ptr<AnimationGroupList> AnimationGroupList::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::AnimationGroupList));

	MemoryStream stream(chunk.GetData());

	uint32_t version   = stream.Read<uint32_t>();
	uint32_t numGroups = stream.Read<uint32_t>();

	std::vector<std::unique_ptr<AnimationGroup>> groups;
	groups.reserve(numGroups);

	for (auto const& child : chunk.GetChildren())
	{
		switch (child->GetType())
		{
		case ChunkType::AnimationGroup:
			groups.push_back(AnimationGroup::Load(*child.get()));
			break;
		default:
			std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
		}
	}

	return std::make_unique<AnimationGroupList>(std::move(groups));
}

} // namespace Donut::P3D
