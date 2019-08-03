#include "Object.h"
#include "Bounds.h"
#include "SpritePool.h"
#include "Sprite.h"
#include "Point.h"

using namespace uFramework;

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
	this->hDirection = Enums::HorizontalDirection::RIGHT;
	this->vDirection = Enums::VerticalDirection::UP;
	this->spriteIndex = spriteIndex;
}

Object::Object(float x, float y, float w, float h) : Object(x, y, w, h, Object::SPRITE_NO_SETTED)
{
}

Object::Object(float x, float y, float w, float h, std::string spriteIndex)
{
	this->x = x;
	this->y = y;
	this->width = 0;
	this->height = 0;
	this->usingSpriteSize = false;
	this->hDirection = Enums::HorizontalDirection::RIGHT;
	this->vDirection = Enums::VerticalDirection::UP;
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

void Object::setHorizontalDirection(Enums::HorizontalDirection direction)
{
	this->hDirection = direction;
}

void Object::setVerticalDirection(Enums::VerticalDirection direction)
{
	this->vDirection = direction;
}

Enums::HorizontalDirection Object::getHorizontalDirection()
{
	return this->hDirection;
}

Enums::VerticalDirection Object::getVerticalDirection()
{
	return this->vDirection;
}

bool Object::isUsingSpriteSize()
{
	return this->usingSpriteSize;
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
