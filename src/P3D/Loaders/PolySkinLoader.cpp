#include <P3D/Loaders/PolySkinLoader.h>

namespace Donut::P3D {

std::unique_ptr<PolySkin> PolySkinLoader::Load(const P3DChunk& chunk)
{
    assert(chunk.IsType(ChunkType::PolySkin));

	const auto& data = chunk.GetData();
    
	printf("PolySkin Name Length: %d\n", data.at(0));

    // String Name
    // uint32_t Version
    // String Skeleton Name
    // uint32_t NumPrimGroups

	// Children Chunks
	// PrimGroups
    // BoundingBox (0x10003)
    // BoundingSphere (0x10004)

    return std::make_unique<PolySkin>();
}

} // namespace Donut::P3D
