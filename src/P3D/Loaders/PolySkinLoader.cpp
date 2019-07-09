#include <P3D/Loaders/PolySkinLoader.h>
#include <MemoryStream.h>
#include <iostream>

namespace Donut::P3D {

std::unique_ptr<PolySkin> PolySkinLoader::Load(const P3DChunk& chunk)
{
    assert(chunk.IsType(ChunkType::PolySkin));

	MemoryStream stream(chunk.GetData());

	std::string name = stream.ReadLPString();
	std::uint32_t version = stream.Read<std::uint32_t>();
	std::string skeletonName = stream.ReadLPString();
	std::uint32_t numPrimGroups = stream.Read<std::uint32_t>();

	printf("PolySkin %s (Version %x): Skeleton %s, %d Prim Groups\n", name.c_str(), version, skeletonName.c_str(), numPrimGroups);

	for (auto const& child : chunk.GetChildren())
	{
		switch(child->GetType())
		{
			case ChunkType::PrimitiveGroup:
			case ChunkType::BoundingBox:
			case ChunkType::BoundingSphere:
			std::cout << "\t" << child->GetType() << " unimplemented.\n";
			break;
			default:
			std::cout << "\tUnexpected Chunk: " << child->GetType() << "\n";
		}

	}

    return std::make_unique<PolySkin>(name, skeletonName);
}

} // namespace Donut::P3D
