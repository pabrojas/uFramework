#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

namespace uFramework
{
	class Sprite
	{

	private:
		//Fields
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


	};
}

