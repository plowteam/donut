#include <MemoryStream.h>
#include <P3D/AnimationGroup.h>
#include <iostream>

namespace Donut::P3D
{

std::unique_ptr<AnimationGroup> AnimationGroup::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::AnimationGroup));

	MemoryStream stream(chunk.GetData());

	uint32_t version     = stream.Read<uint32_t>();
	std::string name     = stream.ReadLPString();
	uint32_t groupId     = stream.Read<uint32_t>();
	uint32_t numChannels = stream.Read<uint32_t>();

	auto animationGroup = std::make_unique<AnimationGroup>();

	for (auto const& child : chunk.GetChildren())
	{
		animationGroup->LoadChannels(*child);
	}

	return animationGroup;
}

void AnimationGroup::LoadChannels(const P3DChunk& chunk)
{
	MemoryStream data(chunk.GetData());

	switch (chunk.GetType())
	{
	case ChunkType::Vector1Channel:
		break;
	case ChunkType::Vector2Channel:
		_vector2Channel = std::make_unique<Vector2Channel>();
		_vector2Channel->Read(data);
		break;
	case ChunkType::Vector3Channel:
		_vector3Channel = std::make_unique<Vector3Channel>();
		_vector3Channel->Read(data);
		break;
	case ChunkType::QuaternionChannel:
		_quaternionChannel = std::make_unique<QuaternionChannel>();
		_quaternionChannel->Read(data);
		break;
	case ChunkType::CompressedQuaternionChannel:
		_compressedQuaternionChannel = std::make_unique<CompressedQuaternionChannel>();
		_compressedQuaternionChannel->Read(data);
		break;
	default:
		std::cout << "Unexpected Chunk: " << chunk.GetType() << "\n";
	}
}

} // namespace Donut::P3D
