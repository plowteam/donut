// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

#include <Render/OpenGL/Texture2D.h>
#include <memory>
#include <vector>
#include <map>

namespace Donut
{
	namespace P3D
	{
		class TextureFont;
	}

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

		GL::Texture2D* GetTexture(std::size_t index) const { return _textures.at(index).get(); }
		float GetHeight() const { return _height; }

		bool TryGetGlyph(int32_t id, Glyph& glyph) const;

	private:

		float _height;
		std::vector<std::unique_ptr<GL::Texture2D>> _textures;
		std::map<int32_t, Glyph> _glyphs;
	};
}
