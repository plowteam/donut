// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Render/OpenGL/glad/glad.h"
#include <vector>

namespace Donut::GL
{

class TextureBuffer
{

public:
	TextureBuffer();
	~TextureBuffer();

	void Bind();
	void Unbind();
	void SetBuffer(void* buffer, size_t length);

protected:
	GLuint m_handle;
	GLuint m_bufferHandle;
};
} // namespace Donut::GL
