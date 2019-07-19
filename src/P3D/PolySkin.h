#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/PrimGroup.h>
#include <Core/BoundingBox.h>
#include <Core/BoundingSphere.h>

namespace Donut::P3D
{

class PolySkin
{
  public:
	PolySkin(const std::string& name, const std::string& skeletonName, std::vector<std::unique_ptr<PrimGroup>> primGroups, const BoundingBox& boundingBox, const BoundingSphere& boundingSphere):
	    _name(name), _skeletonName(skeletonName), _primGroups(std::move(primGroups)), _boundingBox(boundingBox), _boundingSphere(boundingSphere) {}

	static std::unique_ptr<PolySkin> Load(const P3DChunk&);

	const std::string& GetName() const { return _name; }
	const std::string& GetSkeletonName() const { return _skeletonName; }
	const std::vector<std::unique_ptr<PrimGroup>>& GetPrimGroups() const { return _primGroups; }

	const BoundingBox& GetBoundingBox() const { return _boundingBox; }
	const BoundingSphere& GetBoundingSphere() const { return _boundingSphere; }
  private:
	std::string _name;
	std::string _skeletonName;
	std::vector<std::unique_ptr<PrimGroup>> _primGroups;

	BoundingBox _boundingBox;
	BoundingSphere _boundingSphere;
};

} // namespace Donut::P3D
