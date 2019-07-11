#pragma once

#include <P3D/P3DChunk.h>
#include <memory>

namespace Donut::P3D {

class AnimationGroupList {
public:
	AnimationGroupList() {}

	static std::unique_ptr<AnimationGroupList> Load(const P3DChunk&);
private:
};

} // namespace Donut::P3D
