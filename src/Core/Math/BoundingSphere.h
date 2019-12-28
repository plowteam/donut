// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Vector3.h"

namespace Donut
{

class BoundingSphere
{
public:
	BoundingSphere(): _center(Vector3(0.0f)), _radius(0.0f) {}
	BoundingSphere(const Vector3& center, const float radius): _center(center), _radius(radius) {}

	Vector3 GetCenter() const { return _center; }
	float GetRadius() const { return _radius; }

private:
	Vector3 _center;
	float _radius;
};

} // namespace Donut
