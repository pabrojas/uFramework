#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <memory>

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

		std::string index;

		//Class constructors
		Sprite(std::string index, int fps);
		Sprite(std::shared_ptr<Sprite> sprite);

		//Methods
		void setFps(int fps);
		bool addFrame(std::string pathname);
		sf::Sprite* getCurrent();
		void tick(sf::Time time);

	};
}
