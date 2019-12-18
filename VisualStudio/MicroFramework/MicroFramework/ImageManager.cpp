#include "pch.h"
#include "ImageManager.h"
#include "Logger.h"

std::unordered_map<std::string, std::shared_ptr<ImageManager::Data>> ImageManager::FILE_MAP = std::unordered_map<std::string, std::shared_ptr<ImageManager::Data>>();

std::shared_ptr<sf::Sprite> ImageManager::load(std::string pathname)
{
	auto it = ImageManager::FILE_MAP.find(pathname);
	if (it != ImageManager::FILE_MAP.end())
	{
		return std::make_shared<sf::Sprite>(*(it->second->sprite));
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


	std::shared_ptr<Data> data = std::make_shared<Data>();
	data->sprite = sprite;
	data->image = image;
	data->texture = texture;

	ImageManager::FILE_MAP[pathname] = data;

	return std::make_shared<sf::Sprite>(*sprite);
}

std::shared_ptr<sf::Sprite> ImageManager::get(std::string pathname)
{
	auto it = ImageManager::FILE_MAP.find(pathname);
	if (it == ImageManager::FILE_MAP.end())
	{
		return nullptr;
	}

	auto storedSprite = it->second->sprite;
	auto clonedSprite = std::make_shared<sf::Sprite>(*storedSprite);

	return clonedSprite;
}
