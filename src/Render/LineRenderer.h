// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

#include <Render/OpenGL/ShaderProgram.h>
#include <Render/OpenGL/VertexBinding.h>
#include <Render/OpenGL/VertexBuffer.h>
#include <glm/glm.hpp>
#include <vector>

namespace Donut
{
class Skeleton;

class LineRenderer
{
  public:
	LineRenderer(std::size_t maxVertexCount);

	void DrawLine(const glm::vec3& p1, const glm::vec3& p2, const glm::vec4& colour);
	void DrawBox(const glm::mat4 transform, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour);
	void DrawBox(const glm::vec3& position, const glm::vec3& angles, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour);
	void DrawBox(const glm::vec3& position, const glm::quat& angles, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour);
	void DrawAABBox(const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour);
	void DrawAABBox(const glm::vec3& position, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour);
	void DrawSphere(const glm::vec3& position, float radius, int thetaSegments, int phiSegments, const glm::vec4& colour);
	void DrawCone(const glm::vec3& position, float radius, float height, std::size_t sides, const glm::vec4& colour);
	void DrawCone(const glm::vec3& position, const glm::quat& rotation, float radius, float height, std::size_t sides, const glm::vec4& colour);
	void DrawSkeleton(const glm::vec3& position, const Skeleton& skeleton);

	void Flush(glm::mat4& viewProj);

	std::size_t GetVertexCount() const { return _vertexCount; }
	std::size_t GetMaxVertexCount() const { return _maxVertexCount; }

  private:
	void BufferVertex(const glm::vec3& position, const glm::vec4& colour);

	static inline const std::size_t kVertexSize = 28;
	std::size_t _vertexCount;
	std::size_t _maxVertexCount;

	std::unique_ptr<GL::VertexBuffer> _vertexBuffer;
	std::unique_ptr<GL::VertexBinding> _vertexBinding;
	std::vector<uint8_t> _buffer;
	std::unique_ptr<GL::ShaderProgram> _shader;
};
} // namespace Donut
