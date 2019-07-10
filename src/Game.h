#pragma once

#include <memory>
#include <SkinModel.h>

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
    void LoadModel(const std::string&);

private:
    void loadGlobal();
    void debugDrawP3D(const P3D::P3DFile&);

    std::unique_ptr<Window> _window;
    std::unique_ptr<SkinModel> _skinModel;
    std::unique_ptr<P3D::P3DFile> _globalP3D;

	glm::vec3 _lookAt;
    glm::vec3 _camPos;
};

} // namespace Donut
