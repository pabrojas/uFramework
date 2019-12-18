#pragma once

#include <SFML/Graphics.hpp>


class KeyboardMapper
{
public:
	static sf::Keyboard::Key get(std::string keyName);
};


