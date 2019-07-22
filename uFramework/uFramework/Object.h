#pragma once

#include <iostream>

namespace uFramework
{
	class Object
	{
	private:

		//Static Fields
		static std::string SPRITE_NO_SETTED;

		//Fields
		bool SizeSetted;

		//Methods

	public:

		//Fields
		float X;
		float Y;
		float W;
		float H;
		std::string SpriteIndex;

		//Class constructors
		Object(float X, float Y);
		Object(float X, float Y, float W, float H);

		//Methods



	};
}

