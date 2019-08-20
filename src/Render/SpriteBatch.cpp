// Copyright 2019 the donut authors. See AUTHORS.md

#include "SpriteBatch.h"

#include <Render/Font.h>
#include <Render/OpenGL/ShaderProgram.h>
#include <Render/OpenGL/VertexBinding.h>
#include <Render/OpenGL/VertexBuffer.h>
#include <Render/Texture.h>

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

void SpriteBatch::DrawText(const Font* font, const std::string& text, const glm::vec2& position, const glm::vec4& colour)
{
	if (font == nullptr) return;

	Font::Glyph glyph;
	glm::vec2 curPosition = position;
	float fontHeight      = font->GetHeight();

	for (const char& c : text)
	{
		if (c == '\n')
		{
			curPosition.x = position.x;
			curPosition.y += fontHeight;
			continue;
		}

		if (!font->TryGetGlyph(c, glyph)) continue;

		Texture* glyphTexture = font->GetTexture(glyph.textureId);

		Draw(glyphTexture,
		     curPosition + glm::vec2(glyph.leftBearing),
		     glm::vec2(glyph.bottomLeftX, 1.0f - glyph.topRightY),
		     glm::vec2(glyph.topRightX, 1.0f - glyph.bottomLeftY),
		     glm::vec2(glyph.width, fontHeight),
		     colour);

		curPosition += glm::vec2(glyph.advance, 0);
	}
}

SpriteBatch::Sprite::Sprite(
    Texture* texture,
    const glm::vec2& position,
    const glm::vec2& size,
    float angle,
    const glm::vec4& colour):
    _texture(texture),
    _position(position),
    _size(size),
    _uv1(0, 1),
    _uv2(1, 0),
    _colour(colour),
    _angle(angle)
{
}

SpriteBatch::Sprite::Sprite(
    Texture* texture,
    const glm::vec2& position,
    const glm::vec2& size,
    const glm::vec2& uv1,
    const glm::vec2& uv2,
    const glm::vec4& colour):
    _texture(texture),
    _position(position),
    _size(size),
    _uv1(uv1),
    _uv2(uv2),
    _colour(colour),
    _angle(0.0f)
{
}

SpriteBatch::SpriteBatch(size_t maxSpriteCount):
    _clipping(false),
    _drawCallCount(0),
    _maxSpriteCount(maxSpriteCount)
{
	static const size_t vertSize      = 8;
	static const size_t faceVertCount = 6;
	static const size_t vertStride    = vertSize * sizeof(float);

	_vertexBuffer = std::make_unique<GL::VertexBuffer>(nullptr, _maxSpriteCount * faceVertCount, vertStride);

	GL::ArrayElement vertexLayout[] = {
		GL::ArrayElement(_vertexBuffer.get(), 0, 2, GL::AE_FLOAT, vertStride, 0),
		GL::ArrayElement(_vertexBuffer.get(), 1, 2, GL::AE_FLOAT, vertStride, 2 * sizeof(float)),
		GL::ArrayElement(_vertexBuffer.get(), 2, 4, GL::AE_FLOAT, vertStride, 4 * sizeof(float)),
	};

	_vertexBinding = std::make_unique<GL::VertexBinding>();
	_vertexBinding->Create(vertexLayout, 3, *_vertexBuffer);

	_vertexData.resize(_maxSpriteCount * faceVertCount * vertSize);
}

void SpriteBatch::Draw(
    Texture* texture,
    const glm::vec2& position,
    float angle,
    const glm::vec4& colour)
{
	_spritesToDraw.push_back(Sprite(texture, position, texture->GetSize(), angle, colour));
}

void SpriteBatch::Draw(
    Texture* texture,
    const glm::vec2& position,
    const glm::vec2& size,
    const glm::vec4& colour)
{
	float u1              = 0.0f;
	float v1              = 0.0f;
	float u2              = 1.0f;
	float v2              = 1.0f;
	glm::vec2 newPosition = position;
	glm::vec2 newSize     = size;

	if (_clipping)
	{
		if (!IsSpriteInsideClippingRect(position, size))
		{
			return;
		}

		float newleft   = glm::clamp(position.x, (float)_clippingRect.x, (float)_clippingRect.z);
		float newtop    = glm::clamp(position.y, (float)_clippingRect.y, (float)_clippingRect.w);
		float newright  = glm::clamp(position.x + size.x, (float)_clippingRect.x, (float)_clippingRect.z);
		float newbottom = glm::clamp(position.y + size.y, (float)_clippingRect.y, (float)_clippingRect.w);

		newPosition = glm::vec2(newleft, newtop);
		newSize     = glm::vec2(newright - newleft, newbottom - newtop);

		float difleft   = newleft - position.x;
		float diftop    = newtop - position.y;
		float difright  = newright - (position.x + size.x);
		float difbottom = newbottom - (position.y + size.y);

		difleft /= size.x;
		diftop /= size.y;
		difright /= size.x;
		difbottom /= size.y;

		float uwidth  = u2 - u1;
		float vheight = v2 - v1;

		u1 = u1 + (uwidth * difleft);
		u2 = u2 + (uwidth * difright);
		v1 = v1 + (vheight * diftop);
		v2 = v2 + (vheight * difbottom);
	}

	_spritesToDraw.push_back(Sprite(texture, newPosition, newSize, glm::vec2(u1, v1), glm::vec2(u2, v2), colour));
}

