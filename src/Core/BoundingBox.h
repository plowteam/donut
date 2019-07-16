#pragma once

#include <glm/glm.hpp>

namespace Donut
{

class BoundingBox
{
public:
	BoundingBox();
	BoundingBox(const glm::vec3& min, const glm::vec3& max) : _min(min), _max(max) {}

	glm::vec3 GetMin() const { return _min; }
	glm::vec3 GetMax() const { return _max; }
private:
	glm::vec3 _min;
	glm::vec3 _max;
};

} // namespace Donut
