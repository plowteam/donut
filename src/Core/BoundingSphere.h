#pragma once

#include <glm/glm.hpp>

namespace Donut
{

class BoundingSphere
{
  public:
	BoundingSphere();
	BoundingSphere(const glm::vec3& center, const float radius):
	    _center(center), _radius(radius) {}

	glm::vec3 GetCenter() const { return _center; }
	float GetRadius() const { return _radius; }

  private:
	glm::vec3 _center;
	float _radius;
};

} // namespace Donut
