// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "SpriteBatch.h"

#include "Core/Math/Math.h"
#include "Render/Font.h"
#include "Render/OpenGL/ShaderProgram.h"
#include "Render/OpenGL/VertexBinding.h"
#include "Render/OpenGL/VertexBuffer.h"
#include "Render/Texture.h"

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
			outColor = texture2D(texture, frag_texcoord) * frag_color;
		}
	)glsl";

std::unique_ptr<GL::ShaderProgram> SpriteBatch::Shader = nullptr;

GL::ShaderProgram& SpriteBatch::GetShader()
{
	if (Shader == nullptr)
		Shader = std::make_unique<GL::ShaderProgram>(SpriteBatchVertSrc, SpriteBatchFragSrc);

	return *Shader;
}

void SpriteBatch::DrawText(const Font* font, const std::string& text, const Vector2& position, const Vector4& colour)
{
	if (font == nullptr)
		return;

	Font::Glyph glyph;
	Vector2 curPosition = position;
	float fontHeight = font->GetHeight();

	for (const char& c : text)
	{
		if (c == '\n')
		{
			curPosition.X = position.X;
			curPosition.Y += fontHeight;
			continue;
		}

		if (!font->TryGetGlyph(c, glyph))
			continue;

		Texture* glyphTexture = font->GetTexture(glyph.textureId);

		Draw(glyphTexture, curPosition + Vector2(glyph.leftBearing), Vector2(glyph.bottomLeftX, 1.0f - glyph.topRightY),
		     Vector2(glyph.topRightX, 1.0f - glyph.bottomLeftY), Vector2(glyph.width, fontHeight), colour);

		curPosition += Vector2(glyph.advance, 0);
	}
}

SpriteBatch::Sprite::Sprite(Texture* texture, const Vector2& position, const Vector2& size, float angle, const Vector4& colour)
    : _texture(texture), _position(position), _size(size), _uv1(0, 1), _uv2(1, 0), _colour(colour), _angle(angle)
{
}

SpriteBatch::Sprite::Sprite(Texture* texture, const Vector2& position, const Vector2& size, const Vector2& uv1,
                            const Vector2& uv2, const Vector4& colour)
    : _texture(texture), _position(position), _size(size), _uv1(uv1), _uv2(uv2), _colour(colour), _angle(0.0f)
{
}

SpriteBatch::SpriteBatch(size_t maxSpriteCount): _clipping(false), _drawCallCount(0), _maxSpriteCount(maxSpriteCount)
{
	static const size_t vertSize = 8;
	static const size_t faceVertCount = 6;
	static const size_t vertStride = vertSize * sizeof(float);

	_vertexBuffer = std::make_unique<GL::VertexBuffer>(nullptr, _maxSpriteCount * faceVertCount, vertStride, GL_DYNAMIC_DRAW);

	GL::ArrayElement vertexLayout[] = {
	    GL::ArrayElement(_vertexBuffer.get(), 0, 2, GL::AE_FLOAT, vertStride, 0),
	    GL::ArrayElement(_vertexBuffer.get(), 1, 2, GL::AE_FLOAT, vertStride, 2 * sizeof(float)),
	    GL::ArrayElement(_vertexBuffer.get(), 2, 4, GL::AE_FLOAT, vertStride, 4 * sizeof(float)),
	};

	_vertexBinding = std::make_unique<GL::VertexBinding>();
	_vertexBinding->Create(vertexLayout, 3, *_vertexBuffer);

	_vertexData.resize(_maxSpriteCount * faceVertCount * vertSize);
}

void SpriteBatch::Draw(Texture* texture, const Vector2& position, float angle, const Vector4& colour)
{
	_spritesToDraw.push_back(Sprite(texture, position, Vector2(texture->GetSize()), angle, colour));
}

