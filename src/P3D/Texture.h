#pragma once

#include <memory>
#include <string>

namespace Donut::P3D {

struct ImageData
{
	int width;
	int height;
	int comp;
	std::vector<std::uint8_t> data;
};

class Texture {
public:
    Texture(const std::string& name, std::uint32_t width, std::uint32_t height, std::uint32_t bpp, ImageData data) :
		_name(name), _width(width), _height(height), _bpp(bpp), _data(data) {}

	const std::string& GetName() { return _name; }
	const std::uint32_t GetWidth() { return _width; }
	const std::uint32_t GetHeight() { return _height; }
	const std::uint32_t GetBPP() { return _bpp; }
	const ImageData& GetData() { return _data; }

  private:
	std::string _name;
	std::uint32_t _width;
	std::uint32_t _height;
	std::uint32_t _bpp;

	ImageData _data;
};

} // namespace Donut::P3D
