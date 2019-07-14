#include "VertexBinding.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace Donut::GL
{
	ArrayElement::ArrayElement(size_t attributeIndex,
		size_t componentCount,
		ElementType type,
		size_t stride,
		size_t offset,
		size_t instanceStep) :
		attributeIndex(attributeIndex),
		componentCount(componentCount),
		type(type),
		stride(stride),
		offset(offset),
		instanceStep(instanceStep)
	{
	}

	VertexBinding::VertexBinding() :
		m_handle(0),
		m_indicesType(AE_UBYTE),
		m_hasIndices(false)
	{
	}

	VertexBinding::~VertexBinding()
	{
		Dispose();
	}

	void VertexBinding::Create(const ArrayElement* elements, size_t elementCount, const VertexBuffer& vertices)
	{
		if (m_handle != 0)
		{
			Dispose();
		}

		CreateVAO();

		Bind();
		SetupVertices(vertices, elements, elementCount);
		Unbind();
	}

	void VertexBinding::Create(const ArrayElement* elements, size_t elementCount, const VertexBuffer& vertices, const IndexBuffer& indices, ElementType indicesType)
	{
		if (m_handle != 0)
		{
			Dispose();
		}

		CreateVAO();

		Bind();
		SetupVertices(vertices, elements, elementCount);
		SetupIndices(indices, indicesType);
		Unbind();
	}

	void VertexBinding::Dispose()
	{
		if (m_handle != 0)
		{
			glDeleteVertexArrays(1, &m_handle);

			m_handle = 0;
		}

		m_hasIndices = false;
		m_indicesType = AE_UBYTE;
	}

	void VertexBinding::Bind()
	{
		glBindVertexArray(m_handle);
	}

	void VertexBinding::Unbind()
	{
		glBindVertexArray(0);
	}

	void VertexBinding::CreateVAO()
	{
		if (m_handle != 0)
		{
			Dispose();
		}

		glGenVertexArrays(1, &m_handle);
	}

	void VertexBinding::SetupIndices(const IndexBuffer& indices, ElementType indicesType)
	{
		m_hasIndices = true;
		m_indicesType = indicesType;

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indices.GetIBO());
	}

	void VertexBinding::SetupVertices(const VertexBuffer& vertices, const ArrayElement* elements, size_t elementCount)
	{
		for (size_t i = 0; i < elementCount; ++i)
		{
			const ArrayElement& element = elements[i];

			glBindBuffer(GL_ARRAY_BUFFER, vertices.GetVBO());

			GLenum type = GL_FLOAT;

			if (element.type == AE_FLOAT)
			{
				type = GL_FLOAT;
			}
			else if (element.type == AE_INT)
			{
				type = GL_INT;
			}

			glEnableVertexAttribArray(element.attributeIndex);

			if (type == GL_INT || type == GL_UNSIGNED_INT)
			{
				glVertexAttribIPointer(element.attributeIndex, element.componentCount, type, element.stride, (void*)element.offset);
			}
			else
			{
				glVertexAttribPointer(element.attributeIndex, element.componentCount, type, GL_FALSE, element.stride, (void*)element.offset);
			}

			if (element.instanceStep > 0)
			{
				glVertexAttribDivisor(element.attributeIndex, element.instanceStep);
			}
		}
	}
}
