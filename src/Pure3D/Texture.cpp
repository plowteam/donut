// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#include "Texture.h"

#include "Core/Log.h"
#include "Render/OpenGL/glad/gl.h"

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

} // namespace Donut
