#pragma once

#include <memory>
#include <P3D/P3DFile.h>

namespace Donut {

class Window;

class Game {
public:
    Game(int argc, char** argv);
    ~Game();

    Window& GetWindow() const {
        return *_window;
    }

    void Run();
private:
    void createMesh();
    void debugDrawP3D(const std::string&, const P3D::P3DFile&);

    std::unique_ptr<Window> _window;
    std::unique_ptr<P3D::P3DFile> _p3d;
};

} // namespace Donut
