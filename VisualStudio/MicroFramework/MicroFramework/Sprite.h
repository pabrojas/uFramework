#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>


class Sprite
{

private:
	//Fields
	sf::Time lastTick;
	size_t currentIndex;
	int fps;

	std::vector<std::shared_ptr<sf::Sprite>> sprites;

public:

	std::string index;

	//Class constructors
	Sprite(std::string index, int fps);
	Sprite(std::shared_ptr<Sprite> sprite);

	//Methods
	void setFps(int fps);
	bool addFrame(std::string pathname);
	std::shared_ptr<sf::Sprite> getCurrent();
	void tick(sf::Time time);

};

