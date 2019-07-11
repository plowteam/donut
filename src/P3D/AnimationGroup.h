#pragma once

#include <P3D/P3DChunk.h>
#include <memory>

namespace Donut::P3D {

class AnimationGroup {
public:
	AnimationGroup() {}

	static std::unique_ptr<AnimationGroup> Load(const P3DChunk&);
private:
};

} // namespace Donut::P3D
