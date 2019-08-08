// Copyright 2019 the donut authors. See AUTHORS.md

#include <Game.h>
#include <SDL.h>
#include <iostream>
#include <memory>

#ifdef _WIN32
#include <Windows.h>
#endif 

int main(int argc, char** argv)
{
	std::cout << "+---------------------------------------------------+\n"
	             "|    _____        /--------------------------\\      |\n"
	             "|   /     \\      |                            |     |\n"
	             "| \\/\\/     |    /     donut game               \\    |\n"
	             "|  |  (o)(o)    |                              |    |\n"
	             "|  C   .---_)   \\_   _________________________/     |\n"
	             "|   | |.___|      | /                               |\n"
	             "|   |  \\__/      <_/                                |\n"
	             "|   /_____\\                                         |\n"
	             "|  /_____/ \\                                        |\n"
	             "| /         \\                                       |\n"
	             "+---------------------------------------------------+\n"
	          << std::endl;

	#ifdef NDEBUG
	try {
	#endif
		const auto game = std::make_unique<Donut::Game>(argc, argv);
		game->Run();
	#ifdef NDEBUG
	}
	catch (std::runtime_error& e)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Fatal error", e.what(), nullptr);
		return EXIT_FAILURE;
	}
	#endif

	return EXIT_SUCCESS;
}

#if defined(_WIN32) && !defined(_CONSOLE)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	return main(__argc, __argv);
}
#endif
