#pragma once

#include "Enums.h"

#include <string>

namespace uFramework
{
	class Bounds;
	class Sprite;
	class Point;

	class Object
	{

	private:

		//Static Fields
		static const std::string SPRITE_NO_SETTED;


		//Fields
		float width;
		float height;
		Sprite* sprite;
		std::string spriteIndex;
		bool usingSpriteSize;
		Enums::HorizontalDirection hDirection;
		Enums::VerticalDirection vDirection;



	public:

		//Fields
		float x;
		float y;

		//Class constructors
		Object(float x, float y);
		Object(float x, float y, std::string spriteIndex);
		Object(float x, float y, float w, float h);
		Object(float x, float y, float w, float h, std::string spriteIndex);

		//Sprite methods
		bool setSprite(std::string spriteIndex);
		Sprite* getSprite();


		//Direction methods
		void setHorizontalDirection(Enums::HorizontalDirection direction);
		void setVerticalDirection(Enums::VerticalDirection direction);
		Enums::HorizontalDirection getHorizontalDirection();
		Enums::VerticalDirection getVerticalDirection();

		//Bounds methods
		bool isUsingSpriteSize();
		Bounds* getBounds();
		bool intersects(Bounds* other);
		bool contains(Point* point);
		bool contains(float x, float y);


	};
}
