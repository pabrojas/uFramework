#include "pch.h"
#include "Sprite.h"
#include "ImageManager.h"
#include "Object.h"
#include "Logger.h"

//Class constructor
Sprite::Sprite(std::string index, int fps)
{
	if (fps == 0)
	{
		fps = 1;
	}
	this->index = index;
	this->fps = fps;
	this->currentIndex = 0;
	this->lastTick = sf::seconds(-10.0f);
}

Sprite::Sprite(std::shared_ptr<Sprite> sprite)
{
	this->fps = sprite->fps;
	this->currentIndex = sprite->currentIndex;
	this->lastTick = sprite->lastTick;

	int N = (int)(sprite->sprites.size());
	for (int i = 0; i < N; i++)
	{
		std::shared_ptr<sf::Sprite> cloned = std::make_shared<sf::Sprite>(*(sprite->sprites.at(i)));
		this->sprites.push_back(cloned);
	}
}

void Sprite::setFps(int fps)
{
	if (fps == 0)
	{
		fps = 1;
	}
	this->fps = fps;
}

//Add a file to this sprite
bool Sprite::addFrame(std::string pathname)
{
	std::shared_ptr<sf::Sprite> sprite = ImageManager::load(pathname);
	if (sprite == nullptr)
	{
		return false;
	}

	this->sprites.push_back(sprite);
	return true;
}

std::shared_ptr<sf::Sprite> Sprite::getCurrent()
{
	if (this->sprites.empty())
	{
		return nullptr;
	}

	std::shared_ptr<sf::Sprite> current = this->sprites.at(this->currentIndex);
	return current;
}

void Sprite::tick(sf::Time time)
{
	if (time - this->lastTick > sf::milliseconds(1000 / fps))
	{
		this->lastTick = time;
		size_t size = this->sprites.size();
		if (size > 0)
		{
			this->currentIndex = (this->currentIndex + 1) % size;
		}
	}

}

