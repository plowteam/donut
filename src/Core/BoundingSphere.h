// Copyright 2019 the donut authors. See AUTHORS.md

#pragma once

#include <glm/glm.hpp>

namespace Donut
{

class BoundingSphere
{
  public:
	BoundingSphere():
	    _center(glm::vec3(0.0f)), _radius(0.0f) {}
	BoundingSphere(const glm::vec3& center, const float radius):
	    _center(center), _radius(radius) {}

	glm::vec3 GetCenter() const { return _center; }
	float GetRadius() const { return _radius; }

  private:
	glm::vec3 _center;
	float _radius;
};

} // namespace Donut
