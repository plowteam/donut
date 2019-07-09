#pragma once

namespace Donut::P3D {

class PolySkin {
public:
	PolySkin(const std::string& name, const std::string& skeletonName) :
		_name(name), _skeletonName(skeletonName) {}

	std::string& GetName() { return _name; }
	std::string& GetSkeletonName() { return _skeletonName; }
private:
	std::string _name;
	std::string _skeletonName;
};

} // namespace Donut::P3D
