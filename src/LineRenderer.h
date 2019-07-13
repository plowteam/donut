#pragma once

#include <GL/VertexBuffer.h>
#include <GL/ShaderProgram.h>
#include <glm/glm.hpp>
#include <vector>

namespace Donut
{
	class LineRenderer
	{

	public:

		LineRenderer(size_t maxVertexCount);

		void Flush(glm::mat4& viewProj);
		void DrawLine(const glm::vec3& p1, const glm::vec3& p2, const glm::vec4& colour);
		void DrawBox(const glm::mat4 transform, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour);
		void DrawBox(const glm::vec3& position, const glm::vec3& angles, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour);
		void DrawBox(const glm::vec3& position, const glm::quat& angles, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour);
		void DrawAABBox(const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour);
		void DrawAABBox(const glm::vec3& position, const glm::vec3& mins, const glm::vec3& maxs, const glm::vec4& colour);
		void DrawSphere(const glm::vec3& position, float radius, int thetaSegments, int phiSegments, const glm::vec4& colour);
		void DrawCone(const glm::vec3& position, float radius, float height, size_t sides, const glm::vec4& colour);
		void DrawCone(const glm::vec3& position, const glm::quat& rotation, float radius, float height, size_t sides, const glm::vec4& colour);

		inline size_t GetVertexCount() const { return m_vertexCount; }
		inline size_t GetMaxVertexCount() const { return m_maxVertexCount; }

	private:

		void BufferVertex(const glm::vec3& position, const glm::vec4& colour);

		size_t m_vertexCount;
		size_t m_maxVertexCount;

		GLuint m_vertexArrayObject;
		std::unique_ptr<GL::VertexBuffer> m_vertexBuffer;
		std::vector<char> m_buffer;
		static const size_t VERTEX_ATTRIB_STRIDE;
		std::unique_ptr<GL::ShaderProgram> _shader;
	};
}
