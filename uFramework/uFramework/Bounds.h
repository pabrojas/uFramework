#pragma once

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
		bool intersects(Bounds* another);
		bool contains(Point* point);
		bool contains(float xp, float yp);



	};

}
