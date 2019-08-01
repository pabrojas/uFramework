#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <unordered_map>
#include <memory>

namespace uFramework
{
	class ImageManager
	{
	private:
		static std::unordered_map<std::string, sf::Sprite*> FILE_MAP;

	public:
		static sf::Sprite* load(std::string pathname);
		static std::shared_ptr<sf::Sprite> get(std::string pathname);

	};

}