#include <Render/OpenGL/IndexBuffer.h>
#include <cassert>

namespace Donut::GL
{

IndexBuffer::IndexBuffer(const void* indices, std::size_t indicesCount, GLenum type):
    _count(indicesCount), _type(type), _ibo(0), _hint(GL_STATIC_DRAW)
{
	assert(indices != nullptr);
	assert(indicesCount > 0);

	glGenBuffers(1, &_ibo);
	if (glGetError() != GL_NO_ERROR) return;

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _count * GetTypeSize(_type), indices, _hint);
}

IndexBuffer::~IndexBuffer()
{
	if (_ibo != 0)
		glDeleteBuffers(1, &_ibo);
}

std::size_t IndexBuffer::GetCount() const
{
	return _count;
}

std::size_t IndexBuffer::GetSize() const
{
	return _count * GetTypeSize(_type);
}

GLenum IndexBuffer::GetType() const
{
	return _type;
}

GLuint IndexBuffer::GetIBO() const
{
	return _ibo;
}

std::size_t IndexBuffer::GetTypeSize(GLenum type)
{
	switch (type)
	{
	case GL_UNSIGNED_BYTE:
		return 1;
	case GL_SHORT:
	case GL_UNSIGNED_SHORT:
		return 2;
	case GL_INT:
	case GL_UNSIGNED_INT:
	case GL_FLOAT:
		return 4;
	case GL_DOUBLE:
		return 8;
	default:
		break;
	}

	return 0;
}

} // namespace Donut::GL
