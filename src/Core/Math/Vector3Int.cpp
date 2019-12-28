// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "Vector3Int.h"

#include <fmt/format.h>

namespace Donut
{

const Vector3Int Vector3Int::Zero(0, 0, 0);
const Vector3Int Vector3Int::One(1, 1, 1);
const Vector3Int Vector3Int::Up(0, 1, 0);
const Vector3Int Vector3Int::Down(0, -1, 0);
const Vector3Int Vector3Int::Forward(0, 0, 1);
const Vector3Int Vector3Int::Backward(0, 0, -1);
const Vector3Int Vector3Int::Right(1, 0, 0);
const Vector3Int Vector3Int::Left(-1, 0, 0);

std::string Vector3Int::ToString() const
{
	return fmt::format("({:d}, {:d}, {:d})", X, Y, Z);
}

} // namespace Donut
