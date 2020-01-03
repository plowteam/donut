// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Fwd.h"
#include "Render/OpenGL/ShaderProgram.h"
#include "Render/OpenGL/VertexBinding.h"
#include "Render/OpenGL/VertexBuffer.h"

#include <vector>

namespace Donut
{
class Skeleton;

class LineRenderer
{
public:
	LineRenderer(std::size_t maxVertexCount);

	void DrawLine(const Vector3& p1, const Vector3& p2, const Vector4& colour);
	void DrawBox(const Matrix4x4 transform, const Vector3& mins, const Vector3& maxs, const Vector4& colour);
	void DrawBox(const Vector3& position, const Vector3& angles, const Vector3& mins, const Vector3& maxs,
	             const Vector4& colour);
	void DrawBox(const Vector3& position, const Quaternion& angles, const Vector3& mins, const Vector3& maxs,
	             const Vector4& colour);
	void DrawAABBox(const Vector3& mins, const Vector3& maxs, const Vector4& colour);
	void DrawAABBox(const Vector3& position, const Vector3& mins, const Vector3& maxs, const Vector4& colour);
	void DrawSphere(const Vector3& position, float radius, int thetaSegments, int phiSegments, const Vector4& colour);
	void DrawCone(const Vector3& position, float radius, float height, std::size_t sides, const Vector4& colour);
	void DrawCone(const Vector3& position, const Quaternion& rotation, float radius, float height, std::size_t sides,
	              const Vector4& colour);
	void DrawSkeleton(const Vector3& position, const Skeleton& skeleton);

	void Flush(Matrix4x4& viewProj);

	std::size_t GetVertexCount() const { return _vertexCount; }
	std::size_t GetMaxVertexCount() const { return _maxVertexCount; }

private:
	void BufferVertex(const Vector3& position, const Vector4& colour);

	static inline const std::size_t kVertexSize = 28;
	std::size_t _vertexCount;
	std::size_t _maxVertexCount;

	std::unique_ptr<GL::VertexBuffer> _vertexBuffer;
	std::unique_ptr<GL::VertexBinding> _vertexBinding;
	std::vector<uint8_t> _buffer;
	std::unique_ptr<GL::ShaderProgram> _shader;
};
} // namespace Donut
