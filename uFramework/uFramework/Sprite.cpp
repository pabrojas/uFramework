#include "Sprite.h"
#include "ImageManager.h"
#include "Object.h"
#include "Logger.h"

#include <iostream>

using namespace uFramework;

//Class constructor
uFramework::Sprite::Sprite(std::string index, int fps)
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
		sf::Sprite* cloned = new sf::Sprite(*(sprite->sprites.at(i)));
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
bool Sprite::addFrame(std::string Pathname)
{
	sf::Sprite* sprite = ImageManager::load(Pathname);
	if (sprite == nullptr)
	{
		return false;
	}

	this->sprites.push_back(sprite);
	return true;
}

sf::Sprite* Sprite::getCurrent()
{
	if (this->sprites.empty())
	{
		return nullptr;
	}

	sf::Sprite* current = this->sprites.at(this->currentIndex);
	return current;
}

void Sprite::tick(sf::Time time)
{
	//std::cout << time.asMilliseconds() << std::endl;
	std::cout << this->lastTick.asMilliseconds() << std::endl;
	//this->lastTick = sf::milliseconds(time.asMilliseconds());
	this->lastTick = time;
	
	int size = this->sprites.size();
	this->currentIndex++;
	if (this->currentIndex >= size)
	{
		this->currentIndex = 0;
	}

	/*
	if (Time - this->lastTick > sf::milliseconds(1000 / fps))
	{
		std::cout << Time.asMilliseconds() << " : " << this->lastTick.asMilliseconds() << " : " << sf::milliseconds(1000 / fps).asMilliseconds() << std::endl;
		this->lastTick = sf::milliseconds( Time.asMilliseconds() );

		std::cout << "\t" << this->lastTick.asMilliseconds() << std::endl;
		int size = this->sprites.size();
		if (size > 0)
		{
			this->currentIndex++;
			if (this->currentIndex >= size)
			{
				this->currentIndex = 0;
				std::cout << "Zero" << std::endl;
			}
		}
		//Logger::log( this->index + " :: " + std::to_string(size) + " :: " + std::to_string(this->currentIndex));
	}
	else
	{
		std::cout << "nope" << std::endl;
	}
	*/
}
