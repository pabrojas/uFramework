#include "SpritePool.h"
#include "Logger.h"
#include "Sprite.h"

using namespace uFramework;

//Iterators
//typedef std::unordered_map<std::string, Sprite*>::iterator SpriteIterator;

bool SpritePool::add(std::string index, Sprite* sprite)
{
	std::unordered_map<std::string, Sprite*>::iterator it = SpritePool::INDEXED_SPRITES.find(index);
	if (it != SpritePool::INDEXED_SPRITES.end())
	{
		Logger::indexAlreadyExists("SpritePool", index);
		return false;
	}

	SpritePool::INDEXED_SPRITES.emplace(index, sprite);
	return true;
}

uFramework::Sprite* SpritePool::get(std::string index)
{
	std::unordered_map<std::string, Sprite*>::iterator it = SpritePool::INDEXED_SPRITES.find(index);
	if (it == SpritePool::INDEXED_SPRITES.end())
	{
		Logger::indexNotFound("SpritePool", index);
		return nullptr;
	}

	return new Sprite(*(it->second));
}

bool SpritePool::addFrame(std::string index, std::string pathname)
{
	std::unordered_map<std::string, Sprite*>::iterator it = SpritePool::INDEXED_SPRITES.find(index);
	if (it == SpritePool::INDEXED_SPRITES.end())
	{
		Logger::indexNotFound("SpritePool", index);
		return false;
	}

	return it->second->addFrame(pathname);
}
