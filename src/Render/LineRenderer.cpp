// Copyright 2019 the donut authors. See AUTHORS.md

#include <Render/LineRenderer.h>
#include <Skeleton.h>
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

LineRenderer::LineRenderer(size_t maxVertexCount):
    _maxVertexCount(maxVertexCount),
    _vertexCount(0)
{
	_buffer.resize(kVertexSize * _maxVertexCount, 0);

	_vertexBuffer = std::make_unique<GL::VertexBuffer>(nullptr, _maxVertexCount, kVertexSize, GL_DYNAMIC_DRAW);

	GL::ArrayElement vertexLayout[] = {
		GL::ArrayElement(_vertexBuffer.get(), 0, 3, GL::AE_FLOAT, kVertexSize, 0),
		GL::ArrayElement(_vertexBuffer.get(), 1, 4, GL::AE_FLOAT, kVertexSize, 3 * sizeof(float))
	};

	_vertexBinding = std::make_unique<GL::VertexBinding>();
	_vertexBinding->Create(vertexLayout, 2, *_vertexBuffer);

	_shader = std::make_unique<GL::ShaderProgram>(VertSrc, FragSrc);
}

void LineRenderer::Flush(glm::mat4& viewProj)
{
	if (_vertexCount < 2)
		return;

	_vertexBuffer->UpdateBuffer(_buffer.data(), 0, _vertexCount * kVertexSize);

	_shader->Bind();
	_shader->SetUniformValue("viewProj", viewProj);

	_vertexBinding->Bind();
	glDrawArrays(GL_LINES, 0, static_cast<GLsizei>(_vertexCount));
	_vertexBinding->Unbind();

	_vertexCount = 0;
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
	glm::mat4 rot       = glm::toMat4(angles);
	glm::mat4 trans     = glm::translate(glm::mat4(1.0f), position);
	glm::mat4 transform = trans * rot;

	DrawBox(transform, mins, maxs, colour);
}

void LineRenderer::DrawSphere(const glm::vec3& position, float radius, int thetaSegments, int phiSegments, const glm::vec4& colour)
{
	int theta = thetaSegments + 1;
	int phi   = phiSegments;

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

void LineRenderer::DrawCone(const glm::vec3& position, float radius, float height, std::size_t sides, const glm::vec4& colour)
{
	if (sides < 3)
		return;

	std::vector<glm::vec3> vertices;
	vertices.reserve(sides + 1);

	glm::vec3 topVertex = position + (glm::vec3(0, 1, 0) * height);

	for (std::size_t i = 0; i <= sides; ++i)
	{
		float r = glm::two_pi<float>() * (i / (float)sides);
		glm::vec3 vertex(radius * cos(r), 0.0f, radius * sin(r));
		vertices.push_back(position + vertex);
	}

	for (std::size_t i = 0; i < sides; ++i)
	{
		DrawLine(vertices[i], vertices[i + 1], colour);
		DrawLine(vertices[i], topVertex, colour);
	}
}

void LineRenderer::DrawCone(const glm::vec3& position, const glm::quat& rotation, float radius, float height, std::size_t sides, const glm::vec4& colour)
{
	if (sides < 3)
		return;

	std::vector<glm::vec3> vertices;
	vertices.reserve(sides + 1);

	glm::vec3 topVertex = position + (rotation * glm::vec3(0, height, 0));

	for (std::size_t i = 0; i <= sides; ++i)
	{
		float r = glm::two_pi<float>() * (i / (float)sides);
		glm::vec3 vertex(radius * cos(r), 0.0f, radius * sin(r));
		vertices.push_back(position + (rotation * vertex));
	}

	for (std::size_t i = 0; i < sides; ++i)
	{
		DrawLine(vertices[i], vertices[i + 1], colour);
		DrawLine(vertices[i], topVertex, colour);
	}
}

void LineRenderer::DrawSkeleton(const glm::vec3& position, const Skeleton& skeleton)
{
	auto const& joints = skeleton.GetJoints();
	for (auto const& joint : joints)
	{
		auto const& parent = joints[joint.parent];

		glm::mat4 mParent = glm::translate(position) * parent.pose;
		glm::mat4 mJoint  = glm::translate(position) * joint.pose;

		const glm::vec4 lineColor(1.0f, 1.0f, 1.0f, 1.0f);
		const glm::vec4 sphereColor(0.0f, 1.0f, 0.0f, 1.0f);

		DrawSphere(glm::vec3(mJoint[3]), 0.025f, 4, 4, sphereColor);
		DrawLine(glm::vec3(mParent[3]), glm::vec3(mJoint[3]), lineColor);
	}
}

void LineRenderer::BufferVertex(const glm::vec3& position, const glm::vec4& colour)
{
	if (_vertexCount >= _maxVertexCount)
		return;

	uint8_t* vertexData                           = &_buffer[_vertexCount * kVertexSize];
	*(glm::vec3*)(vertexData)                     = position;
	*(glm::vec4*)(vertexData + sizeof(glm::vec3)) = colour;

	_vertexCount++;
}
} // namespace Donut
