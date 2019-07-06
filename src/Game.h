#pragma once

#include <memory>

namespace Donut
{

class Window;

class Game
{
public:
	Game(int argc, char** argv);
	~Game();

	Window& GetWindow() { return *_window; }

	void Run();

private:
	std::unique_ptr<Window> _window;
};

} // namespace Donut
