#include "Sprite.h"
#include "Logger.h"

//Class constructor
uFramework::Sprite::Sprite(int FPS)
{
	this->FPS = FPS;
	this->CurrentIndex = 0;
	this->LastTick = sf::seconds(0.0f);
}


//Load a file
sf::Sprite* uFramework::Sprite::Load(std::string Pathname)
{
	sf::Image* image = new sf::Image();
	if (!(image->loadFromFile(Pathname)))
	{
		Logger::FileNotFound(Pathname);
		return nullptr;
	}

	sf::Texture* texture = new sf::Texture();
	texture->loadFromImage(*image);

	sf::Sprite* sprite = new sf::Sprite();
	sprite->setTexture(*texture);

	return sprite;
	
}

//Add a file to this sprite
bool uFramework::Sprite::AddFrame(std::string Pathname)
{
	sf::Sprite* sprite = this->Load(Pathname);
	if( sprite == nullptr )
	{
		return false;
	}

	this->Sprites.push_back(sprite);
	return true;
}

sf::Sprite* uFramework::Sprite::GetCurrent()
{
	if (this->Sprites.empty())
	{
		return nullptr;
	}

	return this->Sprites.at(this->CurrentIndex);
}

void uFramework::Sprite::Tick(sf::Time Time)
{
	if (Time - this->LastTick > sf::milliseconds(1000/FPS))
	{
		this->LastTick = Time;
		int Size = this->Sprites.size();
		if (Size > 0)
		{
			this->CurrentIndex = (this->CurrentIndex + 1) % Size;
		}
	}
}