void SpriteBatch::Draw(
    Texture* texture,
    const glm::vec2& position,
    const glm::vec2& size,
    float angle,
    const glm::vec4& colour)
{
	_spritesToDraw.push_back(Sprite(texture, position, size, angle, colour));
}

void SpriteBatch::Draw(
    Texture* texture,
    const glm::vec2& position,
    const glm::vec2& uv1,
    const glm::vec2& uv2,
    const glm::vec2& size,
    const glm::vec4& colour)
{
	float u1              = uv1.x;
	float v1              = uv1.y;
	float u2              = uv2.x;
	float v2              = uv2.y;
	glm::vec2 newPosition = position;
	glm::vec2 newSize     = size;

	if (_clipping)
	{
		if (!IsSpriteInsideClippingRect(position, size))
		{
			return;
		}

		float newleft   = glm::clamp(position.x, (float)_clippingRect.x, (float)_clippingRect.z);
		float newtop    = glm::clamp(position.y, (float)_clippingRect.y, (float)_clippingRect.w);
		float newright  = glm::clamp(position.x + size.x, (float)_clippingRect.x, (float)_clippingRect.z);
		float newbottom = glm::clamp(position.y + size.y, (float)_clippingRect.y, (float)_clippingRect.w);

		newPosition = glm::vec2(newleft, newtop);
		newSize     = glm::vec2(newright - newleft, newbottom - newtop);

		float difleft   = newleft - position.x;
		float diftop    = newtop - position.y;
		float difright  = newright - (position.x + size.x);
		float difbottom = newbottom - (position.y + size.y);

		difleft /= size.x;
		diftop /= size.y;
		difright /= size.x;
		difbottom /= size.y;

		float uwidth  = u2 - u1;
		float vheight = v2 - v1;

		u1 = u1 + (uwidth * difleft);
		u2 = u2 + (uwidth * difright);
		v1 = v1 + (vheight * diftop);
		v2 = v2 + (vheight * difbottom);
	}

	_spritesToDraw.push_back(Sprite(texture, newPosition, newSize, glm::vec2(u1, v1), glm::vec2(u2, v2), colour));
}

SpriteBatch::NineSliceProperties::NineSliceProperties(
    const glm::vec2& topLeftSlicePx,
    const glm::vec2& bottomRightSlicePx,
    const glm::vec2& glyphSize,
    const glm::vec2& drawPosition,
    const glm::vec2& drawSize):
    _topLeftSlicePx(topLeftSlicePx),
    _bottomRightSlicePx(bottomRightSlicePx),
    _topLeftSlice(topLeftSlicePx / glyphSize),
    _bottomRightSlice(bottomRightSlicePx / glyphSize),
    _glyphSize(glyphSize),
    _drawPosition(drawPosition),
    _drawSize(drawSize)
{
}

void SpriteBatch::DrawSlice(Texture* texture, const SpriteBatch::Slice& slice, const glm::vec4& colour)
{
	Draw(texture, slice._drawPosition, slice._uv1, slice._uv2, slice._drawSize, colour);
}

void SpriteBatch::NineSliceProperties::GetTopLeftSlice(Slice& slice) const
{
	slice._uv1.x        = 0.0f;
	slice._uv1.y        = 1.0f;
	slice._uv2.x        = _topLeftSlice.x;
	slice._uv2.y        = 1.0f - _topLeftSlice.y;
	slice._drawPosition = _drawPosition;
	slice._drawSize     = _topLeftSlicePx;
}

