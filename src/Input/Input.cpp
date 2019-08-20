// Copyright 2019 the donut authors. See AUTHORS.md

#include "Input.h"

#include <iostream>

namespace Donut
{
std::map<SDL_Keycode, Button> Input::KeyCodeToButtonCodeMap = {
	{ SDLK_UNKNOWN, Button::None },
	{ SDLK_0, Button::Key0 },
	{ SDLK_1, Button::Key1 },
	{ SDLK_2, Button::Key2 },
	{ SDLK_3, Button::Key3 },
	{ SDLK_4, Button::Key4 },
	{ SDLK_5, Button::Key5 },
	{ SDLK_6, Button::Key6 },
	{ SDLK_7, Button::Key7 },
	{ SDLK_8, Button::Key8 },
	{ SDLK_9, Button::Key9 },

	{ SDLK_a, Button::KeyA },
	{ SDLK_b, Button::KeyB },
	{ SDLK_c, Button::KeyC },
	{ SDLK_d, Button::KeyD },
	{ SDLK_e, Button::KeyE },
	{ SDLK_f, Button::KeyF },
	{ SDLK_g, Button::KeyG },
	{ SDLK_h, Button::KeyH },
	{ SDLK_i, Button::KeyI },
	{ SDLK_j, Button::KeyJ },
	{ SDLK_k, Button::KeyK },
	{ SDLK_l, Button::KeyL },
	{ SDLK_m, Button::KeyM },
	{ SDLK_n, Button::KeyN },
	{ SDLK_o, Button::KeyO },
	{ SDLK_p, Button::KeyP },
	{ SDLK_q, Button::KeyQ },
	{ SDLK_r, Button::KeyR },
	{ SDLK_s, Button::KeyS },
	{ SDLK_t, Button::KeyT },
	{ SDLK_u, Button::KeyU },
	{ SDLK_v, Button::KeyV },
	{ SDLK_w, Button::KeyW },
	{ SDLK_x, Button::KeyX },
	{ SDLK_y, Button::KeyY },
	{ SDLK_z, Button::KeyZ },

	{ SDLK_KP_0, Button::KeyPad0 },
	{ SDLK_KP_1, Button::KeyPad1 },
	{ SDLK_KP_2, Button::KeyPad2 },
	{ SDLK_KP_3, Button::KeyPad3 },
	{ SDLK_KP_4, Button::KeyPad4 },
	{ SDLK_KP_5, Button::KeyPad5 },
	{ SDLK_KP_6, Button::KeyPad6 },
	{ SDLK_KP_7, Button::KeyPad7 },
	{ SDLK_KP_8, Button::KeyPad8 },
	{ SDLK_KP_9, Button::KeyPad9 },

	{ SDLK_KP_DIVIDE, Button::KeyPadDIVIDE },
	{ SDLK_KP_MULTIPLY, Button::KeyPadMULTIPLY },
	{ SDLK_KP_MINUS, Button::KeyPadMINUS },
	{ SDLK_KP_PLUS, Button::KeyPadPLUS },
	{ SDLK_KP_ENTER, Button::KeyPadENTER },
	{ SDLK_KP_DECIMAL, Button::KeyPadDECIMAL },

	{ SDLK_LEFTBRACKET, Button::KeyLBRACKET },
	{ SDLK_RIGHTBRACKET, Button::KeyRBRACKET },
	{ SDLK_SEMICOLON, Button::KeySEMICOLON },
	{ SDLK_QUOTE, Button::KeyAPOSTROPHE },
	{ SDLK_BACKQUOTE, Button::KeyBACKQUOTE },
	{ SDLK_COMMA, Button::KeyCOMMA },
	{ SDLK_PERIOD, Button::KeyPERIOD },
	{ SDLK_SLASH, Button::KeySLASH },
	{ SDLK_BACKSLASH, Button::KeyBACKSLASH },
	{ SDLK_MINUS, Button::KeyMINUS },
	{ SDLK_EQUALS, Button::KeyEQUAL },
	{ SDLK_RETURN, Button::KeyENTER },
	{ SDLK_SPACE, Button::KeySPACE },
	{ SDLK_BACKSPACE, Button::KeyBACKSPACE },
	{ SDLK_TAB, Button::KeyTAB },
	{ SDLK_CAPSLOCK, Button::KeyCAPSLOCK },
	{ SDLK_NUMLOCKCLEAR, Button::KeyNUMLOCK },
	{ SDLK_ESCAPE, Button::KeyESCAPE },
	{ SDLK_SCROLLLOCK, Button::KeySCROLLLOCK },
	{ SDLK_INSERT, Button::KeyINSERT },
	{ SDLK_DELETE, Button::KeyDELETE },
	{ SDLK_HOME, Button::KeyHOME },
	{ SDLK_END, Button::KeyEND },
	{ SDLK_PAGEUP, Button::KeyPAGEUP },
	{ SDLK_PAGEDOWN, Button::KeyPAGEDOWN },
	{ SDLK_PAUSE, Button::KeyPAUSE },
	{ SDLK_LSHIFT, Button::KeyLSHIFT },
	{ SDLK_RSHIFT, Button::KeyRSHIFT },
	{ SDLK_LALT, Button::KeyLALT },
	{ SDLK_RALT, Button::KeyRALT },
	{ SDLK_LCTRL, Button::KeyLCONTROL },
	{ SDLK_RCTRL, Button::KeyRCONTROL },
	{ SDLK_LGUI, Button::KeyLGUI },
	{ SDLK_RGUI, Button::KeyRGUI },
	{ SDLK_APPLICATION, Button::KeyAPP },

	{ SDLK_UP, Button::KeyUp },
	{ SDLK_LEFT, Button::KeyLeft },
	{ SDLK_DOWN, Button::KeyDown },
	{ SDLK_RIGHT, Button::KeyRight },

	{ SDLK_F1, Button::F1 },
	{ SDLK_F2, Button::F2 },
	{ SDLK_F3, Button::F3 },
	{ SDLK_F4, Button::F4 },
	{ SDLK_F5, Button::F5 },
	{ SDLK_F6, Button::F6 },
	{ SDLK_F7, Button::F7 },
	{ SDLK_F8, Button::F8 },
	{ SDLK_F9, Button::F9 },
	{ SDLK_F10, Button::F10 },
	{ SDLK_F11, Button::F11 },
	{ SDLK_F12, Button::F12 },

	{ SDLK_PRINTSCREEN, Button::PrintScreen },
};

Input::ButtonState Input::ButtonStates[to_underlying(Button::Count)] = { ButtonState() };
float Input::MouseDeltaX                                             = 0.0f;
float Input::MouseDeltaY                                             = 0.0f;
std::unique_ptr<ITextEntryEventHandler> Input::TextEntry             = nullptr;

Button Input::KeyCodeToButtonCode(SDL_Keycode key)
{
	auto it = KeyCodeToButtonCodeMap.find(key);
	return (it != KeyCodeToButtonCodeMap.end()) ? it->second : Button::None;
}

void Input::UpdateButton(Button button, bool down)
{
	auto& buttonState    = ButtonStates[to_underlying(button)];
	buttonState.Pressed  = !buttonState.Down && down;
	buttonState.Released = buttonState.Down && !down;
	buttonState.Down     = down;
}

void Input::ResetMouseDelta()
{
	MouseDeltaX = 0.0f;
	MouseDeltaY = 0.0f;
}

void Input::PreEvent()
{
	ResetMouseDelta();

	for (size_t i = 0; i < to_underlying(Button::Count); ++i)
	{
		auto& buttonState    = ButtonStates[i];
		buttonState.Pressed  = false;
		buttonState.Released = false;
	}
}

void Input::HandleEvent(const SDL_Event& e)
{
	if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
	{
		UpdateButton(KeyCodeToButtonCode(e.key.keysym.sym), e.key.state == SDL_PRESSED);
	}
	else if (e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
	{
		UpdateButton((Button)(e.button.button), (e.button.state == SDL_PRESSED));
	}
	else if (e.type == SDL_MOUSEMOTION)
	{
		MouseDeltaX += (float)e.motion.xrel;
		MouseDeltaY += (float)e.motion.yrel;
	}
	else if (e.type == SDL_TEXTINPUT)
	{
		if (TextEntry != nullptr)
		{
			TextEntry->Call(e.text.text);
		}
	}
}

float Input::GetMouseDeltaX()
{
	return MouseDeltaX;
}

float Input::GetMouseDeltaY()
{
	return MouseDeltaY;
}

bool Input::IsDown(Button button)
{
	return ButtonStates[to_underlying(button)].Down;
}

bool Input::JustPressed(Button button)
{
	return ButtonStates[to_underlying(button)].Pressed;
}

bool Input::JustReleased(Button button)
{
	return ButtonStates[to_underlying(button)].Released;
}

void Input::ReleaseTextEntry()
{
	if (TextEntry != nullptr)
	{
		TextEntry = nullptr;
		SDL_StopTextInput();
	}
}
} // namespace Donut
