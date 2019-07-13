#include <MemoryStream.h>
#include <P3D/FontGlyphs.h>
#include <iostream>

namespace Donut::P3D
{
	std::unique_ptr<FontGlyphs> FontGlyphs::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::FontGlyphs));

		MemoryStream stream(chunk.GetData());

		uint32_t numGlyphs = stream.Read<uint32_t>();
		std::vector<FontGlyph> glyphs;
		glyphs.resize(numGlyphs);
		stream.ReadBytes(reinterpret_cast<uint8_t*>(glyphs.data()), numGlyphs * sizeof(FontGlyph));

		return std::make_unique<FontGlyphs>();
	}
} // namespace Donut::P3D
