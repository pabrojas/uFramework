#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

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
		std::unordered_map<std::string, std::shared_ptr<Object>> indexedObjects;
		std::unordered_map<std::string, std::vector<std::shared_ptr<Object>>> taggedObjects;

		//Methods
		std::string createUndefinedIndex();


	public:

		//Class constructors
		ObjectPool();

		//Iterators
		std::unordered_map<std::string, std::shared_ptr<Object>>::iterator begin();
		std::unordered_map<std::string, std::shared_ptr<Object>>::iterator end();

		//Methods
		void addObject(float x, float y, std::string spriteIndex);
		void addObject(float x, float y, float w, float h, std::string spriteIndex);

		bool addIndexedObject(std::string index, float x, float y, std::string spriteIndex);
		bool addIndexedObject(std::string index, float x, float y, float w, float h, std::string spriteIndex);

		void addTaggedObject(std::string tag, float x, float y, std::string spriteIndex);
		void addTaggedObject(std::string tag, float x, float y, float w, float h, std::string spriteIndex);

		bool addIndexedTaggedObject(std::string index, std::string tag, float x, float y, std::string spriteIndex);
		bool addIndexedTaggedObject(std::string index, std::string tag, float x, float y, float w, float h, std::string spriteIndex);

		std::shared_ptr<Point> getOrigin(std::string index);
		bool setOrigin(std::string index, float x, float y);
		bool moveOrigin(std::string index, float dx, float dy);

		std::shared_ptr<Object> get(std::string index);
		std::shared_ptr<std::vector<std::shared_ptr<Object>>> getTagged(std::string tag);

	};

}

