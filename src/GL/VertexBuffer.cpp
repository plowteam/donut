#include <GL/VertexBuffer.h>

#include <cassert>

namespace Donut::GL {

VertexBuffer::VertexBuffer(const void* vertices, size_t vertexCount, size_t strideBytes,
                           GLuint hint)
    : _vertexCount(vertexCount), _strideBytes(strideBytes), _hint(hint) {
    // assert(vertices != nullptr);
    assert(vertexCount > 0);
    assert(strideBytes > 0);

    glGenBuffers(1, &_vbo);
    if (glGetError() != GL_NO_ERROR)
        return;

    glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    glBufferData(GL_ARRAY_BUFFER, vertexCount * strideBytes, vertices, _hint);
}

VertexBuffer::~VertexBuffer() {
    if (_vbo != 0)
        glDeleteBuffers(1, &_vbo);
}

size_t VertexBuffer::GetVertexCount() const noexcept {
    return _vertexCount;
}

size_t VertexBuffer::GetStrideBytes() const noexcept {
    return _strideBytes;
}

size_t VertexBuffer::GetSizeInBytes() const noexcept {
    return _vertexCount * _strideBytes;
}

GLuint VertexBuffer::GetHint() const noexcept {
    return _hint;
}

GLuint VertexBuffer::GetVBO() const noexcept {
    return _vbo;
}

} // namespace Donut::GL
