// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Render/OpenGL/glad/glad.h"

namespace Donut::GL
{
class RenderBuffer
{

public:
	RenderBuffer(int width, int height, GLenum internalFormat, int samples = 0);
	~RenderBuffer();

	inline GLuint GetHandle() const { return _handle; }
	inline int GetWidth() const { return _width; }
	inline int GetHeight() const { return _height; }
	inline GLenum GetInternalFormat() const { return _internalFormat; }
	inline int GetSamples() const { return _samples; }

private:
	void Load();
	void Unload();

	int _width;
	int _height;
	GLuint _handle;
	GLenum _internalFormat;
	int _samples;
};
} // namespace Donut::GL
