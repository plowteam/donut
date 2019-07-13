#pragma once

#include <P3D/P3DChunk.h>

namespace Donut::P3D
{
	class FontGlyphs
	{
	public:

		FontGlyphs() {}

		static std::unique_ptr<FontGlyphs> Load(const P3DChunk&);

	private:

	};
} // namespace Donut::P3D
