// Copyright 2019 the donut authors. See AUTHORS.md

#include "RenderBuffer.h"

#include "FrameBuffer.h"

namespace Donut::GL
{
RenderBuffer::RenderBuffer(int width, int height, GLenum internalFormat, int samples):
    _handle(0),
    _width(width),
    _height(height),
    _internalFormat(internalFormat),
    _samples(samples)
{
	Load();
}

RenderBuffer::~RenderBuffer()
{
	Unload();
}

void RenderBuffer::Load()
{
	glGenRenderbuffers(1, &_handle);
	glBindRenderbuffer(GL_RENDERBUFFER, _handle);

	GLint maxSamples = FrameBuffer::GetMaxSamples();
	if (_samples > maxSamples)
	{
		_samples = maxSamples;
	}

	if (_samples > 0)
	{
		glRenderbufferStorageMultisample(GL_RENDERBUFFER, _samples, _internalFormat, _width, _height);
	}
	else
	{
		glRenderbufferStorage(GL_RENDERBUFFER, _internalFormat, _width, _height);
	}
}

void RenderBuffer::Unload()
{
	if (_handle)
	{
		glDeleteRenderbuffers(1, &_handle);
		_handle = 0;
	}
}
} // namespace Donut::GL
