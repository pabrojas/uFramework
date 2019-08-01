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
	this->objects = std::make_shared<ObjectPool>();
}

void EngineWindow::privateShow()
{
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "uFramework");

	while (window.isOpen())
	{
		std::cout << clock.getElapsedTime().asMilliseconds() << " :: ";


		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		this->resourcesMutex.lock();
		

		auto it = this->objects->begin();
		auto end = this->objects->end();

		while (it != end)
		{
			auto object = it->second;
			auto sprite = object->getSprite();

			sprite->tick(clock.getElapsedTime());
			auto sfSprite = sprite->getCurrent();
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
	auto sprite = std::make_shared<Sprite>(spriteIndex, fps);
	bool returnValue = SpritePool::add(spriteIndex, sprite);
	this->resourcesMutex.unlock();
	return returnValue;
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
	bool returnValue = this->objects->addIndexedObject(ObjectIndex, x, y, spriteIndex);
	this->resourcesMutex.unlock();

	return returnValue;
}

bool EngineWindow::addTaggedObject(std::string ObjectTag, float x, float y, std::string spriteIndex)
{
	this->lastUsedIndex++;
	this->resourcesMutex.lock();
	bool returnValue = this->objects->addIndexedObject(ObjectTag + std::to_string(this->lastUsedIndex), x, y, spriteIndex);
	this->resourcesMutex.unlock();

	return returnValue;
}

std::shared_ptr<Point> EngineWindow::getObjectOrigin(std::string ObjectIndex)
{
	this->resourcesMutex.lock();
	auto returnValue = this->objects->getOrigin(ObjectIndex);
	this->resourcesMutex.unlock();
	return returnValue;
}

bool EngineWindow::setObjectOrigin(std::string ObjectIndex, float x, float y)
{
	this->resourcesMutex.lock();
	bool returnValue = this->objects->setOrigin(ObjectIndex, x, y);
	this->resourcesMutex.unlock();
	return returnValue;
}

bool EngineWindow::setObjectSprite(std::string ObjectIndex, std::string spriteIndex)
{
	auto object = this->objects->get(ObjectIndex);
	if (object == nullptr)
	{
		return false;
	}
	if (object->getSprite()->index.compare(spriteIndex) == 0)
	{
		return true;
	}
	return object->setSprite(spriteIndex);
}

void EngineWindow::setObjectHorizontalDirection(std::string ObjectIndex, Enums::HorizontalDirection hDirection)
{
	auto object = this->objects->get(ObjectIndex);
	if (object == nullptr)
	{
		return;
	}

	object->setHorizontalDirection(hDirection);
}

void EngineWindow::setObjectVerticalDirection(std::string ObjectIndex, Enums::VerticalDirection vDirection)
{
	auto object = this->objects->get(ObjectIndex);
	if (object == nullptr)
	{
		return;
	}

	object->setVerticalDirection(vDirection);
}

bool EngineWindow::isFree(float x, float y)
{
	auto it = this->objects->begin();
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
