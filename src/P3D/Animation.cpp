#include <P3D/Animation.h>
#include <P3D/AnimationGroupList.h>
#include <MemoryStream.h>
#include <iostream>

namespace Donut::P3D {

	std::unique_ptr<Animation> Animation::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::Animation));

		MemoryStream stream(chunk.GetData());

		uint32_t version = stream.Read<uint32_t>();
		std::string name = stream.ReadLPString();

		uint8_t animType[4];
		stream.ReadBytes(animType, 4);

		float numFrames = stream.Read<float>();
		float frameRate = stream.Read<float>();
		uint32_t looping = stream.Read<uint32_t>();

		std::unique_ptr<AnimationGroupList> groupList;

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
			case ChunkType::AnimationGroupList:
				groupList = AnimationGroupList::Load(*child.get());
				break;
			case ChunkType::AnimationSize:
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<Animation>();
	}

} // namespace Donut::P3D
