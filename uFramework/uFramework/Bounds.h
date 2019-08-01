#pragma once

#include <memory>

namespace uFramework
{
	class Point;

	class Bounds
	{
	public:

		//Fields
		float x;
		float y;
		float width;
		float height;

		//Class constructors
		Bounds(float x, float y, float width, float height);

		//Methods
		bool intersects(std::shared_ptr<Bounds> another);
		bool contains(std::shared_ptr<Point> point);
		bool contains(float xp, float yp);



	};

}
