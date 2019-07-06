#include <Game.h>
#include <SDL.h>
#include <Window.h>

#include <string>

namespace Donut {

const std::string kWindowTitle = "donut";

Game::Game(int argc, char** argv) {
    const int windowWidth = 1280, windowHeight = 1024;
    _window = std::make_unique<Window>(kWindowTitle, windowWidth, windowHeight);
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
