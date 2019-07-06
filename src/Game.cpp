#include <Game.h>
#include <SDL.h>
#include <Window.h>

#include <Pure3D/Pure3D.h>

#include <string>

namespace Donut {

const std::string kWindowTitle = "donut";

Game::Game(int argc, char** argv)
{
	int windowWidth = 1280, windowHeight = 1024;
	_window = std::make_unique<Window>(kWindowTitle, windowWidth, windowHeight);

	File file("wrench.p3d", FileMode::Read);

	Pure3D::Pure3D p3d;
	p3d.LoadFromFile(file);

	file.Close();
}

Game::~Game() {
    SDL_Quit();
}

void Game::Run() {
    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;
        }

        _window->Swap();
    }
}

} // namespace donut