void SpriteBatch::Draw(Texture* texture, const Vector2& position, const Vector2& size, const Vector4& colour)
{
	float u1 = 0.0f;
	float v1 = 0.0f;
	float u2 = 1.0f;
	float v2 = 1.0f;
	Vector2 newPosition = position;
	Vector2 newSize = size;

	if (_clipping)
	{
		if (!IsSpriteInsideClippingRect(position, size))
		{
			return;
		}

		float newleft = Math::Clamp(position.X, (float)_clippingRect.X, (float)_clippingRect.Z);
		float newtop = Math::Clamp(position.Y, (float)_clippingRect.Y, (float)_clippingRect.W);
		float newright = Math::Clamp(position.X + size.X, (float)_clippingRect.X, (float)_clippingRect.Z);
		float newbottom = Math::Clamp(position.Y + size.Y, (float)_clippingRect.Y, (float)_clippingRect.W);

		newPosition = Vector2(newleft, newtop);
		newSize = Vector2(newright - newleft, newbottom - newtop);

		float difleft = newleft - position.X;
		float diftop = newtop - position.Y;
		float difright = newright - (position.X + size.X);
		float difbottom = newbottom - (position.Y + size.Y);

		difleft /= size.X;
		diftop /= size.Y;
		difright /= size.X;
		difbottom /= size.Y;

		float uwidth = u2 - u1;
		float vheight = v2 - v1;

		u1 = u1 + (uwidth * difleft);
		u2 = u2 + (uwidth * difright);
		v1 = v1 + (vheight * diftop);
		v2 = v2 + (vheight * difbottom);
	}

	_spritesToDraw.push_back(Sprite(texture, newPosition, newSize, Vector2(u1, v1), Vector2(u2, v2), colour));
}

void SpriteBatch::Draw(Texture* texture, const Vector2& position, const Vector2& size, float angle, const Vector4& colour)
{
	_spritesToDraw.push_back(Sprite(texture, position, size, angle, colour));
}

void SpriteBatch::Draw(Texture* texture, const Vector2& position, const Vector2& uv1, const Vector2& uv2, const Vector2& size,
                       const Vector4& colour)
{
	float u1 = uv1.X;
	float v1 = uv1.Y;
	float u2 = uv2.X;
	float v2 = uv2.Y;
	Vector2 newPosition = position;
	Vector2 newSize = size;

	if (_clipping)
	{
		if (!IsSpriteInsideClippingRect(position, size))
		{
			return;
		}

		float newleft = Math::Clamp(position.X, (float)_clippingRect.X, (float)_clippingRect.Z);
		float newtop = Math::Clamp(position.Y, (float)_clippingRect.Y, (float)_clippingRect.W);
		float newright = Math::Clamp(position.X + size.X, (float)_clippingRect.X, (float)_clippingRect.Z);
		float newbottom = Math::Clamp(position.Y + size.Y, (float)_clippingRect.Y, (float)_clippingRect.W);

		newPosition = Vector2(newleft, newtop);
		newSize = Vector2(newright - newleft, newbottom - newtop);

		float difleft = newleft - position.X;
		float diftop = newtop - position.Y;
		float difright = newright - (position.X + size.X);
		float difbottom = newbottom - (position.Y + size.Y);

		difleft /= size.X;
		diftop /= size.Y;
		difright /= size.X;
		difbottom /= size.Y;

		float uwidth = u2 - u1;
		float vheight = v2 - v1;

		u1 = u1 + (uwidth * difleft);
		u2 = u2 + (uwidth * difright);
		v1 = v1 + (vheight * diftop);
		v2 = v2 + (vheight * difbottom);
	}

	_spritesToDraw.push_back(Sprite(texture, newPosition, newSize, Vector2(u1, v1), Vector2(u2, v2), colour));
}

SpriteBatch::NineSliceProperties::NineSliceProperties(const Vector2& topLeftSlicePx, const Vector2& bottomRightSlicePx,
                                                      const Vector2& glyphSize, const Vector2& drawPosition,
                                                      const Vector2& drawSize)
    : _topLeftSlicePx(topLeftSlicePx), _bottomRightSlicePx(bottomRightSlicePx), _topLeftSlice(topLeftSlicePx / glyphSize),
      _bottomRightSlice(bottomRightSlicePx / glyphSize), _glyphSize(glyphSize), _drawPosition(drawPosition), _drawSize(drawSize)
{
}

