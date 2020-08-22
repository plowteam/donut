// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#include "SpriteLoader.h"

#include "Core/Log.h"
#include "Render/OpenGL/GLTexture2D.h"

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

void* SpriteLoader::LoadObject(ChunkFile& file)
{
	std::string name = file.ReadU8String();
	uint32_t nativeX = file.Read<uint32_t>();
	uint32_t nativeY = file.Read<uint32_t>();
	std::string shader = file.ReadU8String();
	uint32_t width = file.Read<uint32_t>();
	uint32_t height = file.Read<uint32_t>();
	uint32_t imageCount = file.Read<uint32_t>();
	uint32_t blitBorder = file.Read<uint32_t>();

	Log::Info("Loaded sprite: {} {}x{} image count: {} nativeXY {} {}\n", name, width, height, imageCount, nativeX, nativeY);

	// TODO: imageCount _should_ always be over 1
	// but hwat if it isn't :o

	// collect a texture list:
	std::vector<std::unique_ptr<Texture>> textures;

	while (file.ChunksRemaining())
	{
		auto const chunkID = file.BeginChunk();

		switch (chunkID)
		{
			case static_cast<ChunkType>(ChunkTypeID::Image) :
				textures.emplace_back(LoadImage(file));
				break;
			default:
				Log::Debug("Unhandled chunk {}\n", chunkID);
		}

		file.EndChunk();
	}

	// pass: textures list (+count)
	// width, height (45x45)
	// shader (if set)
	// nativeX, nativeY (640x480)
	auto sprite = std::make_unique<Sprite>();
	sprite->SetName(name);

	return sprite.get();
}

// todo: move this to common ImageLoader class/factory
Texture* SpriteLoader::LoadImage(ChunkFile& file)
{
	// this is all unused, we trust the image data only!
	std::string name = file.ReadU8String();
	file.Seek(20, SeekOrigin::Current); // ver, w, h, bpp, pal not used

	uint32_t hasAlpha, format;
	file.Read(&hasAlpha);
	file.Read(&format);

	// there should be 1 chunk
	assert(file.ChunksRemaining());

	auto const chunkID = file.BeginChunk();

	assert(chunkID == static_cast<ChunkType>(ChunkTypeID::ImageData));

	auto texture = new Texture();
	if (format == static_cast<uint32_t>(ImageFormat::PNG)) {
		/* get the image data size */
		uint32_t size;
		file.Read(&size);

		/* use libpng */
		png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
		png_infop info = png_create_info_struct(png);
		setjmp(png_jmpbuf(png));

		png_set_read_fn(png, (png_voidp)&file, [](png_struct* ps, png_byte* data, png_size_t length) {
			ChunkFile* f = (ChunkFile*)png_get_io_ptr(ps);
			f->Read(data, length);
			});

		png_uint_32 width, height;
		int bit_depth, color_type;

		png_read_info(png, info);
		png_get_IHDR(png, info, &width, &height, &bit_depth, &color_type, NULL, NULL, NULL);

		// only support these types
		if (color_type != PNG_COLOR_TYPE_PALETTE &&
			color_type != PNG_COLOR_TYPE_RGB &&
			color_type != PNG_COLOR_TYPE_RGB_ALPHA) {
			Log::Error("Unsupported png_color_type: {}\n", color_type);
			png_destroy_read_struct(&png, 0, 0);
			return nullptr; // todo: return error texture
		}

		// Convert transparency to full alpha
		if (png_get_valid(png, info, PNG_INFO_tRNS))
			png_set_tRNS_to_alpha(png);

		// Convert paletted images to RGB
		if (color_type == PNG_COLOR_TYPE_PALETTE) {
			png_set_palette_to_rgb(png);
		}

		// ensure 8-bit packing
		if (bit_depth < 8) {
			png_set_packing(png);
		}
		else if (bit_depth == 16) {
			png_set_scale_16(png);
		}

		png_read_update_info(png, info);

		// read our new color type
		color_type = png_get_color_type(png, info);

		size_t row_bytes = png_get_rowbytes(png, info);

		// pull from png
		std::vector<png_byte> image;
		image.resize(row_bytes * height);

		png_bytep* row_pointers = new png_bytep[height];
		for (int i = 0; i < height; ++i)
			row_pointers[i] = image.data() + i * row_bytes;

		png_read_image(png, row_pointers);

		Texture::Format glFormat = Texture::Format::RGB8;
		if (color_type == PNG_COLOR_TYPE_RGB_ALPHA) {
			glFormat = Texture::Format::RGBA8;
		}


		texture->Create(width, height, glFormat, image);
	} else if (format == static_cast<uint32_t>(ImageFormat::DXT5)) {
		Texture::Format glFormat = Texture::Format::RGB8;
		texture->Create(1, 1, Texture::Format::R8, { 0 });
	}
	else {
		texture->Create(1, 1, Texture::Format::R8, { 0 });
	}

	file.EndChunk();
	
	return texture;
}
} // namespace Donut
