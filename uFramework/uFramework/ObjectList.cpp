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

Point* ObjectList::GetOrigin(std::string Index) 
{
	ObjectIterator Iterator = this->ObjectMap.find(Index);
	if (Iterator == this->ObjectMap.end())
	{
		Logger::IndexNotFound("Object", Index);
		return nullptr;
	}

	Object* StoredObject = Iterator->second;
	Point* Origin = new Point(StoredObject->X, StoredObject->Y);
	
	return Origin;
}

bool ObjectList::SetOrigin(std::string Index, float X, float Y)
{
	ObjectIterator Iterator = this->ObjectMap.find(Index);
	if (Iterator == this->ObjectMap.end())
	{
		Logger::IndexNotFound("Object", Index);
		return false;
	}

	Object* StoredObject = Iterator->second;
	StoredObject->X = X;
	StoredObject->Y = Y;
}
