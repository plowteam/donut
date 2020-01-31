// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#include "Texture.h"

#include "Core/Log.h"
#include "Render/OpenGL/glad/gl.h"

#include <P3D/P3D.generated.h>

namespace Donut
{

Texture::Texture(): _width(0), _height(0), _format(Format::RGB8), _texture(0)
{
	// todo: generic renderer implementation
	glGenTextures(1, &_texture);
}

Texture::~Texture()
{
	Log::Debug("Deleting texture '{}' with id {}\n", GetName(), _texture);

	// todo: generic renderer implementation
	if (_texture != 0)
		glDeleteTextures(1, &_texture);
}

// todo: generic renderer implementation
void Texture::Create(int width, int height, Format format, const std::vector<uint8_t>& data)
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, _texture);

	GLenum glFormat;
	GLenum glInternalFormat;
	GLenum glType;
	int bytes_per_pixel;

	switch (format)
	{
	case Format::RGB8:
		glFormat = GL_RGB;
		glInternalFormat = GL_RGB8;
		glType = GL_UNSIGNED_BYTE;
		bytes_per_pixel = 3;
		break;
	case Format::RGBA8:
		glFormat = GL_RGBA;
		glInternalFormat = GL_RGBA8;
		glType = GL_UNSIGNED_BYTE;
		bytes_per_pixel = 4;
		break;
	default:
		Log::Debug("unknown format {}\n", format);
		break;
	}

	// upload
	glTexImage2D(GL_TEXTURE_2D, 0, glInternalFormat, width, height, 0, glFormat, glType, data.data());

	// generate mipmaps for everything at the moment, maybe this isn't wanted in future though
	// core in 4.6 ?
	glGenerateMipmap(GL_TEXTURE_2D);

	_width = width;
	_height = height;
	_memorySize = width * height * bytes_per_pixel;
	_format = format;
}

void Texture::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, _texture);
}

void Texture::Bind(GLuint slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, _texture);
}

Texture::Texture(const P3D::Texture& texture)
    : _width(texture.GetWidth()), _height(texture.GetHeight()), _texture(0)
{
	Log::Debug("Creating legacy P3D::Texture {}\n", texture.GetName());
	SetName(texture.GetName());

	// more mipmaps = more images?
	assert(texture.GetNumMipMaps() == 1);

	// image handling code: move to own class?
	auto const& image = texture.GetImage();

	// generate the opengl texture, could probs do elsewhere but who cares
	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);

	switch (image->GetFormat())
	{
	case 1: // PNG
	{
		auto imageData = P3D::ImageDecoder::Decode(image->GetData());

		if (imageData.comp == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_width, (GLsizei)_height, 0, GL_RGBA, GL_UNSIGNED_BYTE,
			             imageData.data.data());
		else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_width, (GLsizei)_height, 0, GL_RGB, GL_UNSIGNED_BYTE,
			             imageData.data.data());

		_memorySize = imageData.data.size();

		break;
	}
	default: throw std::runtime_error("non-png texture");
	}

	// generate mipmaps :)
	glGenerateMipmap(GL_TEXTURE_2D);
}

Texture::Texture(const P3D::Sprite& sprite)
    : _width(sprite.GetWidth()), _height(sprite.GetHeight()), _texture(0)
{
	SetName(sprite.GetName());

	uint32_t dstRow = 0;
	uint32_t dstColumn = 0;

	auto spriteWidth = sprite.GetWidth();
	auto spriteHeight = sprite.GetHeight();
	std::vector<uint8_t> data((spriteWidth * spriteHeight) * 4);

	for (const auto& image : sprite.GetImages())
	{
		auto imageWidth = image->GetWidth();
		auto imageHeight = image->GetHeight();
		auto texdata = P3D::ImageDecoder::Decode(image->GetData());

		for (uint32_t row = 0; row < imageHeight - 2; ++row)
		{
			if ((dstRow + row) >= spriteHeight)
			{
				continue;
			}

			auto dstIndex = (dstRow + row) * (spriteWidth * 4);
			dstIndex += dstColumn * 4;

			auto rowDataSize = (imageWidth - 2) * 4;
			if ((spriteWidth - dstColumn) < (imageWidth - 2))
			{
				rowDataSize = (spriteWidth - dstColumn) * 4;
			}

			std::memcpy(&data[dstIndex], &texdata.data[row * (imageWidth * 4)], rowDataSize);
		}

		dstColumn += imageWidth - 2;
		if (dstColumn >= spriteWidth)
		{
			dstColumn = 0;
			dstRow += imageHeight - 2;
		}
	}

	glGenTextures(1, &_texture);
	glBindTexture(GL_TEXTURE_2D, _texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data.data());
	glGenerateMipmap(GL_TEXTURE_2D);

	_memorySize = data.size();
}

} // namespace Donut
