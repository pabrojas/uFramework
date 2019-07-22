#pragma once

#include "Object.h"

#include <unordered_map>

namespace uFramework
{
	typedef std::unordered_map<std::string, Object*>::iterator ObjectIterator;

	class ObjectList
	{
	private:
		std::unordered_map<std::string, Object*> ObjectMap;


	public:

		//Iterators
		ObjectIterator Begin();
		ObjectIterator End();

		bool AddObject(std::string ObjectIndex, float X, float Y, std::string SpriteIndex);
		
	};

}

