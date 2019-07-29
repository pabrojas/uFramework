#include "EngineWindow.h"
#include "KeyboardMapper.h"
#include "Logger.h"
#include "SpritePool.h"
#include "ObjectPool.h"
#include "Object.h"
#include "Point.h"
#include "Sprite.h"


#include <iostream>

using namespace uFramework;

EngineWindow::EngineWindow() : sf::Thread(&EngineWindow::privateShow, this)
{
	this->lastUsedIndex = 0;
	this->objects = new ObjectPool();
}

void EngineWindow::privateShow()
{
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "uFramework");

	while (window.isOpen())
	{
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		this->resourcesMutex.lock();
		
		std::unordered_map<std::string, Object*>::iterator it = this->objects->begin();
		std::unordered_map<std::string, Object*>::iterator end = this->objects->end();

		while (it != end)
		{
			Object* object = it->second;
			Sprite* sprite = object->getSprite();

			sprite->tick(clock.getElapsedTime());
			sf::Sprite* sfSprite = sprite->getCurrent();
			if (sfSprite != nullptr)
			{
				sfSprite->setOrigin(object->x, object->y);
				window.draw(*(sfSprite));
			}
			it++;
		}

		this->resourcesMutex.unlock();
		window.display();
	}
}

bool EngineWindow::createSprite(std::string spriteIndex, int fps)
{
	this->resourcesMutex.lock();
	Sprite* sprite = new Sprite(fps);
	bool ReturnValue = SpritePool::add(spriteIndex, sprite);
	this->resourcesMutex.unlock();
	return ReturnValue;
}

bool EngineWindow::addFrameToSprite(std::string spriteIndex, std::string pathname)
{
	this->resourcesMutex.lock();
	bool ReturnValue = SpritePool::addFrame(spriteIndex, pathname);
	this->resourcesMutex.unlock();

	return ReturnValue;
}

void EngineWindow::addObject(float x, float y, std::string spriteIndex)
{
	this->resourcesMutex.lock();
	this->objects->addObject(x, y, spriteIndex);
	this->resourcesMutex.unlock();
}

bool EngineWindow::addIndexedObject(std::string ObjectIndex, float x, float y, std::string spriteIndex)
{
	this->resourcesMutex.lock();
	bool ReturnValue = this->objects->addIndexedObject(ObjectIndex, x, y, spriteIndex);
	this->resourcesMutex.unlock();

	return ReturnValue;
}

bool EngineWindow::addTaggedObject(std::string ObjectTag, float x, float y, std::string spriteIndex)
{
	this->lastUsedIndex++;
	this->resourcesMutex.lock();
	bool ReturnValue = this->objects->addIndexedObject(ObjectTag + std::to_string(this->lastUsedIndex), x, y, spriteIndex);
	this->resourcesMutex.unlock();

	return ReturnValue;
}


uFramework::Point* EngineWindow::getObjectOrigin(std::string ObjectIndex)
{
	this->resourcesMutex.lock();
	Point* ReturnValue = this->objects->getOrigin(ObjectIndex);
	this->resourcesMutex.unlock();

	return ReturnValue;
}

bool EngineWindow::setObjectOrigin(std::string ObjectIndex, float x, float y)
{
	this->resourcesMutex.lock();
	bool ReturnValue = this->objects->setOrigin(ObjectIndex, x, y);
	this->resourcesMutex.unlock();

	return ReturnValue;
}

bool EngineWindow::setObjectSprite(std::string ObjectIndex, std::string spriteIndex)
{
	Object* Object = this->objects->get(ObjectIndex);
	if (Object == nullptr)
	{
		return false;
	}

	return Object->setSprite(spriteIndex);
}

void EngineWindow::setObjectHorizontalDirection(std::string ObjectIndex, Enums::HorizontalDirection hDirection)
{
	Object* Object = this->objects->get(ObjectIndex);
	if (Object == nullptr)
	{
		return;
	}

	Object->setHorizontalDirection(hDirection);
}

void EngineWindow::setObjectVerticalDirection(std::string ObjectIndex, Enums::VerticalDirection vDirection)
{
	Object* object = this->objects->get(ObjectIndex);
	if (object == nullptr)
	{
		return;
	}

	object->setVerticalDirection(vDirection);
}

bool EngineWindow::isFree(float x, float y)
{
	std::unordered_map<std::string, Object*>::iterator it = this->objects->begin();
	while (it != this->objects->end())
	{
		if (it->second->contains(x, y))
		{
			return false;
		}

		it++;
	}
	return true;
}


bool EngineWindow::isGamepadConnected(int id)
{

	return (sf::Joystick::isConnected(id));
}

bool EngineWindow::isGamepadButtonPressed(int GamepadId, int ButtonId)
{
	return  (sf::Joystick::isButtonPressed(GamepadId, ButtonId));
}

float EngineWindow::getGamepadAxisValue(int GamepadId, int AxisId)
{
	if (AxisId == 0)
		return sf::Joystick::getAxisPosition(GamepadId, sf::Joystick::X);
	if (AxisId == 1)
		return sf::Joystick::getAxisPosition(GamepadId, sf::Joystick::Y);

	return 0;
}

//Keyboard 
bool EngineWindow::isKeyPressed(std::string KeyName)
{
	sf::Keyboard::Key Key = KeyboardMapper::get(KeyName);
	return sf::Keyboard::isKeyPressed(Key);
}
