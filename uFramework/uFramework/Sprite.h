#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

namespace uFramework
{
	class Sprite
	{

	private:
		//Fields
		sf::Time LastTick;
		int CurrentIndex;
		int FPS;
		std::vector<sf::Sprite*> Sprites;

		//Methods
		sf::Sprite* Load(std::string Pathname);

	public:

		//Class constructors
		Sprite(int FPS);

		//Methods
		bool AddFrame(std::string Pathname);
		sf::Sprite* GetCurrent();
		void Tick(sf::Time Time);

	};
}

