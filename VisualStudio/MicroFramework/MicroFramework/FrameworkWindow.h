#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include <unordered_map>
#include <memory>

#include "Direction.h"


class ObjectPool;
class Object;
class Point;

class FrameworkWindow : public sf::Thread
{
private:

	//Fields
	int width;
	int height;
	bool fullscreen;
	std::string title;
	sf::Color backgroundColor;

	sf::RenderWindow* window;


	sf::Mutex resourcesMutex;
	std::shared_ptr<ObjectPool> objects;
	int lastUsedIndex;
	bool closed;

	//Methods
	void privateShow();

public:

	//Class constructors
	FrameworkWindow();

	//Window Methods
	bool isClosed();
	void initializeSize(int width, int height);
	void initializeTitle(std::string title);
	void initializeScreenMode(bool fullscreen);
	void setBackgroundColor(int red, int green, int blue);


	//Sprite Methods
	bool createSprite(std::string spriteIndex, int FPS);
	bool addFrameToSprite(std::string spriteIndex, std::string Pathname);

	//Add Object Methods
	void addObject(float x, float y, std::string spriteIndex);
	void addObject(float x, float y, float width, float height, std::string spriteIndex);

	bool addIndexedObject(std::string ObjectIndex, float x, float y, std::string spriteIndex);
	bool addIndexedObject(std::string ObjectIndex, float x, float y, float width, float height, std::string spriteIndex);

	void addTaggedObject(std::string ObjectTag, float x, float y, std::string spriteIndex);
	void addTaggedObject(std::string ObjectTag, float x, float y, float width, float height, std::string spriteIndex);


	//Get Indexed Object Properties
	std::shared_ptr<Point> getObjectOrigin(std::string ObjectIndex);

	//Change Indexed Object Properties Methods
	bool setIndexedObjectTag(std::string index, std::string tag);
	bool setIndexedObjectOrigin(std::string ObjectIndex, float x, float y);
	bool moveIndexedObjectOrigin(std::string ObjectIndex, float dx, float dy);
	bool setIndexedObjectSprite(std::string ObjectIndex, std::string spriteIndex);
	bool setIndexedObjectSize(std::string ObjectIndex, float width, float height);

	//Change Tagged Object Properties Methods
	void moveTaggedObjectOrigin(std::string ObjectIndex, float dx, float dy);
	bool setTaggedObjectSprite(std::string ObjectIndex, std::string spriteIndex);
	void setTaggedObjectSize(std::string ObjectIndex, float width, float height);

	
	//Erasing methods
	void eraseAll();
	void eraseByTag(std::string tag);
	bool eraseByIndex(std::string index);


	void setObjectHorizontalDirection(std::string ObjectIndex, Direction::Horizontal hDirection);
	void setObjectVerticalDirection(std::string ObjectIndex, Direction::Vertical vDirection);

	//Collides Methods
	bool isFree(float x, float y);
	
	bool preObjectCollidesObject(std::string index1, float dx, float dy, std::string index2);
	bool preObjectCollidesTag(std::string index, float dx, float dy, std::string tag);
	
	bool postObjectCollidesObject(std::string index1, std::string index2);
	bool postObjectCollidesTag(std::string index, std::string tag);
	
	bool objectDeltaCollidesTag(std::string index, std::string tag, float dx, float dy);

	//Gamepad Methods
	bool isGamepadConnected(int GamepadId);
	bool isGamepadButtonPressed(int GamepadId, int ButtonId);
	float getGamepadAxisValue(int GamepadId, int AxisId);

	//Keyboard 
	bool isKeyPressed(std::string KeyName);

	//Mouse
	sf::Vector2i getMouseLocation();
	bool isMouseButtonPressed(std::string button);

	//Log
	void printLog();

};



