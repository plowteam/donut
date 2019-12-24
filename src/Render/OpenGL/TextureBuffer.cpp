// Copyright 2019 the donut authors. See AUTHORS.md

#include <Render/OpenGL/TextureBuffer.h>
#include "Render/OpenGL/glad/glad.h"

namespace Donut::GL
{

TextureBuffer::TextureBuffer():
    m_handle(0),
    m_bufferHandle(0)
{
	glGenTextures(1, &m_handle);
	glGenBuffers(1, &m_bufferHandle);

	glBindBuffer(GL_TEXTURE_BUFFER, m_bufferHandle);
	glBufferData(GL_TEXTURE_BUFFER, 0, 0, GL_DYNAMIC_READ);
	glBindBuffer(GL_TEXTURE_BUFFER, 0);

	glBindTexture(GL_TEXTURE_BUFFER, m_handle);
	glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA32F, m_bufferHandle);
	glBindTexture(GL_TEXTURE_BUFFER, 0);
}

TextureBuffer::~TextureBuffer()
{
	if (m_bufferHandle != 0)
	{
		glDeleteBuffers(1, &m_bufferHandle);
		m_bufferHandle = 0;
	}

	if (m_handle != 0)
	{
		glDeleteTextures(1, &m_handle);
		m_handle = 0;
	}
}

void TextureBuffer::SetBuffer(void* buffer, size_t length)
{
	glBindBuffer(GL_TEXTURE_BUFFER, m_bufferHandle);
	glBufferData(GL_TEXTURE_BUFFER, length, buffer, GL_DYNAMIC_READ);
	glBindBuffer(GL_TEXTURE_BUFFER, 0);
}

void TextureBuffer::Bind()
{
	glBindTexture(GL_TEXTURE_BUFFER, m_handle);
}

void TextureBuffer::Unbind()
{
	glBindTexture(GL_TEXTURE_BUFFER, 0);
}

} // namespace Donut::GL
