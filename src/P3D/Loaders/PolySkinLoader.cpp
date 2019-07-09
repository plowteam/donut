#include <P3D/Loaders/PolySkinLoader.h>
#include <MemoryStream.h>

namespace Donut::P3D {

std::unique_ptr<PolySkin> PolySkinLoader::Load(const P3DChunk& chunk)
{
    assert(chunk.IsType(ChunkType::PolySkin));

	MemoryStream stream(chunk.GetData());

	//std::uint8_t nameLen;
	std::string name = stream.ReadLPString();
	std::uint32_t version = stream.Read<std::uint32_t>();
	std::string skeletonName = stream.ReadLPString();
	std::uint32_t numPrimGroups = stream.Read<std::uint32_t>();

	printf("PolySkin %s (Version %x): Skeleton %s, %d Prim Groups\n", name.c_str(), version, skeletonName.c_str(), numPrimGroups);

	// Children Chunks:
	// PrimGroups
    // BoundingBox (0x10003)
    // BoundingSphere (0x10004)

    return std::make_unique<PolySkin>();
}

} // namespace Donut::P3D
