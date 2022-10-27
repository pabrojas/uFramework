#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

class Object;
class Point;

class ObjectPool
{
private:

	//Static Filds
	static const std::string UNDEFINED_INDEX;

	//Fields
	int undefinedIndexCounter;
	std::unordered_map<std::string, std::shared_ptr<Object>> indexedObjects;
	std::unordered_map<std::string, std::vector<std::shared_ptr<Object>>> taggedObjects;

	std::vector<std::shared_ptr<Object>> toPaintObjects;

	//Methods
	std::string createUndefinedIndex();


public:

	//Class constructors
	ObjectPool();

	//Iterators
	std::vector<std::shared_ptr<Object>>::iterator begin();
	std::vector<std::shared_ptr<Object>>::iterator end();

	//Methods
	void addObject(float x, float y, std::string spriteIndex);
	void addObject(float x, float y, float w, float h, std::string spriteIndex);

	bool addIndexedObject(std::string index, float x, float y, std::string spriteIndex);
	bool addIndexedObject(std::string index, float x, float y, float w, float h, std::string spriteIndex);

	void addTaggedObject(std::string tag, float x, float y, std::string spriteIndex);
	void addTaggedObject(std::string tag, float x, float y, float w, float h, std::string spriteIndex);

	bool addIndexedTaggedObject(std::string index, std::string tag, float x, float y, std::string spriteIndex);
	bool addIndexedTaggedObject(std::string index, std::string tag, float x, float y, float w, float h, std::string spriteIndex);

	std::shared_ptr<Point> getOriginByIndex(std::string index);
	bool setOriginByIndex(std::string index, float x, float y);
	bool moveOriginByIndex(std::string index, float dx, float dy);
	bool setSizeByIndex(std::string index, float width, float height);
	bool setSpriteByIndex(std::string index, std::string sprite);

	void moveOriginByTag(std::string tag, float dx, float dy);
	bool setSpriteByTag(std::string tag, std::string sprite);
	void setSizeByTag(std::string tag, float width, float height);

	bool setIndexedObjectTag(std::string index, std::string tag);


	std::shared_ptr<Object> get(std::string index);
	std::vector<std::shared_ptr<Object>> getTagged(std::string tag);

	void eraseAll();
	bool eraseByIndex(std::string index);
	void eraseByTag(std::string index);

	//Log
	void printLog();

};



