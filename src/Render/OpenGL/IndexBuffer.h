// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Render/OpenGL/glad/glad.h"

#include <cstdio>
#include <memory>
#include <stdint.h>

namespace Donut::GL
{

class IndexBuffer
{
public:
	IndexBuffer() = delete;
	IndexBuffer(const IndexBuffer& other) = delete;
	IndexBuffer(IndexBuffer&&) = default;

	IndexBuffer(const void* indices, std::size_t indicesCount, GLenum type);
	~IndexBuffer();

	std::size_t GetCount() const;
	std::size_t GetSize() const;
	GLenum GetType() const;
	GLuint GetIBO() const;

private:
	std::size_t _count;
	GLenum _type;

	GLuint _ibo;
	GLuint _hint;

	static std::size_t GetTypeSize(GLenum type);
};

} // namespace Donut::GL
