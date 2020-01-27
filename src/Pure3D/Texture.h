// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include "Core/Math/Vector3.h"
#include "Render/OpenGL/GLTexture2D.h"
#include "LoadObject.h"
#include "Name.h"

#include <cstdint>
#include <memory>
#include <string>

namespace Donut
{

class P3DTexture: public radLoadObject, public Name
{
public:
protected:
	uint32_t _width;
	uint32_t _height;
	uint32_t _bpp;
	uint32_t _alphaDepth;
	uint32_t _numMipMaps;
	uint32_t _textureType;
	uint32_t _usage;
	uint32_t _priority;

	// 
	//std::unique_ptr<GLTexture2D> _glTexture;

	friend class TextureLoader;
};

} // namespace Donut
