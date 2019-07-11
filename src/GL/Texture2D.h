#pragma once

#include <glad/glad.h>

namespace Donut::GL
{

class Texture2D
{
  public:
	Texture2D() = delete;
	Texture2D(GLsizei width, GLsizei height, GLenum internalFormat, GLenum format, GLenum type, const void* textureData);
	~Texture2D();

	inline void Bind() const
	{
		glBindTexture(GL_TEXTURE_2D, _textureID);
	}

	inline void Bind(unsigned char slot) const
	{
		glActiveTexture(GL_TEXTURE0 + slot);
		glBindTexture(GL_TEXTURE_2D, _textureID);
	}

	const GLuint GetHandle() const { return _textureID; }
	const GLsizei GetWidth() const { return _width; }
	const GLsizei GetHeight() const { return _height; }

  private:
	GLuint _textureID;
	GLsizei _width;
	GLsizei _height;
	GLenum _internalFormat;
	GLenum _format;
	GLenum _type;
};

} // namespace Donut::GL
