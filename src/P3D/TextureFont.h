#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/Texture.h>
#include <Render/OpenGL/Texture2D.h>
#include <map>

namespace Donut::P3D
{
	class TextureFont
	{
	public:

		TextureFont(const std::string& name, uint32_t numTextures, float size, float width, float height, float baseLine) :
			_name(name), _numTextures(numTextures), _size(size), _width(width), _height(height), _baseLine(baseLine) {}

		static std::unique_ptr<TextureFont> Load(const P3DChunk&);

		uint32_t GetNumTextures() const { return _numTextures; }
		GL::Texture2D* GetTexture(std::size_t index) const { return _glTextures[index].get(); }
		std::string GetTextureName(size_t index) { return _texures[index]->GetName(); }
		float GetHeight() const { return _height; }
		bool TryGetGlyph(int32_t id, FontGlyph& glyph) const;

	private:

		void ReadChild(const P3DChunk&);

		std::string _name;
		float _size;
		float _width;
		float _height;
		float _baseLine;
		uint32_t _numTextures;
		std::vector<std::unique_ptr<Texture>> _texures;
		std::vector<std::unique_ptr<GL::Texture2D>> _glTextures;
		std::map<int32_t, FontGlyph> _glyphs;
	};
} // namespace Donut::P3D
