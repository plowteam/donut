// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <SDL.h>
#include <memory>
#include <string>

struct SDLDestroyer
{
	void operator()(SDL_Window* window) const { SDL_DestroyWindow(window); }
	void operator()(SDL_Renderer* renderer) const { SDL_DestroyRenderer(renderer); }
	void operator()(SDL_GLContext* glcontext) const { SDL_GL_DeleteContext(*glcontext); }
};

namespace Donut
{

class Window
{
public:
	Window(const std::string& title, int width, int height);

	operator SDL_Window*() { return _window; }
	operator SDL_Renderer*() { return _renderer; }

	const std::string GetTitle() const;
	void SetTitle(const std::string&);

	void Swap();

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	EGLDisplay _display;
	EGLSurface _surface;
	EGLContext _context;
};
} // namespace Donut
