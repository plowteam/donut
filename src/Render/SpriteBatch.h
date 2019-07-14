#pragma once

#include <glm/glm.hpp>
#include <Render/OpenGL/Texture2D.h>
#include <Render/OpenGL/ShaderProgram.h>
#include <P3D/TextureFont.h>
#include <vector>
#include <stack>
#include <map>
#include <memory>

namespace Donut
{
	class SpriteBatch
	{

	public:

		SpriteBatch();

		void Begin();
		void End(const glm::mat4& proj);
		void DrawText(P3D::TextureFont* font, const std::string& text, const glm::vec2& position, const glm::vec4& colour);
		void Draw(GL::Texture2D* texture, const glm::vec2& position, float angle, const glm::vec4& colour);
		void Draw(GL::Texture2D* texture, const glm::vec2& position, const glm::vec2& size, const glm::vec4& colour);
		void Draw(GL::Texture2D* texture, const glm::vec2& position, const glm::vec2& size, float angle, const glm::vec4& colour);
		void Draw(GL::Texture2D* texture, const glm::vec2& position, const glm::vec2& uv1, const glm::vec2& uv2, const glm::vec2& size, const glm::vec4& colour);
		void Draw9Slice(GL::Texture2D* texture, const glm::vec2& position, const glm::vec2& size, const glm::vec4& margin, const glm::vec4& colour, bool drawCenter = true);
		void Draw9Slice(GL::Texture2D* texture, const glm::vec2& position, const glm::vec2& size, const glm::vec2& glyphPosition, const glm::vec2& glyphSize, const glm::vec4& margin, const glm::vec4& colour, bool drawCenter = true);
		inline void EnableClipping(bool clipping) { m_clipping = clipping; }

		inline void SetClippingRect(const glm::vec4& clippingRect) { m_clippingRect = clippingRect; }

		inline unsigned int GetDrawCallCount() const { return m_drawCallCount; }

		GL::ShaderProgram* GetShader();

	private:

		struct Sprite
		{
			Sprite(GL::Texture2D* texture, const glm::vec2& position, const glm::vec2& size, float angle, const glm::vec4& colour);
			Sprite(GL::Texture2D* texture, const glm::vec2& position, const glm::vec2& size, const glm::vec2& uv1, const glm::vec2& uv2, const glm::vec4& colour);

			GL::Texture2D* m_texture;
			glm::vec2 m_position;
			glm::vec2 m_size;
			glm::vec2 m_uv1;
			glm::vec2 m_uv2;
			glm::vec4 m_colour;
			float m_angle;
		};

		struct Slice
		{
			glm::vec2 m_uv1;
			glm::vec2 m_uv2;
			glm::vec2 m_drawPosition;
			glm::vec2 m_drawSize;
		};

		struct NineSliceProperties
		{
			NineSliceProperties(
				const glm::vec2& topLeftSlicePx,
				const glm::vec2& bottomRightSlicePx,
				const glm::vec2& glyphSize,
				const glm::vec2& drawPosition,
				const glm::vec2& drawSize);

			void GetTopLeftSlice(Slice& slice) const;
			void GetTopRightSlice(Slice& slice) const;
			void GetBottomLeftSlice(Slice& slice) const;
			void GetBottomRightSlice(Slice& slice) const;
			void GetTopMidSlice(Slice& slice) const;
			void GetBottomMidSlice(Slice& slice) const;
			void GetLeftMidSlice(Slice& slice) const;
			void GetRightMidSlice(Slice& slice) const;
			void GetMidSlice(Slice& slice) const;

			const glm::vec2 m_glyphSize;
			const glm::vec2 m_topLeftSlicePx;
			const glm::vec2 m_bottomRightSlicePx;
			const glm::vec2 m_topLeftSlice;
			const glm::vec2 m_bottomRightSlice;
			const glm::vec2 m_drawPosition;
			const glm::vec2 m_drawSize;
		};

		void DrawSlice(GL::Texture2D* texture, const Slice& slice, const glm::vec4& colour);
		static void TransformUV(glm::vec2& uv, const glm::vec2& glyphSize, const glm::vec2& offset, const glm::vec2& sheetSize);
		static void TransformUVs(Slice& slice, const glm::vec2& glyphSize, const glm::vec2& offset, const glm::vec2& sheetSize);

		bool IsSpriteInsideClippingRect(const glm::vec2& position, const glm::vec2& size);

		std::vector<Sprite> m_spritesToDraw;
		bool m_clipping;
		glm::vec4 m_clippingRect;
		unsigned int m_drawCallCount;

		static std::unique_ptr<GL::ShaderProgram> Shader;
	};
}
