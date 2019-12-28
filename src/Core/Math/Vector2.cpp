// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "Vector2.h"

#include "Core/Math/Vector2Int.h"

#include <fmt/format.h>

namespace Donut
{

const Vector2 Vector2::Zero(0.0f, 0.0f);
const Vector2 Vector2::One(0.0f, 0.0f);

Vector2::Vector2(const Vector2Int& v): X(static_cast<float>(v.X)), Y(static_cast<float>(v.Y)) {}

std::string Vector2::ToString() const
{
	return fmt::format("({:3.3f}, {:3.3f})", X, Y);
}

} // namespace Donut
