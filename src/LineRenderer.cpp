#include "LineRenderer.h"
#include <glm/gtc/constants.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/transform.hpp>

namespace Donut
{
	std::string VertSrc = R"glsl(
	#version 150 core

	in vec3 position;
	in vec4 color;

	out vec4 vertColor;

	uniform mat4 viewProj;

	void main()
	{
		vertColor = color;
		gl_Position = viewProj * vec4(position, 1.0);
	}
)glsl";

	std::string FragSrc = R"glsl(
	#version 150 core

	in vec4 vertColor;

	out vec4 outColor;

	void main()
	{
        outColor = vertColor;
	}
)glsl";

	const size_t LineRenderer::VERTEX_ATTRIB_STRIDE = 28;

	LineRenderer::LineRenderer(size_t maxVertexCount) :
		m_maxVertexCount(maxVertexCount),
		m_vertexCount(0)
	{
		m_buffer.resize(VERTEX_ATTRIB_STRIDE * m_maxVertexCount, 0);

		glGenVertexArrays(1, &m_vertexArrayObject);
		glBindVertexArray(m_vertexArrayObject);

		m_vertexBuffer = std::make_unique<GL::VertexBuffer>(nullptr, m_maxVertexCount, VERTEX_ATTRIB_STRIDE);

		std::size_t ptr = 0;
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, VERTEX_ATTRIB_STRIDE, reinterpret_cast<GLvoid*>(ptr)); // pos
		ptr += sizeof(glm::vec3);
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, VERTEX_ATTRIB_STRIDE, reinterpret_cast<GLvoid*>(ptr)); // color
		ptr += sizeof(glm::vec4);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glBindVertexArray(0);

		_shader = std::make_unique<GL::ShaderProgram>(VertSrc, FragSrc);
	}

	void LineRenderer::Flush(glm::mat4& viewProj)
	{
		if (m_vertexCount < 2)
		{
			return;
		}

		m_vertexBuffer->UpdateBuffer(m_buffer.data(), 0, m_vertexCount * VERTEX_ATTRIB_STRIDE);

		_shader->Bind();
		_shader->SetUniformValue("viewProj", viewProj);

		glBindVertexArray(m_vertexArrayObject);
		glDrawArrays(GL_LINES, 0, (GLsizei)m_vertexCount);
		glBindVertexArray(0);

		m_vertexCount = 0;
	}

	void LineRenderer::DrawLine(const glm::vec3& p1, const glm::vec3& p2, const glm::vec4& colour)
	{
		BufferVertex(p1, colour);
		BufferVertex(p2, colour);
	}

	void LineRenderer::DrawBox(const glm::mat4 transform, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour)
	{
		DrawLine(transform * glm::vec4(mins.x, mins.y, mins.z, 1), transform * glm::vec4(maxs.x, mins.y, mins.z, 1), colour);
		DrawLine(transform * glm::vec4(maxs.x, mins.y, mins.z, 1), transform * glm::vec4(maxs.x, maxs.y, mins.z, 1), colour);
		DrawLine(transform * glm::vec4(maxs.x, maxs.y, mins.z, 1), transform * glm::vec4(mins.x, maxs.y, mins.z, 1), colour);
		DrawLine(transform * glm::vec4(mins.x, maxs.y, mins.z, 1), transform * glm::vec4(mins.x, mins.y, mins.z, 1), colour);
		DrawLine(transform * glm::vec4(mins.x, mins.y, mins.z, 1), transform * glm::vec4(mins.x, mins.y, maxs.z, 1), colour);
		DrawLine(transform * glm::vec4(maxs.x, mins.y, mins.z, 1), transform * glm::vec4(maxs.x, mins.y, maxs.z, 1), colour);
		DrawLine(transform * glm::vec4(maxs.x, maxs.y, mins.z, 1), transform * glm::vec4(maxs.x, maxs.y, maxs.z, 1), colour);
		DrawLine(transform * glm::vec4(mins.x, maxs.y, mins.z, 1), transform * glm::vec4(mins.x, maxs.y, maxs.z, 1), colour);
		DrawLine(transform * glm::vec4(mins.x, mins.y, maxs.z, 1), transform * glm::vec4(maxs.x, mins.y, maxs.z, 1), colour);
		DrawLine(transform * glm::vec4(maxs.x, mins.y, maxs.z, 1), transform * glm::vec4(maxs.x, maxs.y, maxs.z, 1), colour);
		DrawLine(transform * glm::vec4(maxs.x, maxs.y, maxs.z, 1), transform * glm::vec4(mins.x, maxs.y, maxs.z, 1), colour);
		DrawLine(transform * glm::vec4(mins.x, maxs.y, maxs.z, 1), transform * glm::vec4(mins.x, mins.y, maxs.z, 1), colour);
	}

	void LineRenderer::DrawAABBox(const glm::vec3& position, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour)
	{
		DrawAABBox(position + mins, position + maxs, colour);
	}

	void LineRenderer::DrawAABBox(const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour)
	{
		DrawLine(glm::vec3(mins.x, mins.y, mins.z), glm::vec3(maxs.x, mins.y, mins.z), colour);
		DrawLine(glm::vec3(maxs.x, mins.y, mins.z), glm::vec3(maxs.x, maxs.y, mins.z), colour);
		DrawLine(glm::vec3(maxs.x, maxs.y, mins.z), glm::vec3(mins.x, maxs.y, mins.z), colour);
		DrawLine(glm::vec3(mins.x, maxs.y, mins.z), glm::vec3(mins.x, mins.y, mins.z), colour);
		DrawLine(glm::vec3(mins.x, mins.y, mins.z), glm::vec3(mins.x, mins.y, maxs.z), colour);
		DrawLine(glm::vec3(maxs.x, mins.y, mins.z), glm::vec3(maxs.x, mins.y, maxs.z), colour);
		DrawLine(glm::vec3(maxs.x, maxs.y, mins.z), glm::vec3(maxs.x, maxs.y, maxs.z), colour);
		DrawLine(glm::vec3(mins.x, maxs.y, mins.z), glm::vec3(mins.x, maxs.y, maxs.z), colour);
		DrawLine(glm::vec3(mins.x, mins.y, maxs.z), glm::vec3(maxs.x, mins.y, maxs.z), colour);
		DrawLine(glm::vec3(maxs.x, mins.y, maxs.z), glm::vec3(maxs.x, maxs.y, maxs.z), colour);
		DrawLine(glm::vec3(maxs.x, maxs.y, maxs.z), glm::vec3(mins.x, maxs.y, maxs.z), colour);
		DrawLine(glm::vec3(mins.x, maxs.y, maxs.z), glm::vec3(mins.x, mins.y, maxs.z), colour);
	}

	void LineRenderer::DrawBox(const glm::vec3& position, const glm::vec3& angles, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour)
	{
		DrawBox(position, glm::quat(glm::radians(angles)), mins, maxs, colour);
	}

	void LineRenderer::DrawBox(const glm::vec3& position, const glm::quat& angles, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour)
	{
		glm::mat4 rot = glm::toMat4(angles);
		glm::mat4 trans = glm::translate(glm::mat4(1.0f), position);
		glm::mat4 transform = trans * rot;

		DrawBox(transform, mins, maxs, colour);
	}

	void LineRenderer::DrawSphere(const glm::vec3& position, float radius, int thetaSegments, int phiSegments, const glm::vec4& colour)
	{
		int theta = thetaSegments + 1;
		int phi = phiSegments;

		std::vector<glm::vec3> vertices;
		vertices.reserve(phi * theta);

		for (int i = 0; i < phi; ++i)
		{
			for (int j = 0; j < theta; ++j)
			{
				float u = j / (float)(theta - 1);
				float v = i / (float)(phi - 1);
				float t = glm::two_pi<float>() * u;
				float p = glm::pi<float>() * v;

				glm::vec3 vertex(radius * sin(p) * cos(t),
					radius * cos(p),
					radius * sin(p) * sin(t));

				vertex += position;

				vertices.push_back(vertex);
			}
		}

		for (int i = 0; i < phi - 1; ++i)
		{
			for (int j = 0; j < theta - 1; ++j)
			{
				int index = theta * i + j;

				DrawLine(vertices[index], vertices[index + theta], colour);
				DrawLine(vertices[index], vertices[index + 1], colour);
			}
		}
	}

	void LineRenderer::DrawCone(const glm::vec3& position, float radius, float height, size_t sides, const glm::vec4& colour)
	{
		if (sides < 3)
		{
			return;
		}

		std::vector<glm::vec3> vertices;
		vertices.reserve(sides + 1);

		glm::vec3 topVertex = position + (glm::vec3(0, 1, 0) * height);

		for (size_t i = 0; i <= sides; ++i)
		{
			float r = glm::two_pi<float>() * (i / (float)sides);
			glm::vec3 vertex(radius * cos(r), 0.0f, radius * sin(r));
			vertices.push_back(position + vertex);
		}

		for (size_t i = 0; i < sides; ++i)
		{
			DrawLine(vertices[i], vertices[i + 1], colour);
			DrawLine(vertices[i], topVertex, colour);
		}
	}

	void LineRenderer::DrawCone(const glm::vec3& position, const glm::quat& rotation, float radius, float height, size_t sides, const glm::vec4& colour)
	{
		if (sides < 3)
		{
			return;
		}

		std::vector<glm::vec3> vertices;
		vertices.reserve(sides + 1);

		glm::vec3 topVertex = position + (rotation * glm::vec3(0, height, 0));

		for (size_t i = 0; i <= sides; ++i)
		{
			float r = glm::two_pi<float>() * (i / (float)sides);
			glm::vec3 vertex(radius * cos(r), 0.0f, radius * sin(r));
			vertices.push_back(position + (rotation * vertex));
		}

		for (size_t i = 0; i < sides; ++i)
		{
			DrawLine(vertices[i], vertices[i + 1], colour);
			DrawLine(vertices[i], topVertex, colour);
		}
	}

	void LineRenderer::BufferVertex(const glm::vec3& position, const glm::vec4& colour)
	{
		if (m_vertexCount >= m_maxVertexCount)
		{
			return;
		}

		char* vertexData = &m_buffer[m_vertexCount * VERTEX_ATTRIB_STRIDE];
		*(glm::vec3*)(vertexData) = position;
		*(glm::vec4*)(vertexData + sizeof(glm::vec3)) = colour;

		m_vertexCount++;
	}
}
