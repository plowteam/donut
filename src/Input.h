#pragma once

#include <SDL.h>
#include <map>
#include "ButtonCodes.h"

namespace Donut
{
	class Input
	{

	public:

		Input() = delete;
		~Input() = delete;

		static void PreEvent();
		static void HandleEvent(const SDL_Event& e);

		static bool IsDown(Button button);
		static bool JustPressed(Button button);
		static bool JustReleased(Button button);
		static float GetMouseDeltaX();
		static float GetMouseDeltaY();

	private:

		struct ButtonState
		{
			ButtonState() :
				Pressed(false), Released(false), Down(false) {};

			bool Pressed;
			bool Released;
			bool Down;
		};

		static void UpdateButton(Button button, bool down);

		static float MouseDeltaX;
		static float MouseDeltaY;

		static Button KeyCodeToButtonCode(SDL_Keycode key);
		static std::map<SDL_Keycode, Button> KeyCodeToButtonCodeMap;
		static ButtonState ButtonStates[to_underlying(Button::Count)];

	};
}
