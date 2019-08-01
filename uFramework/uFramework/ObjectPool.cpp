#include "ObjectPool.h"
#include "SpritePool.h"
#include "Point.h"
#include "Object.h"

using namespace uFramework;

const std::string ObjectPool::UNDEFINED_INDEX = "UndefinedIndex::9iuB54rCchcvxq5OaLsA::";

ObjectPool::ObjectPool()
{
	this->undefinedIndexCounter = 0;
}

std::string ObjectPool::createUndefinedIndex()
{
	this->undefinedIndexCounter++;
	return ObjectPool::UNDEFINED_INDEX + std::to_string(this->undefinedIndexCounter);
}

std::unordered_map<std::string, std::shared_ptr<Object>>::iterator uFramework::ObjectPool::begin()
{
	return this->indexedObjects.begin();
}

std::unordered_map<std::string, std::shared_ptr<Object>>::iterator uFramework::ObjectPool::end()
{
	return this->indexedObjects.end();
}

void ObjectPool::addObject(float x, float y, std::string spriteIndex)
{
	std::shared_ptr<Object> object = std::make_shared<Object>(x, y);
	object->setSprite(spriteIndex);
	std::string index = this->createUndefinedIndex();
	this->indexedObjects[index] = object;
}

void ObjectPool::addObject(float x, float y, float w, float h, std::string spriteIndex)
{
	std::shared_ptr<Object> object = std::make_shared<Object>(x, y, w, h);
	object->setSprite(spriteIndex);
	std::string index = this->createUndefinedIndex();
	this->indexedObjects[index] = object;
}

bool ObjectPool::addIndexedObject(std::string index, float x, float y, std::string spriteIndex)
{
	auto it = this->indexedObjects.find(index);
	if (it != this->end())
	{
		return false;
	}

	std::shared_ptr<Object> object = std::make_shared<Object>(x, y);
	object->setSprite(spriteIndex);
	this->indexedObjects[index] = object;

	return true;
}

bool ObjectPool::addIndexedObject(std::string index, float x, float y, float w, float h, std::string spriteIndex)
{
	auto it = this->indexedObjects.find(index);
	if (it != this->indexedObjects.end())
	{
		return false;
	}

	std::shared_ptr<Object> object = std::make_shared<Object>(x, y, w, h);
	object->setSprite(spriteIndex);
	this->indexedObjects[index] = object;

	return true;
}

void ObjectPool::addTaggedObject(std::string tag, float x, float y, std::string spriteIndex)
{
	std::shared_ptr<Object> object = std::make_shared<Object>(x, y);
	object->setSprite(spriteIndex);
	std::string index = this->createUndefinedIndex();
	this->indexedObjects[index] = object;

	auto it = this->taggedObjects.find(tag);
	if (it != this->taggedObjects.end())
	{
		it->second.push_back(object);
	}
	else
	{
		std::vector<std::shared_ptr<Object>> objects;
		objects.push_back(object);
		this->taggedObjects[tag] = objects;
	}
}

void ObjectPool::addTaggedObject(std::string tag, float x, float y, float w, float h, std::string spriteIndex)
{
	std::shared_ptr<Object> object = std::make_shared<Object>(x, y, w, h);
	object->setSprite(spriteIndex);
	std::string index = this->createUndefinedIndex();
	this->indexedObjects[index] = object;

	auto it = this->taggedObjects.find(tag);
	if (it != this->taggedObjects.end())
	{
		it->second.push_back(object);
	}
	else
	{
		std::vector<std::shared_ptr<Object>> objects;
		objects.push_back(object);
		this->taggedObjects[tag] = objects;
	}
}

bool ObjectPool::addIndexedTaggedObject(std::string index, std::string tag, float x, float y, std::string spriteIndex)
{
	auto itIndexes = this->indexedObjects.find(index);
	if (itIndexes != this->indexedObjects.end())
	{
		return false;
	}

	std::shared_ptr<Object> object = std::make_shared<Object>(x, y);
	object->setSprite(spriteIndex);
	this->indexedObjects[index] = object;

	auto itTags = this->taggedObjects.find(tag);
	if (itTags != this->taggedObjects.end())
	{
		itTags->second.push_back(object);
	}
	else
	{
		std::vector<std::shared_ptr<Object>> objects;
		objects.push_back(object);
		this->taggedObjects[tag] = objects;
	}

	return true;
}

bool ObjectPool::addIndexedTaggedObject(std::string index, std::string tag, float x, float y, float w, float h, std::string spriteIndex)
{
	auto itIndexes = this->indexedObjects.find(index);
	if (itIndexes != this->indexedObjects.end())
	{
		return false;
	}

	std::shared_ptr<Object> object = std::make_shared<Object>(x, y, w, h);
	object->setSprite(spriteIndex);
	this->indexedObjects[index] = object;

	auto itTags = this->taggedObjects.find(tag);
	if (itTags != this->taggedObjects.end())
	{
		itTags->second.push_back(object);
	}
	else
	{
		std::vector<std::shared_ptr<Object>> objects;
		objects.push_back(object);
		this->taggedObjects[tag] = objects;
	}

	return true;
}

std::shared_ptr<Point> ObjectPool::getOrigin(std::string index)
{
	auto it = this->indexedObjects.find(index);
	if (it == this->indexedObjects.end())
	{
		return nullptr;
	}

	return std::make_shared<Point>(it->second->x, it->second->y);
}

bool ObjectPool::setOrigin(std::string index, float x, float y)
{
	auto it = this->indexedObjects.find(index);
	if (it == this->indexedObjects.end())
	{
		return false;
	}

	it->second->x = x;
	it->second->y = y;
	return true;
}

bool ObjectPool::moveOrigin(std::string index, float dx, float dy)
{
	auto it = this->indexedObjects.find(index);
	if (it == this->indexedObjects.end())
	{
		return false;
	}

	it->second->x += dx;
	it->second->y += dy;
	return true;
}

std::shared_ptr<Object> ObjectPool::get(std::string index)
{
	auto it = this->indexedObjects.find(index);
	if (it == this->indexedObjects.end())
	{
		return nullptr;
	}

	return it->second;
}

