#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/SkeletonJoint.h>

#include <memory>

namespace Donut::P3D {

// acts like a factory:
class SkeletonJointLoader {
public:
	// I think we need a LoadFromChunk thing
    std::unique_ptr<SkeletonJoint> Load(const P3DChunk&);
};

} // namespace Donut::P3D
