// Copyright 2019 the donut authors. See AUTHORS.md

#include <Render/Texture.h>
#include <P3D/p3d.generated.h>

namespace Donut
{
Texture::Texture(const P3D::Texture& texture):
    _name(texture.GetName()), _width(texture.GetWidth()), _height(texture.GetHeight()),
    _glTexture(0)
{
	// more mipmaps = more images?
	assert(texture.GetNumMipMaps() == 1);

	// image handling code: move to own class?
	auto const& image = texture.GetImage();

	// generate the opengl texture, could probs do elsewhere but who cares
	glGenTextures(1, &_glTexture);
	glBindTexture(GL_TEXTURE_2D, _glTexture);

	switch (image->GetFormat())
	{
	case 1: // PNG
	{
		auto imageData = P3D::ImageData::Decode(image->GetData());

		if (imageData.comp == 4)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_width, (GLsizei)_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.data.data());
		else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_width, (GLsizei)_height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData.data.data());

		break;
	}
	default:
		throw std::runtime_error("non-png texture");
	}

	// generate mipmaps :)
	glGenerateMipmap(GL_TEXTURE_2D);
}

Texture::Texture(const P3D::Sprite& sprite):
    _name(sprite.GetName()), _width(sprite.GetWidth()), _height(sprite.GetHeight()),
    _glTexture(0)
{
	uint32_t dstRow    = 0;
	uint32_t dstColumn = 0;

	auto spriteWidth  = sprite.GetWidth();
	auto spriteHeight = sprite.GetHeight();
	std::vector<uint8_t> data((spriteWidth * spriteHeight) * 4);

	for (const auto& image : sprite.GetImages())
	{
		auto imageWidth  = image->GetWidth();
		auto imageHeight = image->GetHeight();
		auto texdata     = P3D::ImageData::Decode(image->GetData());

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

	glGenTextures(1, &_glTexture);
	glBindTexture(GL_TEXTURE_2D, _glTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, (GLsizei)_width, (GLsizei)_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data.data());
	glGenerateMipmap(GL_TEXTURE_2D);
}

Texture::~Texture()
{
	if (_glTexture != 0)
		glDeleteTextures(1, &_glTexture);
}

void Texture::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, _glTexture);
}

void Texture::Bind(GLuint slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, _glTexture);
}

} // namespace Donut
