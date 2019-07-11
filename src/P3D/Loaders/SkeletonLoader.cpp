#include <P3D/Loaders/SkeletonLoader.h>
#include <P3D/Loaders/SkeletonJointLoader.h>
#include <MemoryStream.h>
#include <iostream>

namespace Donut::P3D {

std::unique_ptr<Skeleton> SkeletonLoader::Load(const P3DChunk& chunk)
{
    assert(chunk.IsType(ChunkType::Skeleton));

	MemoryStream stream(chunk.GetData());

	std::string name = stream.ReadLPString();
	uint32_t version = stream.Read<uint32_t>();
	uint32_t numJoints = stream.Read<uint32_t>();

	assert(version == 0);

	std::vector<std::unique_ptr<SkeletonJoint>> joints;
	joints.reserve(numJoints);

	for (auto const& child : chunk.GetChildren())
	{
		switch(child->GetType())
		{
			case ChunkType::SkeletonJoint:
				SkeletonJointLoader loader;
				joints.push_back(loader.Load(*child.get()));
			    break;
			default:
				std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
		}
	}

    return std::make_unique<Skeleton>(name, version, numJoints, std::move(joints));
}

} // namespace Donut::P3D
