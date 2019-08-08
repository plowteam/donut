#pragma once
#include <memory>
#include <string>
#include "glad/glad.h"

namespace Donut
{

// forward declare
namespace P3D {
class Sprite;
class Texture;
}

class Texture
{
  public:
	Texture(const P3D::Texture&);
	Texture(const P3D::Sprite&);
	~Texture();

	void Bind(GLenum texture) const;

	std::size_t GetWidth() const { return _width; }
	std::size_t GetHeight() const { return _height; }

	// bool HasAlpha() const;
	GLuint GetOpenGLHandle() const { return _glTexture; }

  protected:
	std::string _name;
	std::size_t _width;
	std::size_t _height;

	GLuint _glTexture;
};

using TexturePtr = std::shared_ptr<Texture>;
}
