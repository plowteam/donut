// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Core/Math/Fwd.h"

#include <memory>
#include <string>

namespace Donut
{

/* forward declarations */
class SkinAnimation;

namespace P3D
{
class P3DChunk;
}

class AnimCamera
{
public:
	AnimCamera(const P3D::P3DChunk& chunk);

	static std::unique_ptr<AnimCamera> LoadP3D(const std::string& filename);

	Matrix4x4 Update(double dt);

private:
	double _time;
	std::unique_ptr<SkinAnimation> _trans;
	std::unique_ptr<SkinAnimation> _forward;
	std::unique_ptr<SkinAnimation> _up;
};
} // namespace Donut
