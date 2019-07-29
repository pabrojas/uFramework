#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace uFramework
{
	class Object;
	class Point;

	class ObjectPool
	{
	private:

		//Static Filds
		static const std::string UNDEFINED_INDEX;

		//Fields
		int undefinedIndexCounter;
		std::unordered_map<std::string, Object*> indexedObjects;
		std::unordered_map<std::string, std::vector<Object*>> taggedObjects;

		//Methods
		std::string createUndefinedIndex();


	public:

		//Class constructors
		ObjectPool();

		//Iterators
		std::unordered_map<std::string, Object*>::iterator begin();
		std::unordered_map<std::string, Object*>::iterator end();

		//Methods
		void addObject(float x, float y, std::string spriteIndex);
		void addObject(float x, float y, float w, float h, std::string spriteIndex);

		bool addIndexedObject(std::string index, float x, float y, std::string spriteIndex);
		bool addIndexedObject(std::string index, float x, float y, float w, float h, std::string spriteIndex);

		void addTaggedObject(std::string tag, float x, float y, std::string spriteIndex);
		void addTaggedObject(std::string tag, float x, float y, float w, float h, std::string spriteIndex);

		bool addIndexedTaggedObject(std::string index, std::string tag, float x, float y, std::string spriteIndex);
		bool addIndexedTaggedObject(std::string index, std::string tag, float x, float y, float w, float h, std::string spriteIndex);

		Point* getOrigin(std::string index);
		bool setOrigin(std::string index, float x, float y);
		bool moveOrigin(std::string index, float dx, float dy);

		Object* get(std::string index);

	};

}

