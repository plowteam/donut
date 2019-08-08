// Copyright 2019 the donut authors. See AUTHORS.md

#include "VertexBinding.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Donut::GL
{
	ArrayElement::ArrayElement(
		const VertexBuffer* buffer,
		std::size_t attributeIndex,
		std::size_t componentCount,
		ElementType type,
		std::size_t stride,
		std::size_t offset,
		std::size_t instanceStep) :
		buffer(buffer),
		attributeIndex(attributeIndex),
		componentCount(componentCount),
		type(type),
		stride(stride),
		offset(offset),
		instanceStep(instanceStep)
	{
	}

	VertexBinding::VertexBinding() :
		_handle(0),
		_indicesType(AE_UBYTE),
		_hasIndices(false)
	{
	}

	VertexBinding::~VertexBinding()
	{
		Dispose();
	}

	void VertexBinding::Create(const ArrayElement* elements, std::size_t elementCount, const VertexBuffer& vertices)
	{
		if (_handle != 0)
		{
			Dispose();
		}

		CreateVAO();

		Bind();
		SetupVertices(elements, elementCount);
		Unbind();
	}

	void VertexBinding::Create(const ArrayElement* elements, std::size_t elementCount, const IndexBuffer& indices, ElementType indicesType)
	{
		if (_handle != 0)
		{
			Dispose();
		}

		CreateVAO();

		Bind();
		SetupVertices(elements, elementCount);
		SetupIndices(indices, indicesType);
		Unbind();
	}

	void VertexBinding::Dispose()
	{
		if (_handle != 0)
		{
			glDeleteVertexArrays(1, &_handle);

			_handle = 0;
		}

		_hasIndices = false;
		_indicesType = AE_UBYTE;
	}

	void VertexBinding::Bind()
	{
		glBindVertexArray(_handle);
	}

	void VertexBinding::Unbind()
	{
		glBindVertexArray(0);
	}

	void VertexBinding::CreateVAO()
	{
		if (_handle != 0)
		{
			Dispose();
		}

		glGenVertexArrays(1, &_handle);
	}

	void VertexBinding::SetupIndices(const IndexBuffer& indices, ElementType indicesType)
	{
		_hasIndices = true;
		_indicesType = indicesType;

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices.GetIBO());
	}

	void VertexBinding::SetupVertices(const ArrayElement* elements, std::size_t elementCount)
	{
		for (std::size_t i = 0; i < elementCount; ++i)
		{
			const ArrayElement& element = elements[i];

			glBindBuffer(GL_ARRAY_BUFFER, element.buffer->GetVBO());

			GLenum type = GL_FLOAT;

			if (element.type == AE_FLOAT)
			{
				type = GL_FLOAT;
			}
			else if (element.type == AE_INT)
			{
				type = GL_INT;
			}

			glEnableVertexAttribArray((GLuint)element.attributeIndex);

			if (type == GL_INT || type == GL_UNSIGNED_INT)
			{
				glVertexAttribIPointer((GLuint)element.attributeIndex, (GLint)element.componentCount, type, (GLsizei)element.stride, (void*)element.offset);
			}
			else
			{
				glVertexAttribPointer((GLuint)element.attributeIndex, (GLint)element.componentCount, type, GL_FALSE, (GLsizei)element.stride, (void*)element.offset);
			}

			if (element.instanceStep > 0)
			{
				glVertexAttribDivisor((GLuint)element.attributeIndex, (GLuint)element.instanceStep);
			}
		}
	}
}
