// Copyright 2019 the donut authors. See AUTHORS.md

include "Font.h"
#include <P3D/P3DChunk.h>
#include <P3D/p3d.generated.h>

namespace Donut
{
	Font::Font(P3D::TextureFont& fontP3D)
	{
		_height = fontP3D.GetHeight();

		for (const auto& texture : fontP3D.GetTextures())
		{
			auto texdata = P3D::ImageData::Decode(texture->GetImage()->GetData());
			_textures.push_back(std::move((texdata.comp == 4) ?
				std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, texdata.data.data()) :
				std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, texdata.data.data())));
		}

		for (const auto& glyph : fontP3D.GetGlyphs())
		{
			_glyphs.insert({
				glyph.id,
				Glyph
				{
					glyph.textureId,
					glyph.bottomLeftX,
					glyph.bottomLeftY,
					glyph.topRightX,
					glyph.topRightY,
					glyph.leftBearing,
					glyph.rightBearing,
					glyph.width,
					glyph.advance
				} });
		}
	}

	bool Font::TryGetGlyph(int32_t id, Font::Glyph& glyph) const
	{
		if (_glyphs.find(id) != _glyphs.end())
		{
			glyph = _glyphs.at(id);
			return true;
		}

		return false;
	}
}