void SpriteBatch::DrawSlice(Texture* texture, const SpriteBatch::Slice& slice, const Vector4& colour)
{
	Draw(texture, slice._drawPosition, slice._uv1, slice._uv2, slice._drawSize, colour);
}

void SpriteBatch::NineSliceProperties::GetTopLeftSlice(Slice& slice) const
{
	slice._uv1.X = 0.0f;
	slice._uv1.Y = 1.0f;
	slice._uv2.X = _topLeftSlice.X;
	slice._uv2.Y = 1.0f - _topLeftSlice.Y;
	slice._drawPosition = _drawPosition;
	slice._drawSize = _topLeftSlicePx;
}

void SpriteBatch::NineSliceProperties::GetTopRightSlice(Slice& slice) const
{
	slice._uv1.X = 1.0f - _bottomRightSlice.X;
	slice._uv1.Y = 1.0f;
	slice._uv2.X = 1.0f;
	slice._uv2.Y = 1.0f - _topLeftSlice.Y;
	slice._drawPosition.X = _drawPosition.X + _drawSize.X - _bottomRightSlicePx.X;
	slice._drawPosition.Y = _drawPosition.Y;
	slice._drawSize.X = _bottomRightSlicePx.X;
	slice._drawSize.Y = _topLeftSlicePx.Y;
}

void SpriteBatch::NineSliceProperties::GetBottomLeftSlice(Slice& slice) const
{
	slice._uv1.X = 0.0f;
	slice._uv1.Y = _bottomRightSlice.Y;
	slice._uv2.X = _topLeftSlice.X;
	slice._uv2.Y = 0.0f;
	slice._drawPosition.X = _drawPosition.X;
	slice._drawPosition.Y = _drawPosition.Y + _drawSize.Y - _bottomRightSlicePx.Y;
	slice._drawSize.X = _topLeftSlicePx.X;
	slice._drawSize.Y = _bottomRightSlicePx.Y;
}

void SpriteBatch::NineSliceProperties::GetBottomRightSlice(Slice& slice) const
{
	slice._uv1.X = 1.0f - _bottomRightSlice.X;
	slice._uv1.Y = _bottomRightSlice.Y;
	slice._uv2.X = 1.0f;
	slice._uv2.Y = 0.0f;
	slice._drawPosition = _drawPosition + _drawSize - _bottomRightSlicePx;
	slice._drawSize = _bottomRightSlicePx;
}

void SpriteBatch::NineSliceProperties::GetTopMidSlice(Slice& slice) const
{
	slice._uv1.X = _topLeftSlice.X;
	slice._uv1.Y = 1.0f;
	slice._uv2.X = 1.0f - _bottomRightSlice.X;
	slice._uv2.Y = 1.0f - _topLeftSlice.Y;
	slice._drawPosition.X = _drawPosition.X + _topLeftSlicePx.X;
	slice._drawPosition.Y = _drawPosition.Y;
	slice._drawSize.X = _drawSize.X - _topLeftSlicePx.X - _bottomRightSlicePx.X;
	slice._drawSize.Y = _topLeftSlicePx.Y;
}

void SpriteBatch::NineSliceProperties::GetBottomMidSlice(Slice& slice) const
{
	slice._uv1.X = _topLeftSlice.X;
	slice._uv1.Y = _bottomRightSlice.Y;
	slice._uv2.X = 1.0f - _bottomRightSlice.X;
	slice._uv2.Y = 0.0f;
	slice._drawPosition.X = _drawPosition.X + _topLeftSlicePx.X;
	slice._drawPosition.Y = _drawPosition.Y + _drawSize.Y - _bottomRightSlicePx.Y;
	slice._drawSize.X = _drawSize.X - _topLeftSlicePx.X - _bottomRightSlicePx.X;
	slice._drawSize.Y = _bottomRightSlicePx.Y;
}

