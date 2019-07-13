#pragma once

#include <P3D/P3DChunk.h>

namespace Donut::P3D
{
	class TextureFont
	{
	public:

		TextureFont(const std::string& name, uint32_t numTextures, float size, float width, float height, float baseLine) :
			_name(name), _numTextures(numTextures), _size(size), _width(width), _height(height), _baseLine(baseLine) {}

		static std::unique_ptr<TextureFont> Load(const P3DChunk&);

	private:

		uint32_t _version;
		std::string _name;
		std::string _shader;
		float _size;
		float _width;
		float _height;
		float _baseLine;
		uint32_t _numTextures;
	};
} // namespace Donut::P3D
