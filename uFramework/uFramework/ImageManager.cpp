#include "ImageManager.h"
#include "Logger.h"

using namespace uFramework;

std::unordered_map<std::string, sf::Sprite*> ImageManager::FILE_MAP = std::unordered_map<std::string, sf::Sprite*>();

sf::Sprite* ImageManager::load(std::string pathname)
{
	std::unordered_map<std::string, sf::Sprite*>::iterator it = ImageManager::FILE_MAP.find(pathname);
	if (it != ImageManager::FILE_MAP.end())
	{
		return it->second;
	}

	sf::Image* image = new sf::Image();
	if (!(image->loadFromFile(pathname)))
	{
		Logger::fileNotFound(pathname);
		return nullptr;
	}

	sf::Texture* texture = new sf::Texture();
	texture->loadFromImage(*image);

	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*texture);

	ImageManager::FILE_MAP.emplace(pathname, sprite);
	return sprite;
}

sf::Sprite* ImageManager::get(std::string pathname)
{
	std::unordered_map<std::string, sf::Sprite*>::iterator it = ImageManager::FILE_MAP.find(pathname);
	if (it == ImageManager::FILE_MAP.end())
	{
		return nullptr;
	}

	sf::Sprite* storedSprite = it->second;
	sf::Sprite* clonedSprite = new sf::Sprite(*storedSprite);

	return clonedSprite;
}
