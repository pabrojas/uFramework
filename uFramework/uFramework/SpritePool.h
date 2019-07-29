#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace uFramework
{
	class Sprite;

	class SpritePool
	{
	public:

		//Fields
		static std::unordered_map<std::string, Sprite*> INDEXED_SPRITES;

	//public:

		//Methods
		static bool add(std::string index, Sprite* sprite);
		static Sprite* get(std::string index);
		static bool addFrame(std::string index, std::string pathname);

	};

}

