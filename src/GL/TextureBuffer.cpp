#include <GL/TextureBuffer.h>
#include <glad/glad.h>

namespace Donut::GL {

TextureBuffer::Data::Data() : m_target(GL_TEXTURE_BUFFER) {}

TextureBuffer::TextureBuffer() : m_handle(0), m_bufferHandle(0) {
    Load();
}

TextureBuffer::~TextureBuffer() {
    Unload();
}

void TextureBuffer::Load() {
    glGenTextures(1, &m_handle);
    glGenBuffers(1, &m_bufferHandle);
	
	glBindTexture(m_data.m_target, m_handle);
    glTexBuffer(m_data.m_target, GL_RGBA32F, m_bufferHandle);
    glBindTexture(m_data.m_target, 0);
}

void TextureBuffer::Unload() {

    if (m_bufferHandle != 0) {
        glDeleteBuffers(1, &m_bufferHandle);
        m_bufferHandle = 0;
    }

    if (m_handle != 0) {
        glDeleteTextures(1, &m_handle);
        m_handle = 0;
    }
}

void TextureBuffer::Update() {
    glBindBuffer(m_data.m_target, m_bufferHandle);
    glBufferData(m_data.m_target, m_data.m_buffer.size(), &m_data.m_buffer[0], GL_DYNAMIC_READ);
    glBindBuffer(m_data.m_target, 0);
}

void TextureBuffer::SetBuffer(void* buffer, unsigned int length) {
    if (m_data.m_buffer.size() != length) {
        m_data.m_buffer.clear();
        m_data.m_buffer.resize(length);
    }

    memcpy(&m_data.m_buffer[0], buffer, length);

    Update();
}

void TextureBuffer::SetBuffer(Data::Buffer& buffer) {
    SetBuffer((unsigned char*)&buffer[0], buffer.size());
}

void TextureBuffer::Bind() {
    glBindTexture(m_data.m_target, m_handle);
}

void TextureBuffer::Unbind() {
    glBindTexture(m_data.m_target, 0);
}

} // namespace Donut::GL
