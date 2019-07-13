#include "SpriteBatch.h"
#include "GL/Texture2D.h"
#include "GL/VertexBuffer.h"
#include "GL/VertexBinding.h"

namespace Donut
{
	std::string SpriteBatchVertSrc = R"glsl(
		#version 150 core

		in vec2 vert_position;
		in vec2 vert_texcoord;
		in vec4 vert_color;

		out vec2 frag_texcoord;
		out vec4 frag_color;

		uniform mat4 projMatrix;

		void main()
		{
			frag_texcoord = vert_texcoord;
			frag_color = vert_color;
			gl_Position = projMatrix * vec4(vert_position.xy, 1.0, 1.0);
		}
	)glsl";

	std::string SpriteBatchFragSrc = R"glsl(
		#version 150 core

		uniform sampler2D texture;

		in vec2 frag_texcoord;
		in vec4 frag_color;

		out vec4 outColor;

		void main()
		{
			outColor = frag_color;
		}
	)glsl";

	std::unique_ptr<GL::ShaderProgram> SpriteBatch::Shader = nullptr;

	GL::ShaderProgram* SpriteBatch::GetShader()
	{
		if (Shader == nullptr)
		{
			Shader = std::make_unique<GL::ShaderProgram>(SpriteBatchVertSrc, SpriteBatchFragSrc);
		}

		return Shader.get();
	}

	SpriteBatch::Sprite::Sprite(
		GL::Texture2D* texture,
		const glm::vec2& position,
		const glm::vec2& size,
		float angle,
		const glm::vec4& colour) :
		m_texture(texture),
		m_position(position),
		m_size(size),
		m_uv1(0, 1),
		m_uv2(1, 0),
		m_colour(colour),
		m_angle(angle)
	{
	}

	SpriteBatch::Sprite::Sprite(
		GL::Texture2D* texture,
		const glm::vec2& position,
		const glm::vec2& size,
		const glm::vec2& uv1,
		const glm::vec2& uv2,
		const glm::vec4& colour) :
		m_texture(texture),
		m_position(position),
		m_size(size),
		m_uv1(uv1),
		m_uv2(uv2),
		m_colour(colour),
		m_angle(0.0f)
	{
	}

	SpriteBatch::SpriteBatch() :
		m_clipping(false),
		m_drawCallCount(0)
	{
	}

	void SpriteBatch::Begin()
	{
		m_spritesToDraw.clear();
		m_drawCallCount = 0;
	}

	void SpriteBatch::Draw(
		GL::Texture2D* texture,
		const glm::vec2& position,
		float angle,
		const glm::vec4& colour)
	{
		m_spritesToDraw.push_back(Sprite(texture, position, texture->GetSize(), angle, colour));
	}

	void SpriteBatch::Draw(
		GL::Texture2D* texture,
		const glm::vec2& position,
		const glm::vec2& size,
		const glm::vec4& colour)
	{
		float u1 = 0.0f;
		float v1 = 1.0f;
		float u2 = 1.0f;
		float v2 = 0.0f;
		glm::vec2 newPosition = position;
		glm::vec2 newSize = size;

		if (m_clipping)
		{
			if (!IsSpriteInsideClippingRect(position, size))
			{
				return;
			}

			float newleft = glm::clamp(position.x, (float)m_clippingRect.x, (float)m_clippingRect.z);
			float newtop = glm::clamp(position.y, (float)m_clippingRect.y, (float)m_clippingRect.w);
			float newright = glm::clamp(position.x + size.x, (float)m_clippingRect.x, (float)m_clippingRect.z);
			float newbottom = glm::clamp(position.y + size.y, (float)m_clippingRect.y, (float)m_clippingRect.w);

			newPosition = glm::vec2(newleft, newtop);
			newSize = glm::vec2(newright - newleft, newbottom - newtop);

			float difleft = newleft - position.x;
			float diftop = newtop - position.y;
			float difright = newright - (position.x + size.x);
			float difbottom = newbottom - (position.y + size.y);

			difleft /= size.x;
			diftop /= size.y;
			difright /= size.x;
			difbottom /= size.y;

			float uwidth = u2 - u1;
			float vheight = v2 - v1;

			u1 = u1 + (uwidth * difleft);
			u2 = u2 + (uwidth * difright);
			v1 = v1 + (vheight * diftop);
			v2 = v2 + (vheight * difbottom);
		}

		m_spritesToDraw.push_back(Sprite(texture, newPosition, newSize, glm::vec2(u1, v1), glm::vec2(u2, v2), colour));
	}

	void SpriteBatch::Draw(
		GL::Texture2D* texture,
		const glm::vec2& position,
		const glm::vec2& size,
		float angle,
		const glm::vec4& colour)
	{
		m_spritesToDraw.push_back(Sprite(texture, position, size, angle, colour));
	}

	void SpriteBatch::Draw(
		GL::Texture2D* texture,
		const glm::vec2& position,
		const glm::vec2& uv1,
		const glm::vec2& uv2,
		const glm::vec2& size,
		const glm::vec4& colour)
	{
		float u1 = uv1.x;
		float v1 = uv1.y;
		float u2 = uv2.x;
		float v2 = uv2.y;
		glm::vec2 newPosition = position;
		glm::vec2 newSize = size;

		if (m_clipping)
		{
			if (!IsSpriteInsideClippingRect(position, size))
			{
				return;
			}

			float newleft = glm::clamp(position.x, (float)m_clippingRect.x, (float)m_clippingRect.z);
			float newtop = glm::clamp(position.y, (float)m_clippingRect.y, (float)m_clippingRect.w);
			float newright = glm::clamp(position.x + size.x, (float)m_clippingRect.x, (float)m_clippingRect.z);
			float newbottom = glm::clamp(position.y + size.y, (float)m_clippingRect.y, (float)m_clippingRect.w);

			newPosition = glm::vec2(newleft, newtop);
			newSize = glm::vec2(newright - newleft, newbottom - newtop);

			float difleft = newleft - position.x;
			float diftop = newtop - position.y;
			float difright = newright - (position.x + size.x);
			float difbottom = newbottom - (position.y + size.y);

			difleft /= size.x;
			diftop /= size.y;
			difright /= size.x;
			difbottom /= size.y;

			float uwidth = u2 - u1;
			float vheight = v2 - v1;

			u1 = u1 + (uwidth * difleft);
			u2 = u2 + (uwidth * difright);
			v1 = v1 + (vheight * diftop);
			v2 = v2 + (vheight * difbottom);
		}

		m_spritesToDraw.push_back(Sprite(texture, newPosition, newSize, glm::vec2(u1, v1), glm::vec2(u2, v2), colour));
	}

	SpriteBatch::NineSliceProperties::NineSliceProperties(
		const glm::vec2& topLeftSlicePx,
		const glm::vec2& bottomRightSlicePx,
		const glm::vec2& glyphSize,
		const glm::vec2& drawPosition,
		const glm::vec2& drawSize) :
		m_topLeftSlicePx(topLeftSlicePx),
		m_bottomRightSlicePx(bottomRightSlicePx),
		m_topLeftSlice(topLeftSlicePx / glyphSize),
		m_bottomRightSlice(bottomRightSlicePx / glyphSize),
		m_glyphSize(glyphSize),
		m_drawPosition(drawPosition),
		m_drawSize(drawSize)
	{

	}

	void SpriteBatch::DrawSlice(GL::Texture2D* texture, const SpriteBatch::Slice& slice, const glm::vec4& colour)
	{
		Draw(texture, slice.m_drawPosition, slice.m_uv1, slice.m_uv2, slice.m_drawSize, colour);
	}

	void SpriteBatch::NineSliceProperties::GetTopLeftSlice(Slice& slice) const
	{
		slice.m_uv1.x = 0.0f;
		slice.m_uv1.y = 1.0f;
		slice.m_uv2.x = m_topLeftSlice.x;
		slice.m_uv2.y = 1.0f - m_topLeftSlice.y;
		slice.m_drawPosition = m_drawPosition;
		slice.m_drawSize = m_topLeftSlicePx;
	}

	void SpriteBatch::NineSliceProperties::GetTopRightSlice(Slice& slice) const
	{
		slice.m_uv1.x = 1.0f - m_bottomRightSlice.x;
		slice.m_uv1.y = 1.0f;
		slice.m_uv2.x = 1.0f;
		slice.m_uv2.y = 1.0f - m_topLeftSlice.y;
		slice.m_drawPosition.x = m_drawPosition.x + m_drawSize.x - m_bottomRightSlicePx.x;
		slice.m_drawPosition.y = m_drawPosition.y;
		slice.m_drawSize.x = m_bottomRightSlicePx.x;
		slice.m_drawSize.y = m_topLeftSlicePx.y;
	}

	void SpriteBatch::NineSliceProperties::GetBottomLeftSlice(Slice& slice) const
	{
		slice.m_uv1.x = 0.0f;
		slice.m_uv1.y = m_bottomRightSlice.y;
		slice.m_uv2.x = m_topLeftSlice.x;
		slice.m_uv2.y = 0.0f;
		slice.m_drawPosition.x = m_drawPosition.x;
		slice.m_drawPosition.y = m_drawPosition.y + m_drawSize.y - m_bottomRightSlicePx.y;
		slice.m_drawSize.x = m_topLeftSlicePx.x;
		slice.m_drawSize.y = m_bottomRightSlicePx.y;
	}

	void SpriteBatch::NineSliceProperties::GetBottomRightSlice(Slice& slice) const
	{
		slice.m_uv1.x = 1.0f - m_bottomRightSlice.x;
		slice.m_uv1.y = m_bottomRightSlice.y;
		slice.m_uv2.x = 1.0f;
		slice.m_uv2.y = 0.0f;
		slice.m_drawPosition = m_drawPosition + m_drawSize - m_bottomRightSlicePx;
		slice.m_drawSize = m_bottomRightSlicePx;
	}

	void SpriteBatch::NineSliceProperties::GetTopMidSlice(Slice& slice) const
	{
		slice.m_uv1.x = m_topLeftSlice.x;
		slice.m_uv1.y = 1.0f;
		slice.m_uv2.x = 1.0f - m_bottomRightSlice.x;
		slice.m_uv2.y = 1.0f - m_topLeftSlice.y;
		slice.m_drawPosition.x = m_drawPosition.x + m_topLeftSlicePx.x;
		slice.m_drawPosition.y = m_drawPosition.y;
		slice.m_drawSize.x = m_drawSize.x - m_topLeftSlicePx.x - m_bottomRightSlicePx.x;
		slice.m_drawSize.y = m_topLeftSlicePx.y;
	}

	void SpriteBatch::NineSliceProperties::GetBottomMidSlice(Slice& slice) const
	{
		slice.m_uv1.x = m_topLeftSlice.x;
		slice.m_uv1.y = m_bottomRightSlice.y;
		slice.m_uv2.x = 1.0f - m_bottomRightSlice.x;
		slice.m_uv2.y = 0.0f;
		slice.m_drawPosition.x = m_drawPosition.x + m_topLeftSlicePx.x;
		slice.m_drawPosition.y = m_drawPosition.y + m_drawSize.y - m_bottomRightSlicePx.y;
		slice.m_drawSize.x = m_drawSize.x - m_topLeftSlicePx.x - m_bottomRightSlicePx.x;
		slice.m_drawSize.y = m_bottomRightSlicePx.y;
	}

	void SpriteBatch::NineSliceProperties::GetLeftMidSlice(Slice& slice) const
	{
		slice.m_uv1.x = 0.0f;
		slice.m_uv1.y = 1.0f - m_topLeftSlice.y;
		slice.m_uv2.x = m_topLeftSlice.x;
		slice.m_uv2.y = m_bottomRightSlice.y;
		slice.m_drawPosition.x = m_drawPosition.x;
		slice.m_drawPosition.y = m_drawPosition.y + m_topLeftSlicePx.y;
		slice.m_drawSize.x = m_topLeftSlicePx.x;
		slice.m_drawSize.y = m_drawSize.y - m_bottomRightSlicePx.y - m_topLeftSlicePx.y;
	}

	void SpriteBatch::NineSliceProperties::GetRightMidSlice(Slice& slice) const
	{
		slice.m_uv1.x = 1.0f - m_bottomRightSlice.x;
		slice.m_uv1.y = 1.0f - m_topLeftSlice.y;
		slice.m_uv2.x = 1.0f;
		slice.m_uv2.y = m_bottomRightSlice.y;
		slice.m_drawPosition.x = m_drawPosition.x + m_drawSize.x - m_bottomRightSlicePx.x;
		slice.m_drawPosition.y = m_drawPosition.y + m_topLeftSlicePx.y;
		slice.m_drawSize.x = m_bottomRightSlicePx.x;
		slice.m_drawSize.y = m_drawSize.y - m_bottomRightSlicePx.y - m_topLeftSlicePx.y;
	}

	void SpriteBatch::NineSliceProperties::GetMidSlice(Slice& slice) const
	{
		slice.m_uv1.x = m_topLeftSlice.x;
		slice.m_uv1.y = 1.0f - m_topLeftSlice.y;
		slice.m_uv2.x = 1.0f - m_bottomRightSlice.x;
		slice.m_uv2.y = m_bottomRightSlice.y;
		slice.m_drawPosition = m_drawPosition + m_topLeftSlicePx;
		slice.m_drawSize = m_drawSize - m_topLeftSlicePx - m_bottomRightSlicePx;
	}

	void SpriteBatch::Draw9Slice(
		GL::Texture2D* texture,
		const glm::vec2& position,
		const glm::vec2& size,
		const glm::vec4& margin,
		const glm::vec4& colour,
		bool drawCenter)
	{
		Slice slice;
		const NineSliceProperties properties(glm::vec2(margin.x, margin.y), glm::vec2(margin.z, margin.w), texture->GetSize(), position, size);

		properties.GetTopLeftSlice(slice);
		DrawSlice(texture, slice, colour);

		properties.GetTopRightSlice(slice);
		DrawSlice(texture, slice, colour);

		properties.GetBottomLeftSlice(slice);
		DrawSlice(texture, slice, colour);

		properties.GetBottomRightSlice(slice);
		DrawSlice(texture, slice, colour);

		properties.GetTopMidSlice(slice);
		DrawSlice(texture, slice, colour);

		properties.GetBottomMidSlice(slice);
		DrawSlice(texture, slice, colour);

		properties.GetLeftMidSlice(slice);
		DrawSlice(texture, slice, colour);

		properties.GetRightMidSlice(slice);
		DrawSlice(texture, slice, colour);

		if (drawCenter)
		{
			properties.GetMidSlice(slice);
			DrawSlice(texture, slice, colour);
		}
	}

	void SpriteBatch::TransformUV(glm::vec2& uv, const glm::vec2& glyphSize, const glm::vec2& offset, const glm::vec2& sheetSize)
	{
		uv = glm::vec2(offset.x, sheetSize.y - offset.y - glyphSize.y) / sheetSize + uv * glyphSize / sheetSize;
	}

	void SpriteBatch::TransformUVs(Slice& slice, const glm::vec2& glyphSize, const glm::vec2& offset, const glm::vec2& sheetSize)
	{
		TransformUV(slice.m_uv1, glyphSize, offset, sheetSize);
		TransformUV(slice.m_uv2, glyphSize, offset, sheetSize);
	}

	void SpriteBatch::Draw9Slice(
		GL::Texture2D* texture,
		const glm::vec2& position,
		const glm::vec2& size,
		const glm::vec2& glyphPosition,
		const glm::vec2& glyphSize,
		const glm::vec4& margin,
		const glm::vec4& colour,
		bool drawCenter)
	{
		Slice slice;
		const glm::vec2& sheetSize = texture->GetSize();
		const NineSliceProperties properties(glm::vec2(margin.x, margin.y), glm::vec2(margin.z, margin.w), glyphSize, position, size);

		properties.GetTopLeftSlice(slice);
		TransformUVs(slice, glyphSize, glyphPosition, sheetSize);
		DrawSlice(texture, slice, colour);

		properties.GetTopRightSlice(slice);
		TransformUVs(slice, glyphSize, glyphPosition, sheetSize);
		DrawSlice(texture, slice, colour);

		properties.GetBottomLeftSlice(slice);
		TransformUVs(slice, glyphSize, glyphPosition, sheetSize);
		DrawSlice(texture, slice, colour);

		properties.GetBottomRightSlice(slice);
		TransformUVs(slice, glyphSize, glyphPosition, sheetSize);
		DrawSlice(texture, slice, colour);

		properties.GetTopMidSlice(slice);
		TransformUVs(slice, glyphSize, glyphPosition, sheetSize);
		DrawSlice(texture, slice, colour);

		properties.GetBottomMidSlice(slice);
		TransformUVs(slice, glyphSize, glyphPosition, sheetSize);
		DrawSlice(texture, slice, colour);

		properties.GetLeftMidSlice(slice);
		TransformUVs(slice, glyphSize, glyphPosition, sheetSize);
		DrawSlice(texture, slice, colour);

		properties.GetRightMidSlice(slice);
		TransformUVs(slice, glyphSize, glyphPosition, sheetSize);
		DrawSlice(texture, slice, colour);

		if (drawCenter)
		{
			properties.GetMidSlice(slice);
			TransformUVs(slice, glyphSize, glyphPosition, sheetSize);
			DrawSlice(texture, slice, colour);
		}
	}

	void SpriteBatch::End(const glm::mat4& proj)
	{
		if (m_spritesToDraw.empty())
		{
			return;
		}

		glDisable(GL_DEPTH_TEST);

		GL::ShaderProgram* shader = GetShader();
		shader->Bind();
		shader->SetUniformValue("projMatrix", proj);

		static const size_t vertSize = 8;
		static const size_t faceVertCount = 6;
		static const size_t vertStride = vertSize * sizeof(float);

		GL::ArrayElement vertexLayout[3] =
		{
			GL::ArrayElement(0, 2, GL::AE_FLOAT, vertStride, 0),
			GL::ArrayElement(1, 2, GL::AE_FLOAT, vertStride, 2 * sizeof(float)),
			GL::ArrayElement(2, 4, GL::AE_FLOAT, vertStride, 4 * sizeof(float)),
		};

		GL::VertexBuffer vertexBuffer(nullptr, m_spritesToDraw.size() * faceVertCount, vertStride);
		GL::VertexBinding vertexBinding;
		vertexBinding.Create(vertexLayout, 3, vertexBuffer);
		vertexBinding.Bind();

		unsigned int basePos = 0;

		while (basePos < m_spritesToDraw.size())
		{
			unsigned int searchPos = basePos;
			GL::Texture2D* batchTexture = m_spritesToDraw[basePos].m_texture;

			while (searchPos < m_spritesToDraw.size() && m_spritesToDraw[searchPos].m_texture == batchTexture)
			{
				searchPos++;
			}

			std::vector<float> vertexData((searchPos - basePos) * faceVertCount * vertSize);

			if (batchTexture != nullptr)
			{
				batchTexture->Bind(0);
			}

			for (size_t i = basePos; i < searchPos; ++i)
			{
				float* buffer = &vertexData[(i - basePos) * faceVertCount * vertSize];
				Sprite& sprite = m_spritesToDraw[i];

				for (size_t j = 0; j < faceVertCount; ++j)
				{
					buffer[4 + vertSize * j] = sprite.m_colour.x;
					buffer[5 + vertSize * j] = sprite.m_colour.y;
					buffer[6 + vertSize * j] = sprite.m_colour.z;
					buffer[7 + vertSize * j] = sprite.m_colour.w;
				}

				glm::vec2 vertexPositions[4] =
				{
					glm::vec2(-(sprite.m_size.x / 2), -(sprite.m_size.y / 2)),
					glm::vec2(-(sprite.m_size.x / 2), sprite.m_size.y / 2),
					glm::vec2(sprite.m_size.x / 2, sprite.m_size.y / 2),
					glm::vec2(sprite.m_size.x / 2, -(sprite.m_size.y / 2)),
				};

				glm::vec2 vertexTextureCoords[4] =
				{
					glm::vec2(sprite.m_uv1.x, sprite.m_uv1.y),
					glm::vec2(sprite.m_uv1.x, sprite.m_uv2.y),
					glm::vec2(sprite.m_uv2.x, sprite.m_uv2.y),
					glm::vec2(sprite.m_uv2.x, sprite.m_uv1.y),
				};

				for (size_t j = 0; j < 4; ++j)
				{
					float cosAngle = glm::cos(glm::radians(sprite.m_angle));
					float sinAngle = glm::sin(glm::radians(sprite.m_angle));

					glm::vec2 p = vertexPositions[j];
					vertexPositions[j].x = p.x * cosAngle - p.y * sinAngle;
					vertexPositions[j].y = p.y * cosAngle + p.x * sinAngle;
					vertexPositions[j] += sprite.m_position + (sprite.m_size * 0.5f);
				}

				unsigned int faceIndices[] = { 0, 1, 2, 2, 3, 0 };

				for (size_t j = 0; j < faceVertCount; ++j)
				{
					size_t bufferIndex = j * vertSize;
					size_t vertexIndex = faceIndices[j];

					buffer[bufferIndex] = vertexPositions[vertexIndex].x;
					buffer[bufferIndex + 1] = vertexPositions[vertexIndex].y;
					buffer[bufferIndex + 2] = vertexTextureCoords[vertexIndex].x;
					buffer[bufferIndex + 3] = vertexTextureCoords[vertexIndex].y;
				}
			}

			vertexBuffer.UpdateBuffer(&vertexData[0], 0, (searchPos - basePos) * faceVertCount * vertStride);

			glDrawArrays(GL_TRIANGLES, 0, (GLsizei)((searchPos - basePos) * faceVertCount));

			m_drawCallCount++;

			basePos = searchPos;
		}

		vertexBinding.Unbind();
		shader->Unbind();

		glEnable(GL_DEPTH_TEST);
	}

	bool SpriteBatch::IsSpriteInsideClippingRect(const glm::vec2& position, const glm::vec2& size)
	{
		return !((position.x >= m_clippingRect.z) ||
				 (position.x + size.x <= m_clippingRect.x) ||
				 (position.y >= m_clippingRect.w) ||
				 (position.y + size.y <= m_clippingRect.y));
	}
}
