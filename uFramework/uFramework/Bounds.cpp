#include "Bounds.h"
#include "Point.h"

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
	float x1 = another->x;
	float y1 = another->y;
	if (this->contains(x1, y1))
	{
		return true;
	}

	float x2 = another->x;
	float y2 = another->y + another->height;
	if (this->contains(x2, y2))
	{
		return true;
	}

	float x3 = another->x + another->width;
	float y3 = another->y;
	if (this->contains(x3, y3))
	{
		return true;
	}

	float x4 = another->x + another->width;
	float y4 = another->y + another->height;
	if (this->contains(x4, y4))
	{
		return true;
	}

	return false;
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

