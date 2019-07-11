#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/Skeleton.h>

#include <memory>

namespace Donut::P3D {

// acts like a factory:
class SkeletonLoader {
public:
	// I think we need a LoadFromChunk thing
    std::unique_ptr<Skeleton> Load(const P3DChunk&);
};

} // namespace Donut::P3D
