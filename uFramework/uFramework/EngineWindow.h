#pragma once

#include "SpriteList.h"
#include "ObjectList.h"
#include "Point.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <unordered_map>

namespace uFramework
{
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

		//Sprite Methods
		bool CreateSprite(std::string SpriteIndex, int FPS);
		bool AddFrameToSprite(std::string SpriteIndex, std::string Pathname);

		//Object Methods
		bool AddObject(std::string ObjectIndex, float X, float Y, std::string SpriteIndex);
		Point* GetObjectOrigin(std::string ObjectIndex);
		bool SetObjectOrigin(std::string ObjectIndex, float X, float Y);
		
		//Gamepad Methods
		bool IsGamepadConnected(int GamepadId);
		bool IsGamepadbuttonPressed(int GamepadId, int ButtonId);
		float GetGamepadAxisValue(int GamepadId, int AxisId);




	};

}

