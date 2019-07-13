#pragma once

#include <glm/glm.hpp>

namespace Donut
{

class AABB
{
public:
	AABB();
	AABB(const glm::vec3& min, const glm::vec3& max) : _min(min), _max(max) {}
	//AABB(const glm::vec3& center, float radius);

	//glm::vec3 GetCenter() const;
	glm::vec3 GetMin() const { return _min; }
	glm::vec3 GetMax() const { return _max; }
private:
	glm::vec3 _min;
	glm::vec3 _max;
};

} // namespace Donut
