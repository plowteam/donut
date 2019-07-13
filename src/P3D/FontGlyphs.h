#pragma once

#include <P3D/P3DChunk.h>

namespace Donut::P3D
{
	struct FontGlyph
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
		uint32_t id;
	};

	class FontGlyphs
	{
	public:

		FontGlyphs() {}

		static std::unique_ptr<FontGlyphs> Load(const P3DChunk&);

	private:

	};
} // namespace Donut::P3D
