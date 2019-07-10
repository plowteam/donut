#include <P3D/Loaders/TextureLoader.h>
#include <MemoryStream.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include <stb_image.h>

namespace Donut::P3D {

std::unique_ptr<Texture> TextureLoader::Load(const P3DChunk& chunk)
{
    assert(chunk.IsType(ChunkType::Texture));

	MemoryStream stream(chunk.GetData());

	std::string name = stream.ReadLPString();
    std::uint32_t version = stream.Read<std::uint32_t>();

	std::cout << "Texture: " << name << " version " << version << "\n";

    return std::make_unique<Texture>();
}

} // namespace Donut::P3D
