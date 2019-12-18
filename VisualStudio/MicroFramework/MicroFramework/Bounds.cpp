

#include "pch.h"

#include <SFML/Graphics.hpp>

#include "Bounds.h"
#include "Point.h"
#include "Logger.h"

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
	sf::FloatRect r1(this->x, this->y, this->width, this->height);
	sf::FloatRect r2(another->x, another->y, another->width, another->height);

	return r1.intersects(r2);
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

	return (x1 <= xp && xp <= x2) && (y1 <= yp && yp <= y2);
}


