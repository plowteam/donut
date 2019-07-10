#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/PrimGroup.h>

#include <memory>

namespace Donut::P3D {

class PrimGroupLoader {
public:
    std::unique_ptr<PrimGroup> Load(const P3DChunk&);
};

} // namespace Donut::P3D
