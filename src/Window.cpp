#include <Window.h>
#include <glad/glad.h>
#include <iostream>

namespace Donut
{

Window::Window(const std::string& title, const int width, const int height)
{
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
	if (SDL_WasInit(0) == 0)
	{
		SDL_SetMainReady();
		if (SDL_Init(0) != 0) throw std::runtime_error("Could not initialize SDL: " + std::string(SDL_GetError()));

		if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0)
			throw std::runtime_error("Could not initialize SDL Video Subsystem: " +
			                         std::string(SDL_GetError()));

		if (SDL_InitSubSystem(SDL_INIT_TIMER) != 0)
			throw std::runtime_error("Could not initialize SDL Timer Subsystem: " +
			                         std::string(SDL_GetError()));
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_DEBUG_FLAG);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

	const uint32_t flags = SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_FOCUS | SDL_WINDOW_ALLOW_HIGHDPI;

	auto window = std::unique_ptr<SDL_Window, SDLDestroyer>(SDL_CreateWindow(
	    title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags));

	if (window == nullptr)
	{
		throw std::runtime_error("Failed creating window: " + std::string(SDL_GetError()));
	}

	_window = std::move(window);

	SDL_Renderer* renderer = SDL_CreateRenderer(_window.get(), -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
	{
		std::cerr << "SDL2 Renderer couldn't be created. Error: " << SDL_GetError() << std::endl;
		exit(1);
	}

	_renderer = std::move(std::unique_ptr<SDL_Renderer, SDLDestroyer>(renderer));

	auto context = SDL_GL_CreateContext(_window.get());

	// Create a OpenGL context on SDL2
	_glContext = std::move(std::unique_ptr<SDL_GLContext, SDLDestroyer>(&context));

	// Load GL extensions using glad
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
	{
		std::cerr << "Failed to initialize the OpenGL context." << std::endl;
		exit(1);
	}

	// Loaded OpenGL successfully.
	std::cout << "OpenGL version loaded: " << GLVersion.major << "." << GLVersion.minor
	          << std::endl;
}

void Window::SetTitle(const std::string& title)
{
	SDL_SetWindowTitle(_window.get(), title.c_str());
}

const std::string Window::GetTitle() const
{
	return SDL_GetWindowTitle(_window.get());
}

void Window::Swap()
{
	SDL_GL_SwapWindow(_window.get());
}

} // namespace Donut
