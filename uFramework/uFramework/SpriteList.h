#pragma once

#include "Sprite.h"

#include <unordered_map>

#include <SFML/Graphics.hpp>



namespace uFramework
{
	typedef std::unordered_map<std::string, Sprite*>::iterator SpriteIterator;

	class SpriteList
	{
	private:

		//Fields
		std::unordered_map<std::string, Sprite*> SpriteMap;

	public:

		//Metodos
		bool CreateSprite(std::string Index, int FPS);
		bool AddFrame(std::string Index, std::string Pathname);
		Sprite* GetSprite(std::string Index);


	};

}