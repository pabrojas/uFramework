#include "Bounds.h"
#include "Point.h"
#include "Logger.h"

#include <SFML/Graphics.hpp>


using namespace uFramework;

Bounds::Bounds(float x, float y, float width, float height)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

/*
(x1, y1) (x3, y3)
	+-------+
	|       |
	|       |
	+-------+
(x2, y2) (x4, y4)
*/

bool Bounds::intersects(std::shared_ptr<Bounds> another)
{
	//Logger::printBounds(this->x, this->y, this->x + this->width, this->y + this->height);
	//Logger::printBounds(another->x, another->y, another->x + another->width, another->y + another->height);

	
	float epsilon = 5.0f;

	sf::FloatRect r1(this->x , this->y - epsilon, -this->width, -this->height - 2*epsilon);
	sf::FloatRect r2(another->x , another->y - epsilon, -another->width , -another->height - 2*epsilon);

	return r1.intersects(r2);
	
	
	/*
	float x1 = another->x;
	float y1 = another->y;
	Logger::log("p1");
	Logger::printPoint(x1, y1);


	if (this->contains(x1, y1))
	{
		return true;
	}

	float x2 = another->x;
	float y2 = another->y + another->height;
	Logger::log("p2");
	Logger::printPoint(x2, y2);
	
	if (this->contains(x2, y2))
	{
		return true;
	}

	float x3 = another->x + another->width;
	float y3 = another->y;
	Logger::log("p3");
	Logger::printPoint(x3, y3);
	
	if (this->contains(x3, y3))
	{
		return true;
	}

	float x4 = another->x + another->width;
	float y4 = another->y + another->height;
	Logger::log("p4");
	Logger::printPoint(x4, y4);

	if (this->contains(x4, y4))
	{
		return true;
	}

	return false;
	*/
}

bool Bounds::contains(std::shared_ptr<Point> point)
{
	return this->contains(point->x, point->y);
}

bool Bounds::contains(float xp, float yp)
{
	float x1 = this->x;
	float x2 = this->x + this->width;
	float y1 = this->y;
	float y2 = this->y + this->height;

	Logger::log("Otro:");
	Logger::printPoint(x1, y1);
	Logger::printPoint(x2, y2);

	return (x1 <= xp && xp <= x2) && (y1 <= yp && yp <= y2);
}