void SpriteBatch::NineSliceProperties::GetTopRightSlice(Slice& slice) const
{
	slice._uv1.x          = 1.0f - _bottomRightSlice.x;
	slice._uv1.y          = 1.0f;
	slice._uv2.x          = 1.0f;
	slice._uv2.y          = 1.0f - _topLeftSlice.y;
	slice._drawPosition.x = _drawPosition.x + _drawSize.x - _bottomRightSlicePx.x;
	slice._drawPosition.y = _drawPosition.y;
	slice._drawSize.x     = _bottomRightSlicePx.x;
	slice._drawSize.y     = _topLeftSlicePx.y;
}

void SpriteBatch::NineSliceProperties::GetBottomLeftSlice(Slice& slice) const
{
	slice._uv1.x          = 0.0f;
	slice._uv1.y          = _bottomRightSlice.y;
	slice._uv2.x          = _topLeftSlice.x;
	slice._uv2.y          = 0.0f;
	slice._drawPosition.x = _drawPosition.x;
	slice._drawPosition.y = _drawPosition.y + _drawSize.y - _bottomRightSlicePx.y;
	slice._drawSize.x     = _topLeftSlicePx.x;
	slice._drawSize.y     = _bottomRightSlicePx.y;
}

void SpriteBatch::NineSliceProperties::GetBottomRightSlice(Slice& slice) const
{
	slice._uv1.x        = 1.0f - _bottomRightSlice.x;
	slice._uv1.y        = _bottomRightSlice.y;
	slice._uv2.x        = 1.0f;
	slice._uv2.y        = 0.0f;
	slice._drawPosition = _drawPosition + _drawSize - _bottomRightSlicePx;
	slice._drawSize     = _bottomRightSlicePx;
}

void SpriteBatch::NineSliceProperties::GetTopMidSlice(Slice& slice) const
{
	slice._uv1.x          = _topLeftSlice.x;
	slice._uv1.y          = 1.0f;
	slice._uv2.x          = 1.0f - _bottomRightSlice.x;
	slice._uv2.y          = 1.0f - _topLeftSlice.y;
	slice._drawPosition.x = _drawPosition.x + _topLeftSlicePx.x;
	slice._drawPosition.y = _drawPosition.y;
	slice._drawSize.x     = _drawSize.x - _topLeftSlicePx.x - _bottomRightSlicePx.x;
	slice._drawSize.y     = _topLeftSlicePx.y;
}

void SpriteBatch::NineSliceProperties::GetBottomMidSlice(Slice& slice) const
{
	slice._uv1.x          = _topLeftSlice.x;
	slice._uv1.y          = _bottomRightSlice.y;
	slice._uv2.x          = 1.0f - _bottomRightSlice.x;
	slice._uv2.y          = 0.0f;
	slice._drawPosition.x = _drawPosition.x + _topLeftSlicePx.x;
	slice._drawPosition.y = _drawPosition.y + _drawSize.y - _bottomRightSlicePx.y;
	slice._drawSize.x     = _drawSize.x - _topLeftSlicePx.x - _bottomRightSlicePx.x;
	slice._drawSize.y     = _bottomRightSlicePx.y;
}

void SpriteBatch::NineSliceProperties::GetLeftMidSlice(Slice& slice) const
{
	slice._uv1.x          = 0.0f;
	slice._uv1.y          = 1.0f - _topLeftSlice.y;
	slice._uv2.x          = _topLeftSlice.x;
	slice._uv2.y          = _bottomRightSlice.y;
	slice._drawPosition.x = _drawPosition.x;
	slice._drawPosition.y = _drawPosition.y + _topLeftSlicePx.y;
	slice._drawSize.x     = _topLeftSlicePx.x;
	slice._drawSize.y     = _drawSize.y - _bottomRightSlicePx.y - _topLeftSlicePx.y;
}

void SpriteBatch::NineSliceProperties::GetRightMidSlice(Slice& slice) const
{
	slice._uv1.x          = 1.0f - _bottomRightSlice.x;
	slice._uv1.y          = 1.0f - _topLeftSlice.y;
	slice._uv2.x          = 1.0f;
	slice._uv2.y          = _bottomRightSlice.y;
	slice._drawPosition.x = _drawPosition.x + _drawSize.x - _bottomRightSlicePx.x;
	slice._drawPosition.y = _drawPosition.y + _topLeftSlicePx.y;
	slice._drawSize.x     = _bottomRightSlicePx.x;
	slice._drawSize.y     = _drawSize.y - _bottomRightSlicePx.y - _topLeftSlicePx.y;
}

