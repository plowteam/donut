// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Vector3.h"

namespace Donut
{

class BoundingBox
{
public:
	BoundingBox(): _min(Vector3(0.0f)), _max(Vector3(0.0f)) {}
	BoundingBox(const Vector3& min, const Vector3& max): _min(min), _max(max) {}

	Vector3 GetMin() const { return _min; }
	Vector3 GetMax() const { return _max; }

private:
	Vector3 _min;
	Vector3 _max;
};

} // namespace Donut
