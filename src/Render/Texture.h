#pragma once

#include "Core/Math/Vector2Int.h"
#include "OpenGL/glad/glad.h"

#include <memory>
#include <string>

namespace Donut
{

// forward declare
namespace P3D
{
class Sprite;
class Texture;
} // namespace P3D

class Texture
{
public:
	Texture(const P3D::Texture&);
	Texture(const P3D::Sprite&);
	~Texture();

	void Bind() const;
	void Bind(GLuint slot) const;

	std::size_t GetWidth() const { return _width; }
	std::size_t GetHeight() const { return _height; }
	Vector2Int GetSize() const { return Vector2Int(_width, _height); }

	// bool HasAlpha() const;
	GLuint GetOpenGLHandle() const { return _glTexture; }

protected:
	std::string _name;
	std::size_t _width;
	std::size_t _height;

	GLuint _glTexture;
};

} // namespace Donut
