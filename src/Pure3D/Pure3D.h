#pragma once

#include <Pure3D/Chunk.h>

namespace Donut::Pure3D {

enum class FileTypes : uint32_t {
    P3D = 0xFF443350,  // 'P3D'
    P3DZ = 0x5A443350, // 'P3DZ' proprietary compression
    RZ = 0x5A52,       // 'RZ' (zlib deflate)
};

class Pure3D {
public:
    Pure3D();
    void LoadFromFile(File&);

    Chunk& GetRoot() {
        return _root;
    }

protected:
    Chunk _root;
};

} // namespace Donut::Pure3D
