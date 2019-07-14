#include <Core/MemoryStream.h>
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
				auto texture = P3D::Texture::Load(child);
				auto texdata = texture->GetData();
				std::unique_ptr<GL::Texture2D> glTexture;

				if (texdata.comp == 4)
				{
					glTexture = std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, texdata.data.data());
				}
				else
				{
					glTexture = std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, texdata.data.data());
				}

				_glTextures.push_back(std::move(glTexture));
				_texures.push_back(std::move(texture));

				break;
			}
			case ChunkType::FontGlyphs:
			{
				MemoryStream data(child.GetData());
				uint32_t numGlyphs = data.Read<uint32_t>();

				for (int i = 0; i < numGlyphs; ++i)
				{
					FontGlyph glyph;
					data.ReadBytes(reinterpret_cast<uint8_t*>(&glyph), sizeof(FontGlyph));
					_glyphs.insert(std::pair<int32_t, FontGlyph>(glyph.id, glyph));
				}

				break;
			}
			default:
				throw std::runtime_error("unexpected child chunk in TextureFont");
		}
	}

	bool TextureFont::TryGetGlyph(int32_t id, FontGlyph& glyph) const
	{
		if (_glyphs.find(id) != _glyphs.end())
		{
			glyph = _glyphs.at(id);
			return true;
		}

		return false;
	}
} // namespace Donut::P3D
