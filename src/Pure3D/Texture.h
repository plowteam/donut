// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include "Core/Object.h"
#include "Core/Math/Vector2Int.h"

#include <cstdint>
#include <string>
#include <vector>

namespace Donut
{

class Texture: public Object
{
public:
	Texture();
	~Texture();

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

	void Create(int width, int height, Format format, const std::vector<uint8_t>& data);

	int GetWidth() const { return _width; }
	int GetHeight() const { return _height; }
	Vector2Int GetSize() const { return Vector2Int(_width, _height); }
	Format GetFormat() const { return _format; }

	void Bind() const;
	void Bind(unsigned int slot) const;

	unsigned int GetNativeTextureHandle() const { return _texture; }
	std::size_t GetMemorySize() const { return _memorySize; }


	// bool HasAlpha();

	virtual std::string GetClassName() const override { return "Texture"; }
protected:
	unsigned int _texture;
	int _width;
	int _height;
	std::size_t _memorySize;
	Format _format;

	friend class TextureLoader;
};

} // namespace Donut
