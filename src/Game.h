#pragma once

#include <memory>
#include <Pure3D/Pure3D.h>

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
    void debugDrawP3D(const std::string&, const Pure3D::Pure3D&);

    std::unique_ptr<Window> _window;
    std::unique_ptr<Pure3D::Pure3D> _p3d;
};

} // namespace Donut
