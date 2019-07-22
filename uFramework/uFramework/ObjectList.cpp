#include "ObjectList.h"
#include "Logger.h"

using namespace uFramework;

ObjectIterator uFramework::ObjectList::Begin()
{
	return this->ObjectMap.begin();
}

ObjectIterator ObjectList::End()
{
	return this->ObjectMap.end();
}

bool ObjectList::AddObject(std::string ObjectIndex, float X, float Y, std::string SpriteIndex)
{
	ObjectIterator Iterator = this->ObjectMap.find(ObjectIndex);
	if (Iterator != this->ObjectMap.end())
	{
		Logger::IndexAlreadyExists("Object", ObjectIndex);
		return false;
	}

	Object* NewObject = new Object(X, Y);
	NewObject->SpriteIndex = SpriteIndex;

	this->ObjectMap.emplace(ObjectIndex, NewObject);
}
