#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace uFramework
{
	class Sprite;

	class SpritePool
	{
	public:

		//Fields
		static std::unordered_map<std::string, std::shared_ptr<Sprite>> INDEXED_SPRITES;

	//public:

		//Methods
		static bool add(std::string index, std::shared_ptr<Sprite> sprite);
		static std::shared_ptr <Sprite> get(std::string index);
		static bool addFrame(std::string index, std::string pathname);

	};

}

