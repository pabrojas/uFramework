#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <unordered_map>
#include <memory>

#include "Enums.h"

namespace uFramework
{
	class ObjectPool;
	class Object;
	class Point;

	class EngineWindow : public sf::Thread
	{
	private:

		//Fields
		sf::Mutex resourcesMutex;
		std::shared_ptr<ObjectPool> objects;
		int lastUsedIndex;
		
		//Methods
		void privateShow();

	public:

		//Class constructors
		EngineWindow();

		//Sprite Methods
		bool createSprite(std::string spriteIndex, int FPS);
		bool addFrameToSprite(std::string spriteIndex, std::string Pathname);

		//Object Methods
		void addObject(float x, float y, std::string spriteIndex);
		bool addIndexedObject(std::string ObjectIndex, float x, float y, std::string spriteIndex);
		bool addTaggedObject(std::string ObjectTag, float x, float y, std::string spriteIndex);

		std::shared_ptr<Point> getObjectOrigin(std::string ObjectIndex);
		bool setObjectOrigin(std::string ObjectIndex, float x, float y);
		bool setObjectSprite(std::string ObjectIndex, std::string spriteIndex);
		void setObjectHorizontalDirection(std::string ObjectIndex, Enums::HorizontalDirection hDirection);
		void setObjectVerticalDirection(std::string ObjectIndex, Enums::VerticalDirection vDirection);

		bool isFree(float x, float y);


		//Gamepad Methods
		bool isGamepadConnected(int GamepadId);
		bool isGamepadButtonPressed(int GamepadId, int ButtonId);
		float getGamepadAxisValue(int GamepadId, int AxisId);

		//Keyboard 
		bool isKeyPressed(std::string KeyName);






	};

}

