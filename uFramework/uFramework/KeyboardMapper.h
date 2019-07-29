#pragma once

#include <SFML/Graphics.hpp>

namespace uFramework
{
	class KeyboardMapper
	{
	public:
		static sf::Keyboard::Key get(std::string keyName);
	};
}

