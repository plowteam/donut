// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "LineRenderer.h"

#include "Core/Math/Math.h"
#include "Core/Math/Matrix3x3.h"
#include "Core/Math/Matrix4x4.h"
#include "Core/Math/Quaternion.h"
#include "Core/Math/Vector3.h"
#include "Core/Math/Vector4.h"

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

LineRenderer::LineRenderer(size_t maxVertexCount): _maxVertexCount(maxVertexCount), _vertexCount(0)
{
	_buffer.resize(kVertexSize * _maxVertexCount, 0);

	_vertexBuffer = std::make_unique<GL::VertexBuffer>(nullptr, _maxVertexCount, kVertexSize, GL_DYNAMIC_DRAW);

	GL::ArrayElement vertexLayout[] = {
	    GL::ArrayElement(_vertexBuffer.get(), 0, 3, GL::AE_FLOAT, kVertexSize, 0),
	    GL::ArrayElement(_vertexBuffer.get(), 1, 4, GL::AE_FLOAT, kVertexSize, 3 * sizeof(float))};

	_vertexBinding = std::make_unique<GL::VertexBinding>();
	_vertexBinding->Create(vertexLayout, 2, *_vertexBuffer);

	_shader = std::make_unique<GL::ShaderProgram>(VertSrc, FragSrc);
}

void LineRenderer::Flush(Matrix4x4& viewProj)
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

void LineRenderer::DrawLine(const Vector3& p1, const Vector3& p2, const Vector4& colour)
{
	BufferVertex(p1, colour);
	BufferVertex(p2, colour);
}

void LineRenderer::DrawBox(const Matrix4x4 transform, const Vector3& mins, const Vector3& maxs, const Vector4& colour)
{
	// DrawLine(transform * Vector4(mins.X, mins.Y, mins.Z, 1), transform * Vector4(maxs.X, mins.Y, mins.Z, 1), colour);
	// DrawLine(transform * Vector4(maxs.X, mins.Y, mins.Z, 1), transform * Vector4(maxs.X, maxs.Y, mins.Z, 1), colour);
	// DrawLine(transform * Vector4(maxs.X, maxs.Y, mins.Z, 1), transform * Vector4(mins.X, maxs.Y, mins.Z, 1), colour);
	// DrawLine(transform * Vector4(mins.X, maxs.Y, mins.Z, 1), transform * Vector4(mins.X, mins.Y, mins.Z, 1), colour);
	// DrawLine(transform * Vector4(mins.X, mins.Y, mins.Z, 1), transform * Vector4(mins.X, mins.Y, maxs.Z, 1), colour);
	// DrawLine(transform * Vector4(maxs.X, mins.Y, mins.Z, 1), transform * Vector4(maxs.X, mins.Y, maxs.Z, 1), colour);
	// DrawLine(transform * Vector4(maxs.X, maxs.Y, mins.Z, 1), transform * Vector4(maxs.X, maxs.Y, maxs.Z, 1), colour);
	// DrawLine(transform * Vector4(mins.X, maxs.Y, mins.Z, 1), transform * Vector4(mins.X, maxs.Y, maxs.Z, 1), colour);
	// DrawLine(transform * Vector4(mins.X, mins.Y, maxs.Z, 1), transform * Vector4(maxs.X, mins.Y, maxs.Z, 1), colour);
	// DrawLine(transform * Vector4(maxs.X, mins.Y, maxs.Z, 1), transform * Vector4(maxs.X, maxs.Y, maxs.Z, 1), colour);
	// DrawLine(transform * Vector4(maxs.X, maxs.Y, maxs.Z, 1), transform * Vector4(mins.X, maxs.Y, maxs.Z, 1), colour);
	// DrawLine(transform * Vector4(mins.X, maxs.Y, maxs.Z, 1), transform * Vector4(mins.X, mins.Y, maxs.Z, 1), colour);
}

void LineRenderer::DrawAABBox(const Vector3& position, const Vector3& mins, const Vector3& maxs, const Vector4& colour)
{
	DrawAABBox(position + mins, position + maxs, colour);
}

