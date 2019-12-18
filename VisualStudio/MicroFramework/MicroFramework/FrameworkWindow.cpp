#include "pch.h"
#include "FrameworkWindow.h"
#include "KeyboardMapper.h"
#include "Logger.h"
#include "SpritePool.h"
#include "ObjectPool.h"
#include "Object.h"
#include "Point.h"
#include "Sprite.h"
#include "Bounds.h"

#include <iostream>

FrameworkWindow::FrameworkWindow() : sf::Thread(&FrameworkWindow::privateShow, this)
{
	this->lastUsedIndex = 0;
	this->objects = std::make_shared<ObjectPool>();
	this->closed = false;
	this->backgroundColor = sf::Color(0, 0, 0, 255);

}

bool FrameworkWindow::isClosed()
{
	return this->closed;
}

void FrameworkWindow::initializeSize(int width, int height)
{
	if (width < 320 || height < 240)
	{
		width = 320;
		height = 240;
	}

	this->width = width;
	this->height = height;
}

void FrameworkWindow::initializeTitle(std::string title)
{
	this->title = title;
}

void FrameworkWindow::initializeScreenMode(bool fullscreen)
{
	this->fullscreen = fullscreen;
}

void FrameworkWindow::setBackgroundColor(int red, int green, int blue)
{
	if (red < 0) red = 0;
	if (red > 255) red = 255;
	if (green < 0) green = 0;
	if (green > 255) green = 255;
	if (blue < 0) blue = 0;
	if (blue > 255) blue = 255;

	this->resourcesMutex.lock();
	this->backgroundColor = sf::Color(red, green, blue);
	this->resourcesMutex.unlock();
}

void FrameworkWindow::privateShow()
{
	sf::Clock clock;

	sf::Uint32 style = sf::Style::Default;
	if (this->fullscreen)
	{
		style = sf::Style::Fullscreen;
	}

	sf::RenderWindow window(sf::VideoMode(this->width, this->height), this->title, style);

	while (window.isOpen())
	{
		this->resourcesMutex.lock();

		sf::Event Event;
		while (window.pollEvent(Event))
		{
			if (Event.type == sf::Event::Closed)
			{
				window.close();
				this->closed = true;
			}

		}

		window.clear(this->backgroundColor);

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
				sf::Vertex line[2];

				if (object->isUsingSpriteSize())
				{
					sfSprite->setOrigin(-object->x, -object->y);
				}
				else
				{
					auto nuevo = object->getBounds();
					auto actual = sfSprite->getLocalBounds();
					
					float sw = nuevo->width / actual.width;
					float sh = nuevo->height / actual.height;

					sfSprite->setScale(sw, sh);
					sfSprite->setOrigin(-object->x/sw, -object->y/sh);
				}

				window.draw(*(sfSprite));
			}
			it++;
		}

		this->resourcesMutex.unlock();
		window.display();
		window.setFramerateLimit(60);
	}
}

bool FrameworkWindow::createSprite(std::string spriteIndex, int fps)
{
	this->resourcesMutex.lock();
	auto sprite = std::make_shared<Sprite>(spriteIndex, fps);
	bool returnValue = SpritePool::add(spriteIndex, sprite);
	this->resourcesMutex.unlock();
	return returnValue;
}

bool FrameworkWindow::addFrameToSprite(std::string spriteIndex, std::string pathname)
{
	this->resourcesMutex.lock();
	bool ReturnValue = SpritePool::addFrame(spriteIndex, pathname);
	this->resourcesMutex.unlock();

	return ReturnValue;
}

void FrameworkWindow::addObject(float x, float y, std::string spriteIndex)
{
	this->resourcesMutex.lock();
	this->objects->addObject(x, y, spriteIndex);
	this->resourcesMutex.unlock();
}

void FrameworkWindow::addObject(float x, float y, float width, float height, std::string spriteIndex)
{
	this->resourcesMutex.lock();
	this->objects->addObject(x, y, width, height, spriteIndex);
	this->resourcesMutex.unlock();
}

bool FrameworkWindow::addIndexedObject(std::string ObjectIndex, float x, float y, std::string spriteIndex)
{
	this->resourcesMutex.lock();
	bool returnValue = this->objects->addIndexedObject(ObjectIndex, x, y, spriteIndex);
	this->resourcesMutex.unlock();

	return returnValue;
}

bool FrameworkWindow::addIndexedObject(std::string ObjectIndex, float x, float y, float width, float height, std::string spriteIndex)
{
	this->resourcesMutex.lock();
	bool returnValue = this->objects->addIndexedObject(ObjectIndex, x, y, width, height, spriteIndex);
	this->resourcesMutex.unlock();

	return returnValue;
}

void FrameworkWindow::addTaggedObject(std::string ObjectTag, float x, float y, std::string spriteIndex)
{
	this->lastUsedIndex++;
	this->resourcesMutex.lock();
	this->objects->addTaggedObject(ObjectTag, x, y, spriteIndex);
	this->resourcesMutex.unlock();
}

void FrameworkWindow::addTaggedObject(std::string ObjectTag, float x, float y, float width, float height, std::string spriteIndex)
{
	this->lastUsedIndex++;
	this->resourcesMutex.lock();
	this->objects->addTaggedObject(ObjectTag, x, y, width, height, spriteIndex);
	this->resourcesMutex.unlock();
}


std::shared_ptr<Point> FrameworkWindow::getObjectOrigin(std::string ObjectIndex)
{
	this->resourcesMutex.lock();
	auto returnValue = this->objects->getOriginByIndex(ObjectIndex);
	this->resourcesMutex.unlock();
	return returnValue;
}

bool FrameworkWindow::setIndexedObjectTag(std::string index, std::string tag)
{
	this->resourcesMutex.lock();
	bool returnValue = this->objects->setIndexedObjectTag(index, tag);
	this->resourcesMutex.unlock();
	return returnValue;

}

