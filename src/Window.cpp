#include <Window.h>

#include <iostream>

namespace Donut {

Window::Window(const std::string& title, const int width, const int height) {
    SDL_version compiledVersion, linkedVersion;
    SDL_VERSION(&compiledVersion);
    SDL_GetVersion(&linkedVersion);

    std::clog << "Initializing SDL..." << std::endl;
    std::clog << "SDL Version/Compiled " << uint32_t(compiledVersion.major) << "."
              << uint32_t(compiledVersion.minor) << "." << uint32_t(compiledVersion.patch)
              << std::endl;
    std::clog << "SDL Version/Linked " << uint32_t(linkedVersion.major) << "."
              << uint32_t(linkedVersion.minor) << "." << uint32_t(linkedVersion.patch) << std::endl;

    // Initialize SDL
    if (SDL_WasInit(0) == 0) {
        SDL_SetMainReady();
        if (SDL_Init(0) != 0)
            throw std::runtime_error("Could not initialize SDL: " + std::string(SDL_GetError()));

        if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
            throw std::runtime_error("Could not initialize SDL Video Subsystem: " +
                                     std::string(SDL_GetError()));

        if (SDL_InitSubSystem(SDL_INIT_TIMER) != 0)
            throw std::runtime_error("Could not initialize SDL Timer Subsystem: " +
                                     std::string(SDL_GetError()));
    }

    const uint32_t flags = SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_ALLOW_HIGHDPI;

    auto window = std::unique_ptr<SDL_Window, SDLDestroyer>(SDL_CreateWindow(
        title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags));

    if (window == nullptr) {
        throw std::runtime_error("Failed creating window: " + std::string(SDL_GetError()));
    }

    _window = std::move(window);
}

void Window::SetTitle(const std::string& title) {
    SDL_SetWindowTitle(_window.get(), title.c_str());
}

const std::string Window::GetTitle() const {
    return SDL_GetWindowTitle(_window.get());
}

void Window::Swap() {
    SDL_GL_SwapWindow(_window.get());
}

} // namespace donut
