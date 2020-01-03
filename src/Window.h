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

	operator SDL_Window*() { return _window.get(); }
	operator SDL_GLContext*() { return _glContext.get(); }

	const std::string GetTitle() const;
	void SetTitle(const std::string&);

	void Swap();

private:
	std::unique_ptr<SDL_Window, SDLDestroyer> _window;
	std::unique_ptr<SDL_Renderer, SDLDestroyer> _renderer;
	std::unique_ptr<SDL_GLContext, SDLDestroyer> _glContext;
};
} // namespace Donut
