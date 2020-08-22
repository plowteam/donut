// Copyright 2019-2020 the donut authors. See COPYING.md for legal info.

#pragma once

#include "Core/Object.h"
#include "Core/Math/Vector2Int.h"

#include <cstdint>
#include <string>
#include <vector>

namespace Donut
{

class Sprite: public Object
{
public:
	Sprite();
	~Sprite();

	virtual std::string GetClassName() const override { return "Sprite"; }
protected:

	friend class SpriteLoader;
};

} // namespace Donut
