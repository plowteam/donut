#pragma once

#include <P3D/P3DChunk.h>
#include <memory>

namespace Donut::P3D {

class Animation {
public:
	Animation() {}

	static std::unique_ptr<Animation> Load(const P3DChunk&);
private:
};

} // namespace Donut::P3D
