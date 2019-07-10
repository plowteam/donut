#pragma once

#include <cstdio>
#include <memory>
#include <stdint.h>
#include <glad/glad.h>

namespace Donut::GL {

class IndexBuffer
{
  public:
	IndexBuffer()                         = delete;
	IndexBuffer(const IndexBuffer& other) = delete;
	IndexBuffer(IndexBuffer&&)            = default;

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
