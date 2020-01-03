// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include <Render/OpenGL/VertexBuffer.h>
#include <cassert>

namespace Donut::GL
{

VertexBuffer::VertexBuffer(const void* vertices, std::size_t vertexCount, size_t strideBytes, GLuint hint)
    : _vertexCount(vertexCount), _strideBytes(strideBytes), _hint(hint)
{
	// assert(vertices != nullptr);
	assert(vertexCount > 0);
	assert(strideBytes > 0);

	glGenBuffers(1, &_vbo);
	if (glGetError() != GL_NO_ERROR)
		return;

	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexCount * strideBytes, vertices, _hint);
}

VertexBuffer::~VertexBuffer()
{
	if (_vbo != 0)
		glDeleteBuffers(1, &_vbo);
}

void VertexBuffer::UpdateBuffer(const void* data, size_t offset, size_t size)
{
	glBindBuffer(GL_ARRAY_BUFFER, _vbo);
	glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

std::size_t VertexBuffer::GetVertexCount() const noexcept
{
	return _vertexCount;
}

std::size_t VertexBuffer::GetStrideBytes() const noexcept
{
	return _strideBytes;
}

std::size_t VertexBuffer::GetSizeInBytes() const noexcept
{
	return _vertexCount * _strideBytes;
}

GLuint VertexBuffer::GetHint() const noexcept
{
	return _hint;
}

GLuint VertexBuffer::GetVBO() const noexcept
{
	return _vbo;
}

} // namespace Donut::GL