void SpriteBatch::NineSliceProperties::GetMidSlice(Slice& slice) const
{
	slice._uv1.x        = _topLeftSlice.x;
	slice._uv1.y        = 1.0f - _topLeftSlice.y;
	slice._uv2.x        = 1.0f - _bottomRightSlice.x;
	slice._uv2.y        = _bottomRightSlice.y;
	slice._drawPosition = _drawPosition + _topLeftSlicePx;
	slice._drawSize     = _drawSize - _topLeftSlicePx - _bottomRightSlicePx;
}

void SpriteBatch::Draw9Slice(
    Texture* texture,
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
	TransformUV(slice._uv1, glyphSize, offset, sheetSize);
	TransformUV(slice._uv2, glyphSize, offset, sheetSize);
}

void SpriteBatch::Draw9Slice(
    Texture* texture,
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

void SpriteBatch::Flush(const glm::mat4& proj, float scale)
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

	static const size_t vertSize        = 8;
	static const size_t faceVertCount   = 6;
	static const size_t vertStride      = vertSize * sizeof(float);
	static const uint32_t faceIndices[] = { 0, 1, 2, 2, 3, 0 };

	size_t basePos        = 0;
	size_t maxSpriteBatch = _spritesToDraw.size();
	if (maxSpriteBatch > _maxSpriteCount)
	{
		maxSpriteBatch = _maxSpriteCount;
	}

	_vertexBinding->Bind();

	while (basePos < _spritesToDraw.size() && maxSpriteBatch > 0)
	{
		size_t searchPos  = basePos;
		auto batchTexture = _spritesToDraw[basePos]._texture;

		while (searchPos < _spritesToDraw.size() && (searchPos - basePos) < maxSpriteBatch && _spritesToDraw[searchPos]._texture == batchTexture)
		{
			searchPos++;
		}

		if (batchTexture != nullptr)
		{
			batchTexture->Bind(0);
		}

		for (size_t i = basePos; i < searchPos; ++i)
		{
			float* buffer  = &_vertexData[(i - basePos) * faceVertCount * vertSize];
			Sprite& sprite = _spritesToDraw[i];

			for (size_t j = 0; j < faceVertCount; ++j)
			{
				buffer[4 + vertSize * j] = sprite._colour.x;
				buffer[5 + vertSize * j] = sprite._colour.y;
				buffer[6 + vertSize * j] = sprite._colour.z;
				buffer[7 + vertSize * j] = sprite._colour.w;
			}

			glm::vec2 vertexPositions[4] = {
				glm::vec2(-(sprite._size.x / 2), -(sprite._size.y / 2)),
				glm::vec2(-(sprite._size.x / 2), sprite._size.y / 2),
				glm::vec2(sprite._size.x / 2, sprite._size.y / 2),
				glm::vec2(sprite._size.x / 2, -(sprite._size.y / 2)),
			};

			glm::vec2 vertexTextureCoords[4] = {
				glm::vec2(sprite._uv1.x, sprite._uv1.y),
				glm::vec2(sprite._uv1.x, sprite._uv2.y),
				glm::vec2(sprite._uv2.x, sprite._uv2.y),
				glm::vec2(sprite._uv2.x, sprite._uv1.y),
			};

			for (size_t j = 0; j < 4; ++j)
			{
				float cosAngle = glm::cos(glm::radians(sprite._angle));
				float sinAngle = glm::sin(glm::radians(sprite._angle));

				glm::vec2 p          = vertexPositions[j];
				vertexPositions[j].x = p.x * cosAngle - p.y * sinAngle;
				vertexPositions[j].y = p.y * cosAngle + p.x * sinAngle;
				vertexPositions[j] += sprite._position + (sprite._size * 0.5f);
			}

			for (size_t j = 0; j < faceVertCount; ++j)
			{
				size_t bufferIndex = j * vertSize;
				size_t vertexIndex = faceIndices[j];

				buffer[bufferIndex]     = vertexPositions[vertexIndex].x * scale;
				buffer[bufferIndex + 1] = vertexPositions[vertexIndex].y * scale;
				buffer[bufferIndex + 2] = vertexTextureCoords[vertexIndex].x;
				buffer[bufferIndex + 3] = vertexTextureCoords[vertexIndex].y;
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

bool SpriteBatch::IsSpriteInsideClippingRect(const glm::vec2& position, const glm::vec2& size)
{
	return !((position.x >= _clippingRect.z) ||
	         (position.x + size.x <= _clippingRect.x) ||
	         (position.y >= _clippingRect.w) ||
	         (position.y + size.y <= _clippingRect.y));
}
} // namespace Donut
