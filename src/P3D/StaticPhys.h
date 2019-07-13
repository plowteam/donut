#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/CollisionObject.h>
#include <memory>
#include <string>

namespace Donut::P3D
{

// StaticEntity only used in world files it seems
class StaticPhys
{
  public:
	StaticPhys(const std::string& name, std::unique_ptr<CollisionObject> obj):
	    _name(name), _collisionObject(std::move(obj)) {}

	static std::unique_ptr<StaticPhys> Load(const P3DChunk&);

	const std::string& GetName() const { return _name; }
	const CollisionObject& GetCollisionObject() const { return *_collisionObject; }

  private:
	std::string _name;
	std::unique_ptr<CollisionObject> _collisionObject;
};

} // namespace Donut::P3D
