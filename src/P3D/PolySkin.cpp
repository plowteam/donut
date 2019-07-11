#include <MemoryStream.h>
#include <P3D/PolySkin.h>
#include <iostream>

namespace Donut::P3D
{

std::unique_ptr<PolySkin> PolySkin::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::PolySkin));

	MemoryStream stream(chunk.GetData());

	std::string name         = stream.ReadLPString();
	uint32_t version         = stream.Read<uint32_t>();
	std::string skeletonName = stream.ReadLPString();
	uint32_t numPrimGroups   = stream.Read<uint32_t>();

	assert(version == 3);

	std::vector<std::unique_ptr<PrimGroup>> primGroups;
	primGroups.reserve(numPrimGroups);

	for (auto const& child : chunk.GetChildren())
	{
		switch (child->GetType())
		{
		case ChunkType::PrimitiveGroup:
			primGroups.push_back(PrimGroup::Load(*child.get()));
			break;
		case ChunkType::BoundingBox:
		case ChunkType::BoundingSphere:
			// std::cout << child->GetType() << " unimplemented.\n";
			break;
		default:
			std::cout << "Unexpected Chunk: " << child->GetType() << "\n";
		}
	}

	return std::make_unique<PolySkin>(name, skeletonName, std::move(primGroups));
}

} // namespace Donut::P3D
