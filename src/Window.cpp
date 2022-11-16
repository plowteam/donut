// Copyright 2019-2020 the donut authors. See AUTHORS.md

#include "Render/OpenGL/glad/glad.h"
#include <Window.h>
#include <iostream>
#include <switch.h>

namespace Donut
{

Window::Window(const std::string& title, const int width, const int height)
{
	SDL_version compiledVersion, linkedVersion;
	SDL_VERSION(&compiledVersion);
	SDL_GetVersion(&linkedVersion);

	std::clog << "Initializing SDL..." << std::endl;
	std::clog << "SDL Version/Compiled " << uint32_t(compiledVersion.major) << "." << uint32_t(compiledVersion.minor) << "."
	          << uint32_t(compiledVersion.patch) << std::endl;
	std::clog << "SDL Version/Linked " << uint32_t(linkedVersion.major) << "." << uint32_t(linkedVersion.minor) << "."
	          << uint32_t(linkedVersion.patch) << std::endl;

	// init SDL2
	// on switch we don't init video and just use EGL
	printf("Initializing SDL!\n");
	if (SDL_WasInit(0) == 0)
	{
		SDL_SetMainReady();
		if (SDL_Init(SDL_INIT_JOYSTICK | SDL_INIT_TIMER) != 0)
			throw std::runtime_error("Could not initialize SDL: " + std::string(SDL_GetError()));
	}

	// we start init of EGL here...
	// it's based on
	// https://github.com/switchbrew/switch-examples/blob/73960d720c2376fd0eea0edb72a8d56b59db05cd/graphics/opengl/lenny/source/main.cpp
	_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
	if (_display == nullptr)
		throw std::runtime_error("Couldn't get EGL display: " + std::to_string(eglGetError()));

	// init display connection
	eglInitialize(_display, NULL, NULL);

	// bind api (just use OpenGL)
	if (eglBindAPI(EGL_OPENGL_API) == EGL_FALSE)
		throw std::runtime_error("Couldn't bind EGL API: " + std::to_string(eglGetError()));

	// find suitable config
	EGLConfig config;
	EGLint numConfigs;
	static const EGLint framebufferAttributeList[] = {EGL_RENDERABLE_TYPE,
	                                                  EGL_OPENGL_BIT,
	                                                  EGL_RED_SIZE,
	                                                  8,
	                                                  EGL_GREEN_SIZE,
	                                                  8,
	                                                  EGL_BLUE_SIZE,
	                                                  8,
	                                                  EGL_ALPHA_SIZE,
	                                                  8,
	                                                  EGL_DEPTH_SIZE,
	                                                  24,
	                                                  EGL_STENCIL_SIZE,
	                                                  8,
	                                                  EGL_NONE};
	eglChooseConfig(_display, framebufferAttributeList, &config, 1, &numConfigs);
	if (numConfigs == 0)
		throw std::runtime_error("Couldn't find EGL configs: " + std::to_string(eglGetError()));

	// create the window surface with the current display and the default window
	_surface = eglCreateWindowSurface(_display, config, nwindowGetDefault(), NULL);
	if (!_surface)
		throw std::runtime_error("Couldn't create EGL surface: " + std::to_string(eglGetError()));

	static const EGLint ctxAttributeList[] = {EGL_CONTEXT_OPENGL_PROFILE_MASK, EGL_CONTEXT_OPENGL_COMPATIBILITY_PROFILE_BIT,
	                                          EGL_NONE};

	// create the rendering context
	_context = eglCreateContext(_display, config, EGL_NO_CONTEXT, ctxAttributeList);
	if (!_context)
		throw std::runtime_error("Couldn't create EGL context: %d" + std::to_string(eglGetError()));

	// bind context & surface
	eglMakeCurrent(_display, _surface, _surface, _context);

	// use GLAD to load OpenGL
	gladLoadGL();
}

void Window::SetTitle(const std::string& title)
{
	SDL_SetWindowTitle(_window, title.c_str());
}

const std::string Window::GetTitle() const
{
	return SDL_GetWindowTitle(_window);
}

void Window::Swap()
{
	eglSwapBuffers(_display, _surface);
}

} // namespace Donut
