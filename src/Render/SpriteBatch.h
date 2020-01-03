// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Fwd.h"
#include "Core/Math/Vector2.h"
#include "Core/Math/Vector4.h"

#include <map>
#include <memory>
#include <stack>
#include <string>
#include <vector>

namespace Donut
{
namespace GL
{
class VertexBinding;
class VertexBuffer;
class ShaderProgram;
} // namespace GL

class Texture;

class SpriteBatch
{

public:
	SpriteBatch(size_t = 1000);

	void Flush(const Matrix4x4&, float = 1.0f);
	void DrawText(const class Font*, const std::string&, const Vector2&, const Vector4&);
	void Draw(Texture*, const Vector2&, float, const Vector4&);
	void Draw(Texture*, const Vector2&, const Vector2&, const Vector4&);
	void Draw(Texture*, const Vector2&, const Vector2&, float, const Vector4&);
	void Draw(Texture*, const Vector2&, const Vector2&, const Vector2&, const Vector2&, const Vector4&);
	void Draw9Slice(Texture*, const Vector2&, const Vector2&, const Vector4&, const Vector4&, bool = true);
	void Draw9Slice(Texture*, const Vector2&, const Vector2&, const Vector2&, const Vector2&, const Vector4&, const Vector4&,
	                bool = true);

	void EnableClipping(bool clipping) { _clipping = clipping; }
	void SetClippingRect(const Vector4& clippingRect) { _clippingRect = clippingRect; }

	size_t GetDrawCallCount() const { return _drawCallCount; }

	GL::ShaderProgram& GetShader();

private:
	struct Sprite
	{
		Sprite(Texture*, const Vector2&, const Vector2&, float, const Vector4&);
		Sprite(Texture*, const Vector2&, const Vector2&, const Vector2&, const Vector2&, const Vector4&);

		Texture* _texture;
		Vector2 _position;
		Vector2 _size;
		Vector2 _uv1;
		Vector2 _uv2;
		Vector4 _colour;
		float _angle;
	};

	struct Slice
	{
		Vector2 _uv1;
		Vector2 _uv2;
		Vector2 _drawPosition;
		Vector2 _drawSize;
	};

	struct NineSliceProperties
	{
		NineSliceProperties(const Vector2&, const Vector2&, const Vector2&, const Vector2&, const Vector2&);

		void GetTopLeftSlice(Slice&) const;
		void GetTopRightSlice(Slice&) const;
		void GetBottomLeftSlice(Slice&) const;
		void GetBottomRightSlice(Slice&) const;
		void GetTopMidSlice(Slice&) const;
		void GetBottomMidSlice(Slice&) const;
		void GetLeftMidSlice(Slice&) const;
		void GetRightMidSlice(Slice&) const;
		void GetMidSlice(Slice&) const;

		const Vector2 _glyphSize;
		const Vector2 _topLeftSlicePx;
		const Vector2 _bottomRightSlicePx;
		const Vector2 _topLeftSlice;
		const Vector2 _bottomRightSlice;
		const Vector2 _drawPosition;
		const Vector2 _drawSize;
	};

	void DrawSlice(Texture*, const Slice&, const Vector4&);
	static void TransformUV(Vector2&, const Vector2&, const Vector2&, const Vector2&);
	static void TransformUVs(Slice&, const Vector2&, const Vector2&, const Vector2&);
	bool IsSpriteInsideClippingRect(const Vector2&, const Vector2&);

	std::vector<Sprite> _spritesToDraw;
	bool _clipping;
	Vector4 _clippingRect;
	size_t _drawCallCount;
	size_t _maxSpriteCount;
	std::vector<float> _vertexData;
	std::unique_ptr<GL::VertexBuffer> _vertexBuffer;
	std::unique_ptr<GL::VertexBinding> _vertexBinding;

	static std::unique_ptr<GL::ShaderProgram> Shader;
};
} // namespace Donut