bool FrameworkWindow::setIndexedObjectOrigin(std::string ObjectIndex, float x, float y)
{
	this->resourcesMutex.lock();
	bool returnValue = this->objects->setOriginByIndex(ObjectIndex, x, y);
	this->resourcesMutex.unlock();
	return returnValue;
}

bool FrameworkWindow::moveIndexedObjectOrigin(std::string ObjectIndex, float dx, float dy)
{
	this->resourcesMutex.lock();
	bool returnValue = this->objects->moveOriginByIndex(ObjectIndex, dx, dy);
	this->resourcesMutex.unlock();
	return returnValue;
}

bool FrameworkWindow::setIndexedObjectSize(std::string ObjectIndex, float width, float height)
{
	this->resourcesMutex.lock();
	bool returnValue = this->objects->setSizeByIndex(ObjectIndex, width, height);
	this->resourcesMutex.unlock();
	return returnValue;
}

bool FrameworkWindow::setIndexedObjectSprite(std::string ObjectIndex, std::string spriteIndex)
{
	this->resourcesMutex.lock();
	bool returnValue = this->objects->setSpriteByIndex(ObjectIndex, spriteIndex);
	this->resourcesMutex.unlock();
	return returnValue;
}

void FrameworkWindow::moveTaggedObjectOrigin(std::string ObjectIndex, float dx, float dy)
{
	this->resourcesMutex.lock();
	this->objects->moveOriginByTag(ObjectIndex, dx, dy);
	this->resourcesMutex.unlock();
}

bool FrameworkWindow::setTaggedObjectSprite(std::string ObjectIndex, std::string spriteIndex)
{
	this->resourcesMutex.lock();
	bool returnValue = this->objects->setSpriteByTag(ObjectIndex, spriteIndex);
	this->resourcesMutex.unlock();
	return returnValue;
}

void FrameworkWindow::setTaggedObjectSize(std::string ObjectIndex, float width, float height)
{
	this->resourcesMutex.lock();
	this->objects->setSizeByTag(ObjectIndex, width, height);
	this->resourcesMutex.unlock();
}

void FrameworkWindow::setObjectHorizontalDirection(std::string ObjectIndex, Direction::Horizontal hDirection)
{
	auto object = this->objects->get(ObjectIndex);
	if (object == nullptr)
	{
		return;
	}
	object->setHorizontalDirection(hDirection);
}

void FrameworkWindow::setObjectVerticalDirection(std::string ObjectIndex, Direction::Vertical vDirection)
{
	auto object = this->objects->get(ObjectIndex);
	if (object == nullptr)
	{
		return;
	}
	object->setVerticalDirection(vDirection);
}

bool FrameworkWindow::isFree(float x, float y)
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

bool FrameworkWindow::preObjectCollidesObject(std::string index1, float dx, float dy, std::string index2)
{
	auto object1 = this->objects->get(index1);
	auto object2 = this->objects->get(index2);

	if (object1 == nullptr || object2 == nullptr)
	{
		return false;
	}
	return object1->intersectsDelta(object2, dx, dy);
}

bool FrameworkWindow::preObjectCollidesTag(std::string index, float dx, float dy, std::string tag)
{
	auto object = this->objects->get(index);
	if (object == nullptr)
	{
		return false;
	}
	auto taggedObjects = this->objects->getTagged(tag);
	for (auto tagged : taggedObjects)
	{
		if (object->intersectsDelta(tagged, dx, dy))
		{
			return true;
		}
	}
	return false;
}

bool FrameworkWindow::postObjectCollidesObject(std::string index1, std::string index2)
{
	this->resourcesMutex.lock();
	auto object1 = this->objects->get(index1);
	auto object2 = this->objects->get(index2);

	if (object1 == nullptr || object2 == nullptr)
	{
		return false;
	}
	bool returnValue = object1->intersects(object2);
	this->resourcesMutex.unlock();
	return returnValue;

}

bool FrameworkWindow::postObjectCollidesTag(std::string index, std::string tag)
{
	auto object = this->objects->get(index);
	if (object == nullptr)
	{
		return false;
	}
	
	auto taggedObjects = this->objects->getTagged(tag);
	for (auto tagged : taggedObjects)
	{
		if (object->intersects(tagged))
		{
			return true;
		}
	}
	return false;
}

bool FrameworkWindow::objectDeltaCollidesTag(std::string index, std::string tag, float dx, float dy)
{
	auto object = this->objects->get(index);
	auto taggedObjects = this->objects->getTagged(tag);
	for (auto tagged : taggedObjects)
	{
		if (object->intersectsDelta(tagged, dx, dy))
		{
			return true;
		}
	}
	return false;
}


bool FrameworkWindow::isGamepadConnected(int id)
{

	return (sf::Joystick::isConnected(id));
}

bool FrameworkWindow::isGamepadButtonPressed(int GamepadId, int ButtonId)
{
	return  (sf::Joystick::isButtonPressed(GamepadId, ButtonId));
}

float FrameworkWindow::getGamepadAxisValue(int GamepadId, int AxisId)
{
	if (AxisId == 0)
		return sf::Joystick::getAxisPosition(GamepadId, sf::Joystick::X);
	if (AxisId == 1)
		return sf::Joystick::getAxisPosition(GamepadId, sf::Joystick::Y);

	return 0;
}

//Keyboard 
bool FrameworkWindow::isKeyPressed(std::string KeyName)
{
	sf::Keyboard::Key Key = KeyboardMapper::get(KeyName);
	return sf::Keyboard::isKeyPressed(Key);
}

//Log
void FrameworkWindow::printLog()
{
	this->objects->printLog();
}

