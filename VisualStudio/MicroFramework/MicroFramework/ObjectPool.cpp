#include "pch.h"
#include "ObjectPool.h"
#include "SpritePool.h"
#include "Point.h"
#include "Object.h"
#include "Sprite.h"
#include "Logger.h"

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

std::unordered_map<std::string, std::shared_ptr<Object>>::iterator ObjectPool::begin()
{
	return this->indexedObjects.begin();
}

std::unordered_map<std::string, std::shared_ptr<Object>>::iterator ObjectPool::end()
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
		Logger::log("agregando");
		it->second.push_back(object);
	}
	else
	{
		Logger::log("creando");
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

std::shared_ptr<Point> ObjectPool::getOriginByIndex(std::string index)
{
	auto it = this->indexedObjects.find(index);
	if (it == this->indexedObjects.end())
	{
		return nullptr;
	}

	return std::make_shared<Point>(it->second->x, it->second->y);
}

bool ObjectPool::setOriginByIndex(std::string index, float x, float y)
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

bool ObjectPool::moveOriginByIndex(std::string index, float dx, float dy)
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

bool ObjectPool::setSizeByIndex(std::string index, float width, float height)
{
	auto it = this->indexedObjects.find(index);
	if (it == this->indexedObjects.end())
	{
		return false;
	}

	it->second->setSize(width, height);
	return true;
}

bool ObjectPool::setSpriteByIndex(std::string index, std::string sprite)
{
	auto object = this->get(index);
	if (object == nullptr)
	{
		return false;
	}
	if (object->getSprite()->index.compare(sprite) == 0)
	{
		return true;
	}
	return object->setSprite(sprite);
}

void ObjectPool::moveOriginByTag(std::string tag, float dx, float dy)
{
	auto it = this->taggedObjects.find(tag);
	if (it == this->taggedObjects.end())
	{
		return;
	}

	auto objects = it->second;
	for (auto i = objects.begin(); i != objects.end(); ++i)
	{
		(*i)->x += dx;
		(*i)->y += dy;
	}

}

bool ObjectPool::setSpriteByTag(std::string tag, std::string sprite)
{
	auto it = this->taggedObjects.find(tag);
	if (it == this->taggedObjects.end())
	{
		return true;
	}

	auto objects = it->second;
	for (auto i = objects.begin(); i != objects.end(); ++i)
	{
		if ((*i)->setSprite(sprite) == false)
		{
			return false;
		}
	}

	return true;
}

void ObjectPool::setSizeByTag(std::string tag, float width, float height)
{
	auto it = this->taggedObjects.find(tag);
	if (it == this->taggedObjects.end())
	{
		return;
	}

	auto objects = it->second;
	for (auto i = objects.begin(); i != objects.end(); ++i)
	{
		(*i)->setSize(width, height);
	}
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

std::vector<std::shared_ptr<Object>> ObjectPool::getTagged(std::string tag)
{
	std::shared_ptr<std::vector<std::shared_ptr<Object>>> objects = std::make_shared<std::vector<std::shared_ptr<Object>>>();
	auto it = this->taggedObjects.find(tag);
	if (it != this->taggedObjects.end())
	{
		return it->second;

		/*
		for (std::shared_ptr<Object> object : it->second)
		{
			objects->push_back(object);
		}
		*/
	}

	return std::vector<std::shared_ptr<Object>>();
}



/**
IMPORTANTE: FALTRA REMOVER EL TAG ANTERIOR. ESTO PUEDE CAUSAR COMPORTAMIENTO INESPERADO!!!!
*/
bool ObjectPool::setIndexedObjectTag(std::string index, std::string tag)
{
	auto indexed = this->get(index);
	if (indexed == nullptr)
	{
		return false;
	}

	auto itTags = this->taggedObjects.find(tag);
	if (itTags != this->taggedObjects.end())
	{
		itTags->second.push_back(indexed);
	}
	else
	{
		std::vector<std::shared_ptr<Object>> objects;
		objects.push_back(indexed);
		this->taggedObjects[tag] = objects;
	}
	return true;
}


void ObjectPool::printLog()
{
	Logger::log("----------------------Begin Log---------------------------");

	//std::unordered_map<std::string, std::shared_ptr<Object>> indexedObjects;
	Logger::log("Indexed Objects");
	for (auto key : this->indexedObjects)
	{
		Logger::logSL("\t");
		Logger::logSL(key.first);
		Logger::logSL(" : ");
		key.second->print();
	}

	Logger::log("Tagged Objects");
	for (auto key : this->taggedObjects)
	{
		Logger::log(key.first);
		for (auto value : key.second)
		{
			value->print();
		}
	}
	Logger::log("-----------------------End Log----------------------------");

}

