// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "Vector3.h"

#include <fmt/format.h>

namespace Donut
{

const Vector3 Vector3::Zero(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::One(1.0f, 1.0f, 1.0f);
const Vector3 Vector3::Up(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::Down(0.0f, -1.0f, 0.0f);
const Vector3 Vector3::Forward(0.0f, 0.0f, 1.0f);
const Vector3 Vector3::Backward(0.0f, 0.0f, -1.0f);
const Vector3 Vector3::Right(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::Left(-1.0f, 0.0f, 0.0f);

std::string Vector3::ToString() const
{
	return fmt::format("({:3.3f}, {:3.3f}, {:3.3f})", X, Y, Z);
}

} // namespace Donut
