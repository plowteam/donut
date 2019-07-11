#include <MemoryStream.h>
#include <P3D/Texture.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_ONLY_PNG
#include <stb_image.h>

namespace Donut::P3D
{

std::vector<uint8_t> getImageData(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::ImageData));

	MemoryStream stream(chunk.GetData());

	uint32_t length = stream.Read<uint32_t>();
	std::vector<uint8_t> data(length);
	stream.ReadBytes(data.data(), data.size());
	return data;
}

// just does png for now
ImageData decodeImageData(const std::vector<uint8_t>& data)
{
	ImageData ret;
	uint8_t* image = stbi_load_from_memory(data.data(), data.size(), &ret.width, &ret.height, &ret.comp, 0);
	ret.data       = std::vector<uint8_t>(image, image + (ret.width * ret.height * ret.comp));
	stbi_image_free(image);

	return ret;
}

std::unique_ptr<Texture> Texture::Load(const P3DChunk& chunk)
{
	assert(chunk.IsType(ChunkType::Texture));

	MemoryStream stream(chunk.GetData());

	std::string name = stream.ReadLPString();
	uint32_t version = stream.Read<uint32_t>();

	assert(version == 14000);

	uint32_t width       = stream.Read<uint32_t>();
	uint32_t height      = stream.Read<uint32_t>();
	uint32_t bpp         = stream.Read<uint32_t>();
	uint32_t alphaDepth  = stream.Read<uint32_t>();
	uint32_t numMipMaps  = stream.Read<uint32_t>();
	uint32_t textureType = stream.Read<uint32_t>();
	uint32_t usage       = stream.Read<uint32_t>();
	uint32_t priority    = stream.Read<uint32_t>();

	assert(chunk.GetChildren().size() > 0);

	// assume we just have one image chunk in this, not seen anything else yet
	auto const& imageChunk = chunk.GetChildren().at(0);
	assert(imageChunk->IsType(ChunkType::Image));
	MemoryStream img(imageChunk->GetData());

	std::string img_name    = img.ReadLPString();
	uint32_t img_version    = img.Read<uint32_t>();
	uint32_t img_width      = img.Read<uint32_t>();
	uint32_t img_height     = img.Read<uint32_t>();
	uint32_t img_bpp        = img.Read<uint32_t>();
	uint32_t img_palettized = img.Read<uint32_t>();
	uint32_t img_hasAlpha   = img.Read<uint32_t>();
	uint32_t img_format     = img.Read<uint32_t>();

	// lets just check its the same shit
	assert(width == img_width);
	assert(height == img_height);
	assert(bpp == img_bpp);

	// finally we have the image data
	if (imageChunk->GetChildren().size() < 1)
		throw std::runtime_error("no image data in image homer");

	auto const& imgDataChunk  = imageChunk->GetChildren().at(0);
	std::vector<uint8_t> data = getImageData(*imgDataChunk.get());

	ImageData imgdata = decodeImageData(data);

	return std::make_unique<Texture>(name, width, height, bpp, imgdata);
}

} // namespace Donut::P3D
