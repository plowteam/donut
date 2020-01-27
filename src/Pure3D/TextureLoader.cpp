// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#include "TextureLoader.h"

#include "Core/Log.h"
#include "Render/OpenGL/GLTexture2D.h"
#include "ThirdParty/lodepng.h"

#include <png.h>

using namespace Donut::GL;

namespace Donut
{

enum class ImageFormat : uint32_t
{
	Raw = 0,
	PNG = 1,
	TGA = 2,
	BMP = 3,
	IPU = 4,
	DXT = 5,
	DXT1 = 6,
	DXT2 = 7,
	DXT3 = 8,
	DXT4 = 9,
	DXT5 = 10,
};

// nice hot pink error texture (todo: return a shared_ptr of same instance?)
static std::unique_ptr<GLTexture2D> GetErrorTexture()
{
	constexpr GLuint errorTextureData[] = {0xFFFF00DC, 0xFF000000, 0xFF000000, 0xFFFF00DC};

	std::unique_ptr<GLTexture2D> texture =
	    std::make_unique<GLTexture2D>(2, 2, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, errorTextureData);
	return texture;
}

P3DTexture* TextureLoader::LoadObject(ChunkFile& file)
{
	std::string name = file.ReadU8String();
	uint32_t version = file.Read<uint32_t>();

	assert(version == 0);

	// not used at all
	file.Seek(32, SeekOrigin::Current); // w, h, bpp, ad, mipmaps, type, usage, priority

	P3DTexture* tex = nullptr;

	while (file.ChunksRemaining())
	{
		auto const chunkID = file.BeginChunk();

		switch (chunkID)
		{
		case static_cast<ChunkType>(ChunkTypeID::Image): tex = LoadImage(file); break;
		case static_cast<ChunkType>(ChunkTypeID::VolumeImage):
		default: Log::Debug("Unhandled chunk {}\n", chunkID);
		}

		file.EndChunk();
	}

	return tex;
}
P3DTexture* TextureLoader::LoadImage(ChunkFile& file)
{
	// this is all unused, we trust the image data only!
	std::string name = file.ReadU8String();
	file.Seek(20, SeekOrigin::Current); // ver, w, h, bpp, pal not used

	uint32_t hasAlpha, format;
	file.Read(&hasAlpha);
	file.Read(&format);

	// only handle png atm as we suck
	assert(format == 1);

	// there should be 1 chunk
	assert(file.ChunksRemaining());

	auto const chunkID = file.BeginChunk();

	assert(chunkID == static_cast<ChunkType>(ChunkTypeID::ImageData));

	/* get the image data size */
	uint32_t size;
	file.Read(&size);

	/* read into a temporary array */
	// std::vector<uint8_t> pngData(size);
	// file.Read(pngData.data(), size);

	/* use libpng */
	png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	png_infop info = png_create_info_struct(png);
	setjmp(png_jmpbuf(png));

	png_set_read_fn(png, (png_voidp)&file, [](png_struct* ps, png_byte* data, png_size_t length) {
		ChunkFile* f = (ChunkFile*)png_get_io_ptr(ps);
		f->Read(data, length);
	});

	png_read_info(png, info);

	png_byte bit_depth = png_get_bit_depth(png, info);
	png_byte color_type = png_get_color_type(png, info);

	// only support these types
	if (color_type != PNG_COLOR_TYPE_PALETTE &&
		color_type != PNG_COLOR_TYPE_RGB &&
		color_type != PNG_COLOR_TYPE_RGB_ALPHA) {
		Log::Error("Unsupported png_color_type: {}\n", color_type);
		png_destroy_read_struct(&png, 0, 0);
		return nullptr; // todo: return error texture
	}

	// fail?
	png_byte interlace_type = png_get_interlace_type(png, info);
	if (interlace_type) {

	}

	// strip alpha from paletted pngs
	if (png_get_valid(png, info, PNG_INFO_PLTE)) {
		png_set_strip_alpha(png);
	}

	// strip 16-bit png files down to 8 bit
	if (bit_depth == 16) {
		Log::Debug("bit_depth: {}\n", bit_depth);
		png_set_strip_16(png);
	}

	// PNG_COLOR_TYPE_RGB
	png_byte bpp = 32; // bits per PIXEL
	if (bpp != 32) {
		png_set_filler(png, 255, PNG_FILLER_AFTER);
	}
	
	if (color_type == PNG_COLOR_TYPE_PALETTE && bit_depth != 4 && bit_depth != 8) {
		png_set_expand(png);
	}

	png_read_update_info(png, info);

	// png_get_pixel

	int width = png_get_image_width(png, info);
	int height = png_get_image_height(png, info);

	fmt::print("png: {}x{}\n", width, height);

	std::vector<uint8_t> image;

	// should Texture wrap GLTexture2D? (probably)
	auto texture = std::make_unique<GLTexture2D>(2, 2, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, image.data());
	texture->SetObjectLabel(name);

	P3DTexture* p3dtexture = new P3DTexture();
	p3dtexture->SetName(name);

	file.EndChunk();

	return p3dtexture;
}
} // namespace Donut