void LineRenderer::DrawAABBox(const Vector3& mins, const Vector3& maxs, const Vector4& colour)
{
	DrawLine(Vector3(mins.X, mins.Y, mins.Z), Vector3(maxs.X, mins.Y, mins.Z), colour);
	DrawLine(Vector3(maxs.X, mins.Y, mins.Z), Vector3(maxs.X, maxs.Y, mins.Z), colour);
	DrawLine(Vector3(maxs.X, maxs.Y, mins.Z), Vector3(mins.X, maxs.Y, mins.Z), colour);
	DrawLine(Vector3(mins.X, maxs.Y, mins.Z), Vector3(mins.X, mins.Y, mins.Z), colour);
	DrawLine(Vector3(mins.X, mins.Y, mins.Z), Vector3(mins.X, mins.Y, maxs.Z), colour);
	DrawLine(Vector3(maxs.X, mins.Y, mins.Z), Vector3(maxs.X, mins.Y, maxs.Z), colour);
	DrawLine(Vector3(maxs.X, maxs.Y, mins.Z), Vector3(maxs.X, maxs.Y, maxs.Z), colour);
	DrawLine(Vector3(mins.X, maxs.Y, mins.Z), Vector3(mins.X, maxs.Y, maxs.Z), colour);
	DrawLine(Vector3(mins.X, mins.Y, maxs.Z), Vector3(maxs.X, mins.Y, maxs.Z), colour);
	DrawLine(Vector3(maxs.X, mins.Y, maxs.Z), Vector3(maxs.X, maxs.Y, maxs.Z), colour);
	DrawLine(Vector3(maxs.X, maxs.Y, maxs.Z), Vector3(mins.X, maxs.Y, maxs.Z), colour);
	DrawLine(Vector3(mins.X, maxs.Y, maxs.Z), Vector3(mins.X, mins.Y, maxs.Z), colour);
}

void LineRenderer::DrawBox(const Vector3& position, const Vector3& angles, const Vector3& mins, const Vector3& maxs,
                           const Vector4& colour)
{
	// DrawBox(position, Quaternion(Math::DegreesToRadians(angles)), mins, maxs, colour);
}

void LineRenderer::DrawBox(const Vector3& position, const Quaternion& angles, const Vector3& mins, const Vector3& maxs,
                           const Vector4& colour)
{
	// Matrix4x4 transform = Matrix4x4::MakeTranslate(position) * angles;

	DrawBox(Matrix4x4::Identity, mins, maxs, colour);
}

void LineRenderer::DrawSphere(const Vector3& position, float radius, int thetaSegments, int phiSegments, const Vector4& colour)
{
	int theta = thetaSegments + 1;
	int phi = phiSegments;

	std::vector<Vector3> vertices;
	vertices.reserve(phi * theta);

	for (int i = 0; i < phi; ++i)
	{
		for (int j = 0; j < theta; ++j)
		{
			float u = j / (float)(theta - 1);
			float v = i / (float)(phi - 1);
			float t = Math::Pi2 * u;
			float p = Math::Pi * v;

			Vector3 vertex(radius * sin(p) * cos(t), radius * cos(p), radius * sin(p) * sin(t));

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

void LineRenderer::DrawCone(const Vector3& position, float radius, float height, std::size_t sides, const Vector4& colour)
{
	if (sides < 3)
		return;

	std::vector<Vector3> vertices;
	vertices.reserve(sides + 1);

	Vector3 topVertex = position + (Vector3(0, 1, 0) * height);

	for (std::size_t i = 0; i <= sides; ++i)
	{
		float r = Math::Pi2 * (i / (float)sides);
		Vector3 vertex(radius * cos(r), 0.0f, radius * sin(r));
		vertices.push_back(position + vertex);
	}

	for (std::size_t i = 0; i < sides; ++i)
	{
		DrawLine(vertices[i], vertices[i + 1], colour);
		DrawLine(vertices[i], topVertex, colour);
	}
}

void LineRenderer::DrawCone(const Vector3& position, const Quaternion& rotation, float radius, float height, std::size_t sides,
                            const Vector4& colour)
{
	if (sides < 3)
		return;

	std::vector<Vector3> vertices;
	vertices.reserve(sides + 1);

	Vector3 topVertex = position + (rotation * Vector3(0, height, 0));

	for (std::size_t i = 0; i <= sides; ++i)
	{
		float r = Math::Pi2 * (i / (float)sides);
		Vector3 vertex(radius * cos(r), 0.0f, radius * sin(r));
		vertices.push_back(position + (rotation * vertex));
	}

	for (std::size_t i = 0; i < sides; ++i)
	{
		DrawLine(vertices[i], vertices[i + 1], colour);
		DrawLine(vertices[i], topVertex, colour);
	}
}

void LineRenderer::BufferVertex(const Vector3& position, const Vector4& colour)
{
	if (_vertexCount >= _maxVertexCount)
		return;

	uint8_t* vertexData = &_buffer[_vertexCount * kVertexSize];
	*(Vector3*)(vertexData) = position;
	*(Vector4*)(vertexData + sizeof(Vector3)) = colour;

	_vertexCount++;
}
} // namespace Donut
