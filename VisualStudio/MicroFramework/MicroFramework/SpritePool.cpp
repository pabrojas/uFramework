#include "pch.h"
#include "SpritePool.h"
#include "Logger.h"
#include "Sprite.h"

std::unordered_map<std::string, std::shared_ptr<Sprite>> SpritePool::INDEXED_SPRITES = std::unordered_map<std::string, std::shared_ptr<Sprite>>();

bool SpritePool::add(std::string index, std::shared_ptr<Sprite> sprite)
{
	auto it = SpritePool::INDEXED_SPRITES.find(index);
	if (it != SpritePool::INDEXED_SPRITES.end())
	{
		Logger::indexAlreadyExists("SpritePool", index);
		return false;
	}
	SpritePool::INDEXED_SPRITES[index] = sprite;
	return true;
}

std::shared_ptr <Sprite> SpritePool::get(std::string index)
{
	auto it = SpritePool::INDEXED_SPRITES.find(index);
	if (it == SpritePool::INDEXED_SPRITES.end())
	{
		Logger::indexNotFound("SpritePool", index);
		return nullptr;
	}

	return std::make_shared<Sprite>(*(it->second));
}

bool SpritePool::addFrame(std::string index, std::string pathname)
{
	auto it = SpritePool::INDEXED_SPRITES.find(index);
	if (it == SpritePool::INDEXED_SPRITES.end())
	{
		Logger::indexNotFound("SpritePool", index);
		return false;
	}

	return it->second->addFrame(pathname);
}
