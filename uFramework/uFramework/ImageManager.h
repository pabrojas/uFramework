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
		class Data
		{
		public:
			sf::Sprite* sprite;
			sf::Image* image;
			sf::Texture* texture;
		};
		static std::unordered_map<std::string, std::shared_ptr<Data>> FILE_MAP;

	public:
		static std::shared_ptr<sf::Sprite> load(std::string pathname);
		static std::shared_ptr<sf::Sprite> get(std::string pathname);

	};

	

}