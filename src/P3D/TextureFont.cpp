#include <MemoryStream.h>
#include <P3D/TextureFont.h>
#include <P3D/Texture.h>
#include <P3D/FontGlyphs.h>
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

		std::vector<std::unique_ptr<Texture>> texures;
		std::unique_ptr<FontGlyphs> glyphs;

		for (auto const& child : chunk.GetChildren())
		{
			switch (child->GetType())
			{
				case ChunkType::Texture:
				{
					texures.push_back(P3D::Texture::Load(*child));
					break;
				}
				case ChunkType::FontGlyphs:
				{
					glyphs = P3D::FontGlyphs::Load(*child);
					break;
				}
				default:
					throw std::exception("unexpected child chunk in TextureFont");
			}
		}

		return std::make_unique<TextureFont>(name, numTextures, size, width, height, baseLine);
	}
} // namespace Donut::P3D
