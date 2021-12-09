// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include "Entity.h"
#include "Core/Math/Vector2Int.h"

#include <cstdint>
#include <string>
#include <vector>

using namespace Donut;

namespace donut::pure3d
{

class Texture: public Entity
{
public:
	enum class Format
	{
		R8,
		RG8,
		RGB8,
		RGBA8,
	};

	enum class Interpolation
	{
		Nearest,
		Bilinear,
	};

	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
	Format GetFormat() const { return _format; }

	unsigned int GetTexture() const { return _texture; }

	unsigned int GetNativeTextureHandle() const { return _texture; }

	virtual std::string GetClassName() const override { return "Texture"; }
protected:
	Texture();
	~Texture();
	void Create(int width, int height, Format format, const std::vector<uint8_t>& data);

	unsigned int _texture;
	int _width;
	int _height;
	Format _format;

	friend class TextureLoader;
};

} // namespace Donut
