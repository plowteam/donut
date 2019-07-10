#pragma once

#include <vector>

namespace Donut::GL {

class TextureBuffer {

public:
    struct Data {
        Data();

        typedef std::vector<unsigned char> Buffer;

        unsigned int m_target;
        Buffer m_buffer;
    };

    TextureBuffer();
	~TextureBuffer();

    void Bind();
    void Unbind();

    void SetBuffer(void* buffer, unsigned int length);
    void SetBuffer(Data::Buffer& buffer);

    inline Data::Buffer& GetBuffer() {
        return m_data.m_buffer;
    }

protected:
    virtual void Load();
    virtual void Unload();
    virtual void Update();

    Data m_data;
    GLuint m_handle;
    GLuint m_bufferHandle;
};
} // namespace Donut::GL
