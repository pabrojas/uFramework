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
	Sprite* sprite = SpritePool::get(spriteIndex);
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

uFramework::Sprite* Object::getSprite()
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

uFramework::Bounds* Object::getBounds()
{
	if (this->usingSpriteSize)
	{
		return nullptr;
	}
	return new Bounds(this->x, this->y, this->width, this->height);
}

bool Object::intersects(Bounds* other)
{
	Bounds* bounds = this->getBounds();
	bool returnValue = bounds->intersects(other);
	delete bounds;
	return returnValue;
}

bool Object::contains(Point* point)
{
	Bounds* bounds = this->getBounds();
	bool returnValue = bounds->contains(point);
	delete bounds;
	return returnValue;
}

bool Object::contains(float x, float y)
{
	Bounds* bounds = this->getBounds();
	bool returnValue = bounds->contains(x, y);
	delete bounds;
	return returnValue;
}
