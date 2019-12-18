#include "pch.h"
#include "Object.h"
#include "Bounds.h"
#include "SpritePool.h"
#include "Sprite.h"
#include "Point.h"
#include "Logger.h"

const std::string Object::SPRITE_NO_SETTED = "SpriteIndexNotSetted::GI7d20fA8Gzn0a6cJHVM";

Object::Object(float x, float y) : Object(x, y, Object::SPRITE_NO_SETTED)
{
}

Object::Object(float x, float y, std::string spriteIndex)
{
	this->x = x;
	this->y = y;
	this->width = 0;
	this->height = 0;
	this->usingSpriteSize = true;
	this->hDirection = Direction::Horizontal::RIGHT;
	this->vDirection = Direction::Vertical::UP;
	this->spriteIndex = spriteIndex;
}

Object::Object(float x, float y, float w, float h) : Object(x, y, w, h, Object::SPRITE_NO_SETTED)
{
}

Object::Object(float x, float y, float w, float h, std::string spriteIndex)
{
	this->x = x;
	this->y = y;
	this->width = w;
	this->height = h;
	this->usingSpriteSize = false;
	this->hDirection = Direction::Horizontal::RIGHT;
	this->vDirection = Direction::Vertical::UP;
	this->spriteIndex = spriteIndex;
}

bool Object::setSprite(std::string spriteIndex)
{
	auto sprite = SpritePool::get(spriteIndex);
	if (sprite == nullptr)
	{
		this->spriteIndex = Object::SPRITE_NO_SETTED;
		this->sprite = nullptr;
		return false;
	}

	this->spriteIndex = spriteIndex;
	this->sprite = sprite;
	return true;
}

std::shared_ptr<Sprite> Object::getSprite()
{
	return this->sprite;
}

void Object::setHorizontalDirection(Direction::Horizontal direction)
{
	this->hDirection = direction;
}

void Object::setVerticalDirection(Direction::Vertical direction)
{
	this->vDirection = direction;
}

Direction::Horizontal Object::getHorizontalDirection()
{
	return this->hDirection;
}

Direction::Vertical Object::getVerticalDirection()
{
	return this->vDirection;
}

void Object::setSize(float width, float height)
{
	this->usingSpriteSize = false;
	this->width;
	this->height;
}

bool Object::isUsingSpriteSize()
{
	return this->usingSpriteSize;
}

void Object::setUsingSpriteSize(bool state)
{
	this->usingSpriteSize = state;
}

std::shared_ptr<Bounds> Object::getBounds()
{
	float x = this->x;
	float y = this->y;
	float width = this->width;
	this->height = this->height;

	if (this->usingSpriteSize)
	{
		if (this->sprite == nullptr)
		{
			return nullptr;
		}
		std::shared_ptr<sf::Sprite> sprite = this->sprite->getCurrent();
		width = sprite->getGlobalBounds().width;
		height = sprite->getGlobalBounds().height;
	}
	return std::make_shared<Bounds>(x, y, width, height);
}

bool Object::intersects(std::shared_ptr<Object> other)
{
	std::shared_ptr<Bounds> r1 = this->getBounds();
	std::shared_ptr<Bounds> r2 = other->getBounds();
	return r1->intersects(r2);
}

bool Object::intersectsDelta(std::shared_ptr<Object> other, float dx, float dy)
{
	std::shared_ptr<Bounds> r1 = this->getBounds();
	r1->x += dx;
	r1->y  += dy;

	std::shared_ptr<Bounds> r2 = other->getBounds();
	
	return r1->intersects(r2);

}

bool Object::intersects(std::shared_ptr<Bounds> other)
{
	std::shared_ptr<Bounds> bounds = this->getBounds();
	bool returnValue = bounds->intersects(other);
	return returnValue;
}

bool Object::contains(std::shared_ptr<Point> point)
{
	auto bounds = this->getBounds();
	bool returnValue = bounds->contains(point);
	return returnValue;
}

bool Object::contains(float x, float y)
{
	auto bounds = this->getBounds();
	bool returnValue = bounds->contains(x, y);
	return returnValue;
}

void Object::print()
{
	Logger::printObject(this->x, this->y, this->width, this->height, this->usingSpriteSize, this->spriteIndex);
}

