#include "KeyboardMapper.h"
#include "Logger.h"

using namespace uFramework;

sf::Keyboard::Key KeyboardMapper::get(std::string keyName)
{
	for (auto& c : keyName)
	{
		c = tolower(c);
	}

	if (keyName.compare("a") == 0) return sf::Keyboard::A;
	if (keyName.compare("b") == 0) return sf::Keyboard::B;
	if (keyName.compare("c") == 0) return sf::Keyboard::C;
	if (keyName.compare("d") == 0) return sf::Keyboard::D;
	if (keyName.compare("e") == 0) return sf::Keyboard::E;
	if (keyName.compare("f") == 0) return sf::Keyboard::F;
	if (keyName.compare("g") == 0) return sf::Keyboard::G;
	if (keyName.compare("h") == 0) return sf::Keyboard::H;
	if (keyName.compare("i") == 0) return sf::Keyboard::I;
	if (keyName.compare("j") == 0) return sf::Keyboard::J;
	if (keyName.compare("k") == 0) return sf::Keyboard::K;
	if (keyName.compare("l") == 0) return sf::Keyboard::L;
	if (keyName.compare("m") == 0) return sf::Keyboard::M;
	if (keyName.compare("n") == 0) return sf::Keyboard::N;
	if (keyName.compare("o") == 0) return sf::Keyboard::O;
	if (keyName.compare("p") == 0) return sf::Keyboard::P;
	if (keyName.compare("q") == 0) return sf::Keyboard::Q;
	if (keyName.compare("r") == 0) return sf::Keyboard::R;
	if (keyName.compare("s") == 0) return sf::Keyboard::S;
	if (keyName.compare("t") == 0) return sf::Keyboard::T;
	if (keyName.compare("u") == 0) return sf::Keyboard::U;
	if (keyName.compare("v") == 0) return sf::Keyboard::V;
	if (keyName.compare("w") == 0) return sf::Keyboard::W;
	if (keyName.compare("x") == 0) return sf::Keyboard::X;
	if (keyName.compare("y") == 0) return sf::Keyboard::Y;
	if (keyName.compare("z") == 0) return sf::Keyboard::Z;
	if (keyName.compare("num0") == 0) return sf::Keyboard::Num0;
	if (keyName.compare("num1") == 0) return sf::Keyboard::Num1;
	if (keyName.compare("num2") == 0) return sf::Keyboard::Num2;
	if (keyName.compare("num3") == 0) return sf::Keyboard::Num3;
	if (keyName.compare("num4") == 0) return sf::Keyboard::Num4;
	if (keyName.compare("num5") == 0) return sf::Keyboard::Num5;
	if (keyName.compare("num6") == 0) return sf::Keyboard::Num6;
	if (keyName.compare("num7") == 0) return sf::Keyboard::Num7;
	if (keyName.compare("num8") == 0) return sf::Keyboard::Num8;
	if (keyName.compare("num9") == 0) return sf::Keyboard::Num9;
	if (keyName.compare("escape") == 0) return sf::Keyboard::Escape;
	if (keyName.compare("lcontrol") == 0) return sf::Keyboard::LControl;
	if (keyName.compare("lshift") == 0) return sf::Keyboard::LShift;
	if (keyName.compare("lalt") == 0) return sf::Keyboard::LAlt;
	if (keyName.compare("lsystem") == 0) return sf::Keyboard::LSystem;
	if (keyName.compare("rcontrol") == 0) return sf::Keyboard::RControl;
	if (keyName.compare("rshift") == 0) return sf::Keyboard::RShift;
	if (keyName.compare("ralt") == 0) return sf::Keyboard::RAlt;
	if (keyName.compare("rsystem") == 0) return sf::Keyboard::RSystem;
	if (keyName.compare("menu") == 0) return sf::Keyboard::Menu;
	if (keyName.compare("lbracket") == 0) return sf::Keyboard::LBracket;
	if (keyName.compare("rbracket") == 0) return sf::Keyboard::RBracket;
	if (keyName.compare("semicolon") == 0) return sf::Keyboard::Semicolon;
	if (keyName.compare("comma") == 0) return sf::Keyboard::Comma;
	if (keyName.compare("period") == 0) return sf::Keyboard::Period;
	if (keyName.compare("quote") == 0) return sf::Keyboard::Quote;
	if (keyName.compare("slash") == 0) return sf::Keyboard::Slash;
	if (keyName.compare("backslash") == 0) return sf::Keyboard::Backslash;
	if (keyName.compare("tilde") == 0) return sf::Keyboard::Tilde;
	if (keyName.compare("equal") == 0) return sf::Keyboard::Equal;
	if (keyName.compare("hyphen") == 0) return sf::Keyboard::Hyphen;
	if (keyName.compare("space") == 0) return sf::Keyboard::Space;
	if (keyName.compare("enter") == 0) return sf::Keyboard::Enter;
	if (keyName.compare("backspace") == 0) return sf::Keyboard::Backspace;
	if (keyName.compare("tab") == 0) return sf::Keyboard::Tab;
	if (keyName.compare("pageup") == 0) return sf::Keyboard::PageUp;
	if (keyName.compare("pagedown") == 0) return sf::Keyboard::PageDown;
	if (keyName.compare("end") == 0) return sf::Keyboard::End;
	if (keyName.compare("home") == 0) return sf::Keyboard::Home;
	if (keyName.compare("insert") == 0) return sf::Keyboard::Insert;
	if (keyName.compare("delete") == 0) return sf::Keyboard::Delete;
	if (keyName.compare("add") == 0) return sf::Keyboard::Add;
	if (keyName.compare("subtract") == 0) return sf::Keyboard::Subtract;
	if (keyName.compare("multiply") == 0) return sf::Keyboard::Multiply;
	if (keyName.compare("divide") == 0) return sf::Keyboard::Divide;
	if (keyName.compare("left") == 0) return sf::Keyboard::Left;
	if (keyName.compare("right") == 0) return sf::Keyboard::Right;
	if (keyName.compare("up") == 0) return sf::Keyboard::Up;
	if (keyName.compare("down") == 0) return sf::Keyboard::Down;
	if (keyName.compare("numpad0") == 0) return sf::Keyboard::Numpad0;
	if (keyName.compare("numpad1") == 0) return sf::Keyboard::Numpad1;
	if (keyName.compare("numpad2") == 0) return sf::Keyboard::Numpad2;
	if (keyName.compare("numpad3") == 0) return sf::Keyboard::Numpad3;
	if (keyName.compare("numpad4") == 0) return sf::Keyboard::Numpad4;
	if (keyName.compare("numpad5") == 0) return sf::Keyboard::Numpad5;
	if (keyName.compare("numpad6") == 0) return sf::Keyboard::Numpad6;
	if (keyName.compare("numpad7") == 0) return sf::Keyboard::Numpad7;
	if (keyName.compare("numpad8") == 0) return sf::Keyboard::Numpad8;
	if (keyName.compare("numpad9") == 0) return sf::Keyboard::Numpad9;
	if (keyName.compare("f1") == 0) return sf::Keyboard::F1;
	if (keyName.compare("f2") == 0) return sf::Keyboard::F2;
	if (keyName.compare("f3") == 0) return sf::Keyboard::F3;
	if (keyName.compare("f4") == 0) return sf::Keyboard::F4;
	if (keyName.compare("f5") == 0) return sf::Keyboard::F5;
	if (keyName.compare("f6") == 0) return sf::Keyboard::F6;
	if (keyName.compare("f7") == 0) return sf::Keyboard::F7;
	if (keyName.compare("f8") == 0) return sf::Keyboard::F8;
	if (keyName.compare("f9") == 0) return sf::Keyboard::F9;
	if (keyName.compare("f10") == 0) return sf::Keyboard::F10;
	if (keyName.compare("f11") == 0) return sf::Keyboard::F11;
	if (keyName.compare("f12") == 0) return sf::Keyboard::F12;
	if (keyName.compare("f13") == 0) return sf::Keyboard::F13;
	if (keyName.compare("f14") == 0) return sf::Keyboard::F14;
	if (keyName.compare("f15") == 0) return sf::Keyboard::F15;
	if (keyName.compare("pause") == 0) return sf::Keyboard::Pause;
	if (keyName.compare("keycount") == 0) return sf::Keyboard::KeyCount;
	if (keyName.compare("dash") == 0) return sf::Keyboard::Hyphen;
	if (keyName.compare("return") == 0) return sf::Keyboard::Enter;

	return sf::Keyboard::Unknown;

}

