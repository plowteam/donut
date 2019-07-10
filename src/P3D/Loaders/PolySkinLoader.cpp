#include <P3D/Loaders/PolySkinLoader.h>
#include <P3D/Loaders/PrimGroupLoader.h>
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

	assert(version == 3);

	std::vector<std::unique_ptr<PrimGroup>> primGroups;
    primGroups.reserve(numPrimGroups);

	for (auto const& child : chunk.GetChildren())
	{
		switch(child->GetType())
		{
			case ChunkType::PrimitiveGroup:
				PrimGroupLoader primLoader;
                primGroups.push_back(primLoader.Load(*child.get()));
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
