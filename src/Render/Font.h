// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <map>
#include <memory>
#include <vector>

namespace Donut
{
namespace P3D
{
class TextureFont;
}

class Texture;

class Font
{
public:
	struct Glyph
	{
		uint32_t textureId;
		float bottomLeftX;
		float bottomLeftY;
		float topRightX;
		float topRightY;
		float leftBearing;
		float rightBearing;
		float width;
		float advance;
	};

	Font(P3D::TextureFont&);

	Texture* GetTexture(std::size_t index) const { return _textures.at(index).get(); }
	float GetHeight() const { return _height; }

	bool TryGetGlyph(int32_t id, Glyph& glyph) const;

private:
	float _height;
	std::vector<std::shared_ptr<Texture>> _textures;
	std::map<int32_t, Glyph> _glyphs;
};
} // namespace Donut
