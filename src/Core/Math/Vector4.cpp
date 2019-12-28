// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "Vector4.h"

#include <fmt/format.h>

namespace Donut
{

const Vector4 Vector4::Zero(0.0f, 0.0f, 0.0f, 0.0f);
const Vector4 Vector4::One(0.0f, 0.0f, 0.0f, 0.0f);

std::string Vector4::ToString() const
{
	return fmt::format("({:3.3f}, {:3.3f}, {:3.3f}, {:3.3f})", X, Y, Z, W);
}

} // namespace Donut
