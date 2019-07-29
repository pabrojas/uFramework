#include "Sprite.h"
#include "ImageManager.h"
#include "Object.h"
#include "Logger.h"

using namespace uFramework;

//Class constructor
uFramework::Sprite::Sprite(int fps)
{
	if (fps == 0)
	{
		fps = 1;
	}
	this->fps = fps;
	this->currentIndex = 0;
	this->lastTick = sf::seconds(0.0f);
}

uFramework::Sprite::Sprite(Sprite* sprite)
{
	this->fps = sprite->fps;
	this->currentIndex = sprite->currentIndex;
	this->lastTick = sprite->lastTick;

	int N = (int)(sprite->sprites.size());
	for (int i = 0; i < N; i++)
	{
		sf::Sprite* cloned = new sf::Sprite(*(sprite->sprites.at(i)));
		this->sprites.push_back(cloned);
	}
}

void uFramework::Sprite::setFps(int fps)
{
	if (fps == 0)
	{
		fps = 1;
	}
	this->fps = fps;
}

//Add a file to this sprite
bool uFramework::Sprite::addFrame(std::string Pathname)
{
	sf::Sprite* sprite = ImageManager::load(Pathname);
	if (sprite == nullptr)
	{
		return false;
	}

	this->sprites.push_back(sprite);
	return true;
}

sf::Sprite* uFramework::Sprite::getCurrent()
{
	if (this->sprites.empty())
	{
		return nullptr;
	}

	sf::Sprite* current = this->sprites.at(this->currentIndex);
	return current;
}

void uFramework::Sprite::tick(sf::Time Time)
{
	if (Time - this->lastTick > sf::milliseconds(1000 / fps))
	{
		this->lastTick = Time;
		int size = this->sprites.size();
		if (size > 0)
		{
			this->currentIndex = (this->currentIndex + 1) % size;
		}
	}
}
