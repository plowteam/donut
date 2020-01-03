// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Render/OpenGL/glad/glad.h"
#include <cstddef>

namespace Donut::GL
{
class VertexBuffer;
class IndexBuffer;

enum ElementType
{
	AE_FLOAT = GL_FLOAT,
	AE_INT = GL_INT,
	AE_UBYTE = GL_UNSIGNED_BYTE,
	AE_UINT = GL_UNSIGNED_INT,
	AE_USHORT = GL_UNSIGNED_SHORT,
};

struct ArrayElement
{
	ArrayElement(const VertexBuffer* buffer, std::size_t attributeIndex, std::size_t componentCount, ElementType type,
	             std::size_t stride, std::size_t offset, std::size_t instanceStep = 0);

	const VertexBuffer* buffer;
	std::size_t attributeIndex;
	std::size_t componentCount;
	ElementType type;
	std::size_t stride;
	std::size_t offset;
	std::size_t instanceStep;
};

class VertexBinding
{

public:
	explicit VertexBinding();
	~VertexBinding();

	void Create(const ArrayElement* elements, std::size_t elementCount, const VertexBuffer& vertices);
	void Create(const ArrayElement* elements, std::size_t elementCount, const IndexBuffer& indices, ElementType indicesType);
	void Dispose();
	void Bind();
	void Unbind();

private:
	void CreateVAO();
	void SetupVertices(const ArrayElement* elements, std::size_t elementCount);
	void SetupIndices(const IndexBuffer& indices, ElementType indicesType);

	GLuint _handle;
	ElementType _indicesType;
	bool _hasIndices;
};
} // namespace Donut::GL
