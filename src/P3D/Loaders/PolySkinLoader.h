#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/PolySkin.h>

#include <memory>

namespace Donut::P3D {

// acts like a factory:
class PolySkinLoader {
public:
	// I think we need a LoadFromChunk thing
    std::unique_ptr<PolySkin> Load(const P3DChunk&);
};

} // namespace Donut::P3D
