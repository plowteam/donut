#include <MemoryStream.h>
#include <P3D/TextureFont.h>
#include <iostream>

namespace Donut::P3D
{
	std::unique_ptr<TextureFont> TextureFont::Load(const P3DChunk& chunk)
	{
		assert(chunk.IsType(ChunkType::TextureFont));

		MemoryStream stream(chunk.GetData());

		uint32_t version = stream.Read<uint32_t>();
		std::string name = stream.ReadLPString();
		std::string shader = stream.ReadLPString();
		float size = stream.Read<float>();
		float width = stream.Read<float>();
		float height = stream.Read<float>();
		float baseLine = stream.Read<float>();
		uint32_t numTextures = stream.Read<uint32_t>();

		auto textureFont = std::make_unique<TextureFont>(name, numTextures, size, width, height, baseLine);

		for (auto const& child : chunk.GetChildren())
		{
			textureFont->ReadChild(*child);
		}

		return textureFont;
	}

	void TextureFont::ReadChild(const P3DChunk& child)
	{
		switch (child.GetType())
		{
		case ChunkType::Texture:
		{
			_texures.push_back(P3D::Texture::Load(child));
			break;
		}
		case ChunkType::FontGlyphs:
		{
			MemoryStream data(child.GetData());
			uint32_t numGlyphs = data.Read<uint32_t>();
			_glyphs.resize(numGlyphs);
			data.ReadBytes(reinterpret_cast<uint8_t*>(_glyphs.data()), numGlyphs * sizeof(FontGlyph));

			break;
		}
		default:
			throw std::exception("unexpected child chunk in TextureFont");
		}
	}
} // namespace Donut::P3D
