#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

namespace uFramework
{
	class Sprite
	{

	private:
		//Fields
		sf::Time lastTick;
		int currentIndex;
		int fps;
		std::vector<sf::Sprite*> sprites;

	public:

		//Class constructors
		Sprite(int fps);
		Sprite(Sprite* sprite);

		//Methods
		void setFps(int fps);
		bool addFrame(std::string pathname);
		sf::Sprite* getCurrent();
		void tick(sf::Time time);

	};
}
