#include <P3D/AnimationGroup.h>
#include <MemoryStream.h>
#include <iostream>

namespace Donut::P3D {

	std::unique_ptr<AnimationGroup> AnimationGroup::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::AnimationGroup));

		MemoryStream stream(chunk.GetData());

		uint32_t version = stream.Read<uint32_t>();
		std::string name = stream.ReadLPString();
		uint32_t groupId = stream.Read<uint32_t>();
		uint32_t numChannels = stream.Read<uint32_t>();

		std::unique_ptr<Vector2Channel> vector2Channel = nullptr;
		std::unique_ptr<Vector3Channel> vector3Channel = nullptr;
		std::unique_ptr<QuaternionChannel> quaternionChannel = nullptr;
		std::unique_ptr<CompressedQuaternionChannel> compressedQuaternionChannel = nullptr;

		for (auto const& child : chunk.GetChildren())
		{
			MemoryStream data(child->GetData());

			switch (child->GetType())
			{
			case ChunkType::Vector1Channel:
				break;
			case ChunkType::Vector2Channel:
				vector2Channel = std::make_unique<Vector2Channel>();
				vector2Channel->Read(data);
				break;
			case ChunkType::Vector3Channel:
				vector3Channel = std::make_unique<Vector3Channel>();
				vector3Channel->Read(data);
				break;
			case ChunkType::QuaternionChannel:
				quaternionChannel = std::make_unique<QuaternionChannel>();
				quaternionChannel->Read(data);
				break;
			case ChunkType::CompressedQuaternionChannel:
				compressedQuaternionChannel = std::make_unique<CompressedQuaternionChannel>();
				compressedQuaternionChannel->Read(data);
				break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
			}
		}

		return std::make_unique<AnimationGroup>();
	}

} // namespace Donut::P3D
