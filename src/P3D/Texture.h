#pragma once

#include <P3D/P3DChunk.h>

namespace Donut::P3D
{

struct ImageData
{
	int width;
	int height;
	int comp;
	std::vector<uint8_t> data;
};

class Texture
{
  public:
	Texture(const std::string& name, uint32_t width, uint32_t height, uint32_t bpp, ImageData data):
	    _name(name), _width(width), _height(height), _bpp(bpp), _data(data) {}

	static std::unique_ptr<Texture> Load(const P3DChunk&);

	const std::string& GetName() { return _name; }
	const uint32_t GetWidth() { return _width; }
	const uint32_t GetHeight() { return _height; }
	const uint32_t GetBPP() { return _bpp; }
	const ImageData& GetData() { return _data; }

  private:
	std::string _name;
	uint32_t _width;
	uint32_t _height;
	uint32_t _bpp;

	ImageData _data;
};

} // namespace Donut::P3D
