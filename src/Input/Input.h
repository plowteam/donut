// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <Input/ButtonCodes.h>
#include <SDL.h>
#include <map>
#include <memory>
#include <string>

namespace Donut
{
class ITextEntryEventHandler
{

public:
	virtual ~ITextEntryEventHandler() {}

	virtual void Call(const std::string&) = 0;
};

template <class Instance>
class TextEntryEventHandler: public ITextEntryEventHandler
{

private:
	Instance* instance;
	typedef void (Instance::*Callback)(const std::string&);
	Callback callback;

public:
	TextEntryEventHandler(Instance* instance, Callback callback): instance(instance), callback(callback) {}

	void Call(const std::string& text) { (instance->*callback)(text); }
};

class Input
{

public:
	Input() = delete;
	~Input() = delete;

	static void PreEvent();
	static void ResetMouseDelta();
	static void HandleEvent(const SDL_Event& e);

	static bool IsDown(Button button);
	static bool JustPressed(Button button);
	static bool JustReleased(Button button);
	static float GetMouseDeltaX();
	static float GetMouseDeltaY();

	template <class Instance, typename Callback>
	static void CaptureTextEntry(Instance* instance, Callback callback)
	{
		if (TextEntry == nullptr)
		{
			SDL_StartTextInput();
		}

		TextEntry = std::make_unique<TextEntryEventHandler<Instance>>(instance, callback);
	}

	static void ReleaseTextEntry();

private:
	struct ButtonState
	{
		ButtonState(): Pressed(false), Released(false), Down(false) {};

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

	static std::unique_ptr<ITextEntryEventHandler> TextEntry;
};
} // namespace Donut
