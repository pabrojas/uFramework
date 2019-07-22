#include "SpriteList.h"
#include "Sprite.h"

using namespace uFramework;

bool SpriteList::CreateSprite(std::string Index, int FPS)
{
	SpriteIterator Iterator = this->SpriteMap.find(Index);
	if (Iterator != this->SpriteMap.end())
	{
		return false;
	}

	Sprite* NewSprite = new Sprite(FPS);
	this->SpriteMap.emplace(Index, NewSprite);
}

bool SpriteList::AddFrame(std::string Index, std::string Pathname)
{
	SpriteIterator Iterator = this->SpriteMap.find(Index);
	if (Iterator == this->SpriteMap.end())
	{
		return false;
	}

	Sprite* StoredSprite = Iterator->second;
	return StoredSprite->AddFrame(Pathname);
}

Sprite* SpriteList::GetSprite(std::string Index)
{
	SpriteIterator Iterator = this->SpriteMap.find(Index);
	if (Iterator == this->SpriteMap.end())
	{
		return nullptr;
	}
	return Iterator->second;
}