void SpriteBatch::NineSliceProperties::GetLeftMidSlice(Slice& slice) const
{
	slice._uv1.X = 0.0f;
	slice._uv1.Y = 1.0f - _topLeftSlice.Y;
	slice._uv2.X = _topLeftSlice.X;
	slice._uv2.Y = _bottomRightSlice.Y;
	slice._drawPosition.X = _drawPosition.X;
	slice._drawPosition.Y = _drawPosition.Y + _topLeftSlicePx.Y;
	slice._drawSize.X = _topLeftSlicePx.X;
	slice._drawSize.Y = _drawSize.Y - _bottomRightSlicePx.Y - _topLeftSlicePx.Y;
}

void SpriteBatch::NineSliceProperties::GetRightMidSlice(Slice& slice) const
{
	slice._uv1.X = 1.0f - _bottomRightSlice.X;
	slice._uv1.Y = 1.0f - _topLeftSlice.Y;
	slice._uv2.X = 1.0f;
	slice._uv2.Y = _bottomRightSlice.Y;
	slice._drawPosition.X = _drawPosition.X + _drawSize.X - _bottomRightSlicePx.X;
	slice._drawPosition.Y = _drawPosition.Y + _topLeftSlicePx.Y;
	slice._drawSize.X = _bottomRightSlicePx.X;
	slice._drawSize.Y = _drawSize.Y - _bottomRightSlicePx.Y - _topLeftSlicePx.Y;
}

void SpriteBatch::NineSliceProperties::GetMidSlice(Slice& slice) const
{
	slice._uv1.X = _topLeftSlice.X;
	slice._uv1.Y = 1.0f - _topLeftSlice.Y;
	slice._uv2.X = 1.0f - _bottomRightSlice.X;
	slice._uv2.Y = _bottomRightSlice.Y;
	slice._drawPosition = _drawPosition + _topLeftSlicePx;
	slice._drawSize = _drawSize - _topLeftSlicePx - _bottomRightSlicePx;
}

