#pragma once

#include <string>
#include <memory>

#include "Enums.h"

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
		std::shared_ptr<Sprite> sprite;
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
		std::shared_ptr<Sprite> getSprite();


		//Direction methods
		void setHorizontalDirection(Enums::HorizontalDirection direction);
		void setVerticalDirection(Enums::VerticalDirection direction);
		Enums::HorizontalDirection getHorizontalDirection();
		Enums::VerticalDirection getVerticalDirection();

		//Bounds methods
		bool isUsingSpriteSize();
		std::shared_ptr<Bounds> getBounds();
		bool intersects(std::shared_ptr<Bounds> other);
		bool contains(std::shared_ptr<Point> point);
		bool contains(float x, float y);


	};
}
