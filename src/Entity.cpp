#include <Entity.h>

namespace Donut
{
Texture::Texture(const P3D::Texture& texture) :
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

	switch(image->GetFormat())
	{
		case 1: // PNG
		{
			auto imageData = P3D::ImageData::Decode(image->GetData());

			if (imageData.comp == 4)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData.data.data());
			else
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData.data.data());

			break;
		}
		default:
			throw std::runtime_error("non-png texture");
	}

	// generate mipmaps :)
	glGenerateMipmap(GL_TEXTURE_2D);
}

Texture::~Texture()
{
	if (_glTexture != 0)
		glDeleteTextures(1, &_glTexture);
}

StaticEntity::StaticEntity(const P3D::StaticEntity& entity)
{
	_name = entity.GetName();
	_mesh = std::make_unique<Mesh>(*entity.GetMesh());
}

void StaticEntity::Draw(const GL::ShaderProgram& shader, const ResourceManager& rm)
{
	_mesh->Draw(rm);
}


}

