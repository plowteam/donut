// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <type_traits>

namespace Donut
{
enum class Button : std::size_t
{
	None = 0,

	MouseLeft,
	MouseMiddle,
	MouseRight,
	Mouse4,
	Mouse5,

	Key0,
	Key1,
	Key2,
	Key3,
	Key4,
	Key5,
	Key6,
	Key7,
	Key8,
	Key9,

	KeyA,
	KeyB,
	KeyC,
	KeyD,
	KeyE,
	KeyF,
	KeyG,
	KeyH,
	KeyI,
	KeyJ,
	KeyK,
	KeyL,
	KeyM,
	KeyN,
	KeyO,
	KeyP,
	KeyQ,
	KeyR,
	KeyS,
	KeyT,
	KeyU,
	KeyV,
	KeyW,
	KeyX,
	KeyY,
	KeyZ,

	KeyPad0,
	KeyPad1,
	KeyPad2,
	KeyPad3,
	KeyPad4,
	KeyPad5,
	KeyPad6,
	KeyPad7,
	KeyPad8,
	KeyPad9,

	KeyPadDIVIDE,
	KeyPadMULTIPLY,
	KeyPadMINUS,
	KeyPadPLUS,
	KeyPadENTER,
	KeyPadDECIMAL,

	KeyLBRACKET,
	KeyRBRACKET,
	KeySEMICOLON,
	KeyAPOSTROPHE,
	KeyBACKQUOTE,
	KeyCOMMA,
	KeyPERIOD,
	KeySLASH,
	KeyBACKSLASH,
	KeyMINUS,
	KeyEQUAL,
	KeyENTER,
	KeySPACE,
	KeyBACKSPACE,
	KeyTAB,
	KeyCAPSLOCK,
	KeyNUMLOCK,
	KeyESCAPE,
	KeySCROLLLOCK,
	KeyINSERT,
	KeyDELETE,
	KeyHOME,
	KeyEND,
	KeyPAGEUP,
	KeyPAGEDOWN,
	KeyPAUSE,
	KeyLSHIFT,
	KeyRSHIFT,
	KeyLALT,
	KeyRALT,
	KeyLCONTROL,
	KeyRCONTROL,
	KeyLGUI,
	KeyRGUI,
	KeyAPP,

	KeyUp,
	KeyLeft,
	KeyDown,
	KeyRight,

	F1,
	F2,
	F3,
	F4,
	F5,
	F6,
	F7,
	F8,
	F9,
	F10,
	F11,
	F12,

	PrintScreen,

	Count,
};

template <typename E>
constexpr auto to_underlying(E e) noexcept
{
	return static_cast<std::underlying_type_t<E>>(e);
}
} // namespace Donut
