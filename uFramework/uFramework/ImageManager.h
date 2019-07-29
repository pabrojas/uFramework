#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <unordered_map>

namespace uFramework
{
	class ImageManager
	{
	private:
		static std::unordered_map<std::string, sf::Sprite*> FILE_MAP;

	public:
		static sf::Sprite* load(std::string pathname);
		static sf::Sprite* get(std::string pathname);

	};

}