void SpriteBatch::Draw9Slice(Texture* texture, const Vector2& position, const Vector2& size, const Vector4& margin,
                             const Vector4& colour, bool drawCenter)
{
	Slice slice;
	const NineSliceProperties properties(Vector2(margin.X, margin.Y), Vector2(margin.Z, margin.W), texture->GetSize(), position,
	                                     size);

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

void SpriteBatch::TransformUV(Vector2& uv, const Vector2& glyphSize, const Vector2& offset, const Vector2& sheetSize)
{
	uv = Vector2(offset.X, sheetSize.Y - offset.Y - glyphSize.Y) / sheetSize + uv * glyphSize / sheetSize;
}

void SpriteBatch::TransformUVs(Slice& slice, const Vector2& glyphSize, const Vector2& offset, const Vector2& sheetSize)
{
	TransformUV(slice._uv1, glyphSize, offset, sheetSize);
	TransformUV(slice._uv2, glyphSize, offset, sheetSize);
}

void SpriteBatch::Draw9Slice(Texture* texture, const Vector2& position, const Vector2& size, const Vector2& glyphPosition,
                             const Vector2& glyphSize, const Vector4& margin, const Vector4& colour, bool drawCenter)
{
	Slice slice;
	const Vector2& sheetSize = Vector2(texture->GetWidth(), texture->GetHeight());
	const NineSliceProperties properties(Vector2(margin.X, margin.Y), Vector2(margin.Z, margin.W), glyphSize, position, size);

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

void SpriteBatch::Flush(const Matrix4x4& proj, float scale)
{
	if (_spritesToDraw.empty())
	{
		return;
	}

	_drawCallCount = 0;

	glDisable(GL_DEPTH_TEST);

	GL::ShaderProgram& shader = GetShader();
	shader.Bind();
	shader.SetUniformValue("projMatrix", proj);

	static const size_t vertSize = 8;
	static const size_t faceVertCount = 6;
	static const size_t vertStride = vertSize * sizeof(float);
	static const uint32_t faceIndices[] = {0, 1, 2, 2, 3, 0};

	size_t basePos = 0;
	size_t maxSpriteBatch = _spritesToDraw.size();
	if (maxSpriteBatch > _maxSpriteCount)
	{
		maxSpriteBatch = _maxSpriteCount;
	}

	_vertexBinding->Bind();

	while (basePos < _spritesToDraw.size() && maxSpriteBatch > 0)
	{
		size_t searchPos = basePos;
		auto batchTexture = _spritesToDraw[basePos]._texture;

		while (searchPos < _spritesToDraw.size() && (searchPos - basePos) < maxSpriteBatch &&
		       _spritesToDraw[searchPos]._texture == batchTexture)
		{ searchPos++; }

		if (batchTexture != nullptr)
		{
			batchTexture->Bind(0);
		}

		for (size_t i = basePos; i < searchPos; ++i)
		{
			float* buffer = &_vertexData[(i - basePos) * faceVertCount * vertSize];
			Sprite& sprite = _spritesToDraw[i];

			for (size_t j = 0; j < faceVertCount; ++j)
			{
				buffer[4 + vertSize * j] = sprite._colour.X;
				buffer[5 + vertSize * j] = sprite._colour.Y;
				buffer[6 + vertSize * j] = sprite._colour.Z;
				buffer[7 + vertSize * j] = sprite._colour.W;
			}

			Vector2 vertexPositions[4] = {
			    Vector2(-(sprite._size.X / 2), -(sprite._size.Y / 2)),
			    Vector2(-(sprite._size.X / 2), sprite._size.Y / 2),
			    Vector2(sprite._size.X / 2, sprite._size.Y / 2),
			    Vector2(sprite._size.X / 2, -(sprite._size.Y / 2)),
			};

			Vector2 vertexTextureCoords[4] = {
			    Vector2(sprite._uv1.X, sprite._uv1.Y),
			    Vector2(sprite._uv1.X, sprite._uv2.Y),
			    Vector2(sprite._uv2.X, sprite._uv2.Y),
			    Vector2(sprite._uv2.X, sprite._uv1.Y),
			};

			for (size_t j = 0; j < 4; ++j)
			{
				float cosAngle = Math::Cos(Math::DegreesToRadians(sprite._angle));
				float sinAngle = Math::Sin(Math::DegreesToRadians(sprite._angle));

				Vector2 p = vertexPositions[j];
				vertexPositions[j].X = p.X * cosAngle - p.Y * sinAngle;
				vertexPositions[j].Y = p.Y * cosAngle + p.X * sinAngle;
				vertexPositions[j] += sprite._position + (sprite._size * 0.5f);
			}

			for (size_t j = 0; j < faceVertCount; ++j)
			{
				size_t bufferIndex = j * vertSize;
				size_t vertexIndex = faceIndices[j];

				buffer[bufferIndex] = vertexPositions[vertexIndex].X * scale;
				buffer[bufferIndex + 1] = vertexPositions[vertexIndex].Y * scale;
				buffer[bufferIndex + 2] = vertexTextureCoords[vertexIndex].X;
				buffer[bufferIndex + 3] = vertexTextureCoords[vertexIndex].Y;
			}
		}

		_vertexBuffer->UpdateBuffer(_vertexData.data(), 0, (searchPos - basePos) * faceVertCount * vertStride);

		glDrawArrays(GL_TRIANGLES, 0, (GLsizei)((searchPos - basePos) * faceVertCount));

		_drawCallCount++;

		basePos = searchPos;
	}

	_vertexBinding->Unbind();
	shader.Unbind();

	glEnable(GL_DEPTH_TEST);

	_spritesToDraw.clear();
}

bool SpriteBatch::IsSpriteInsideClippingRect(const Vector2& position, const Vector2& size)
{
	return !((position.X >= _clippingRect.Z) || (position.X + size.X <= _clippingRect.X) || (position.Y >= _clippingRect.W) ||
	         (position.Y + size.Y <= _clippingRect.Y));
}
} // namespace Donut
