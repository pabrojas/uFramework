#pragma once

#include "SpriteList.h"
#include "ObjectList.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <unordered_map>

namespace uFramework
{
	typedef struct SpriteLocation SpriteLocation;

	class EngineWindow : public sf::Thread
	{
	private:

		//Fields
		sf::Mutex ResourcesMutex;
		SpriteList Sprites;
		ObjectList Objects;

		//Methods
		void PrivateShow();



	public:

		//Class constructors
		EngineWindow();

		//Virtual Methods
		virtual void Show();

		//Methods
		bool CreateSprite(std::string SpriteIndex, int FPS);
		bool AddFrameToSprite(std::string SpriteIndex, std::string Pathname);

		bool AddObject(std::string ObjectIndex, float X, float Y, std::string SpriteIndex);




	};

}

