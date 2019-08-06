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
	this->closed = false;
}

bool EngineWindow::isClosed()
{
	return this->closed;
}

void EngineWindow::privateShow()
{
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(1024, 768), "uFramework");

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

		window.clear();

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
				//window.draw(*(sfSprite));

				
				sf::FloatRect rect = sfSprite->getGlobalBounds();
				
				/*Logger::log( std::to_string((int)object->x) + ", " +
								std::to_string((int)object->y) + " --- " +
								std::to_string((int)rect.left) + ", " + 
								std::to_string((int)rect.top) + ", " + 
								std::to_string((int)rect.width) + ", " + 
								std::to_string((int)rect.height));
								*/


				float epsilon = 2.0f;

				//sf::FloatRect r1(this->x + epsilon, this->y - epsilon, -this->width - epsilon, -this->height + epsilon);
				/*sf::RectangleShape rect_epsilon(sf::Vector2f(rect.width, rect.height + 2*epsilon));
				rect_epsilon.setOrigin(-rect.left, -rect.top + epsilon);
				rect_epsilon.setFillColor(sf::Color::Transparent);
				rect_epsilon.setOutlineThickness(1);
				rect_epsilon.setOutlineColor(sf::Color(0, 150, 100));
				window.draw(rect_epsilon);
				*/
				
				sf::RectangleShape rectangle(sf::Vector2f(rect.width, rect.height));
				rectangle.setOrigin(-rect.left, -rect.top);
				rectangle.setFillColor(sf::Color::Transparent);
				rectangle.setOutlineThickness(1);
				rectangle.setOutlineColor(sf::Color(250, 150, 100));
				window.draw(rectangle);


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

void EngineWindow::addTaggedObject(std::string ObjectTag, float x, float y, std::string spriteIndex)
{
	this->lastUsedIndex++;
	this->resourcesMutex.lock();
	this->objects->addTaggedObject(ObjectTag, x, y, spriteIndex);
	this->resourcesMutex.unlock();
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

bool EngineWindow::objectCollidesObject(std::string index1, std::string index2)
{
	auto object1 = this->objects->get(index1);
	auto object2 = this->objects->get(index2);

	if (object1 == nullptr || object2 == nullptr)
	{
		return false;
	}

	return object1->intersects(object2);
}

bool EngineWindow::objectCollidesTag(std::string index, std::string tag)
{
	auto object = this->objects->get(index);
	auto taggedObjects = this->objects->getTagged(tag);
	for (auto tagged : *taggedObjects)
	{
		if (object->intersects(tagged))
		{
			return true;
		}
	}
	return false;
}

bool EngineWindow::objectDeltaCollidesTag(std::string index, std::string tag, float dx, float dy)
{
	auto object = this->objects->get(index);
	auto taggedObjects = this->objects->getTagged(tag);
	for (auto tagged : *taggedObjects)
	{
		if (object->intersectsDelta(tagged, dx, dy))
		{
			return true;
		}
	}
	return false;
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
