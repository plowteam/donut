#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <stack>
#include <map>
#include <memory>

namespace Donut
{
	namespace GL
	{
		class VertexBinding;
		class VertexBuffer;
		class Texture2D;
		class ShaderProgram;
	}

	class SpriteBatch
	{

	public:

		SpriteBatch(size_t = 1000);

		void Flush(const glm::mat4&);
		void DrawText(const class Font*, const std::string&, const glm::vec2&, const glm::vec4&);
		void Draw(GL::Texture2D*, const glm::vec2&, float, const glm::vec4&);
		void Draw(GL::Texture2D*, const glm::vec2&, const glm::vec2&, const glm::vec4&);
		void Draw(GL::Texture2D*, const glm::vec2&, const glm::vec2&, float, const glm::vec4&);
		void Draw(GL::Texture2D*, const glm::vec2&, const glm::vec2&, const glm::vec2&, const glm::vec2&, const glm::vec4&);
		void Draw9Slice(GL::Texture2D*, const glm::vec2&, const glm::vec2&, const glm::vec4&, const glm::vec4&, bool = true);
		void Draw9Slice(GL::Texture2D*, const glm::vec2&, const glm::vec2&, const glm::vec2&, const glm::vec2&, const glm::vec4&, const glm::vec4&, bool = true);

		void EnableClipping(bool clipping) { _clipping = clipping; }
		void SetClippingRect(const glm::vec4& clippingRect) { _clippingRect = clippingRect; }

		size_t GetDrawCallCount() const { return _drawCallCount; }

		GL::ShaderProgram& GetShader();

	private:

		struct Sprite
		{
			Sprite(GL::Texture2D*, const glm::vec2&, const glm::vec2&, float, const glm::vec4&);
			Sprite(GL::Texture2D*, const glm::vec2&, const glm::vec2&, const glm::vec2&, const glm::vec2&, const glm::vec4&);

			GL::Texture2D* _texture;
			glm::vec2 _position;
			glm::vec2 _size;
			glm::vec2 _uv1;
			glm::vec2 _uv2;
			glm::vec4 _colour;
			float _angle;
		};

		struct Slice
		{
			glm::vec2 _uv1;
			glm::vec2 _uv2;
			glm::vec2 _drawPosition;
			glm::vec2 _drawSize;
		};

		struct NineSliceProperties
		{
			NineSliceProperties(
				const glm::vec2&,
				const glm::vec2&,
				const glm::vec2&,
				const glm::vec2&,
				const glm::vec2&);

			void GetTopLeftSlice(Slice&) const;
			void GetTopRightSlice(Slice&) const;
			void GetBottomLeftSlice(Slice&) const;
			void GetBottomRightSlice(Slice&) const;
			void GetTopMidSlice(Slice&) const;
			void GetBottomMidSlice(Slice&) const;
			void GetLeftMidSlice(Slice&) const;
			void GetRightMidSlice(Slice&) const;
			void GetMidSlice(Slice&) const;

			const glm::vec2 _glyphSize;
			const glm::vec2 _topLeftSlicePx;
			const glm::vec2 _bottomRightSlicePx;
			const glm::vec2 _topLeftSlice;
			const glm::vec2 _bottomRightSlice;
			const glm::vec2 _drawPosition;
			const glm::vec2 _drawSize;
		};

		void DrawSlice(GL::Texture2D*, const Slice&, const glm::vec4&);
		static void TransformUV(glm::vec2&, const glm::vec2&, const glm::vec2&, const glm::vec2&);
		static void TransformUVs(Slice&, const glm::vec2&, const glm::vec2&, const glm::vec2&);
		bool IsSpriteInsideClippingRect(const glm::vec2&, const glm::vec2&);

		std::vector<Sprite> _spritesToDraw;
		bool _clipping;
		glm::vec4 _clippingRect;
		size_t _drawCallCount;
		size_t _maxSpriteCount;
		std::vector<float> _vertexData;
		std::unique_ptr<GL::VertexBuffer> _vertexBuffer;
		std::unique_ptr<GL::VertexBinding> _vertexBinding;

		static std::unique_ptr<GL::ShaderProgram> Shader;
	};
}
