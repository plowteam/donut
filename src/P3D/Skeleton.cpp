#include <MemoryStream.h>
#include <P3D/Skeleton.h>
#include <iostream>

namespace Donut::P3D
{

std::unique_ptr<Skeleton> Skeleton::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::Skeleton));

	MemoryStream stream(chunk.GetData());

	std::string name   = stream.ReadLPString();
	uint32_t version   = stream.Read<uint32_t>();
	uint32_t numJoints = stream.Read<uint32_t>();

	assert(version == 0);

	std::vector<std::unique_ptr<SkeletonJoint>> joints;
	joints.reserve(numJoints);

	for (auto const& child : chunk.GetChildren())
	{
		switch (child->GetType())
		{
		case ChunkType::SkeletonJoint:
			joints.push_back(SkeletonJoint::Load(*child.get()));
			break;
		default:
			std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
		}
	}

	return std::make_unique<Skeleton>(name, version, numJoints, std::move(joints));
}

} // namespace Donut::P3D
