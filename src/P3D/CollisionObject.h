#pragma once

#include <P3D/P3DChunk.h>
#include <memory>
#include <string>
#include <glm/vec3.hpp>

namespace Donut::P3D
{

class CollisionBoundingBox
{
  public:
	CollisionBoundingBox(glm::vec3 size, glm::vec3 center, glm::vec3 rotX, glm::vec3 rotY, glm::vec3 rotZ):
	    _size(size), _center(center), _rotX(rotX), _rotY(rotY), _rotZ(rotZ)
	{
	}

	static CollisionBoundingBox Load(const P3DChunk&);

	const glm::vec3& GetSize() const { return _size; }
	const glm::vec3& GetCenter() const { return _center; }
	const glm::vec3& GetRotX() const { return _rotX; }
	const glm::vec3& GetRotY() const { return _rotY; }
	const glm::vec3& GetRotZ() const { return _rotZ; }

  private:
	glm::vec3 _size;
	glm::vec3 _center;
	glm::vec3 _rotX;
	glm::vec3 _rotY;
	glm::vec3 _rotZ;
};

class CollisionVolume
{
  public:
	CollisionVolume() {}

	static std::unique_ptr<CollisionVolume> Load(const P3DChunk&);

  private:
	std::vector<std::unique_ptr<CollisionVolume>> _subVolumes;
	std::unique_ptr<CollisionBoundingBox> _boundingBox;
};

class CollisionObject
{
  public:
	CollisionObject(const std::string& name, std::unique_ptr<CollisionVolume> volume):
	    _name(name), _collisionVolume(std::move(volume)) {}

	static std::unique_ptr<CollisionObject> Load(const P3DChunk&);

	const std::string& GetName() const { return _name; }
	const CollisionVolume& GetVolume() const { return *_collisionVolume; }

  private:
	std::string _name;
	std::unique_ptr<CollisionVolume> _collisionVolume;
};

} // namespace Donut::P3D
