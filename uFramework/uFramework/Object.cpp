#include "Object.h"

std::string uFramework::Object::SPRITE_NO_SETTED = "<SpriteNotSetted>";


uFramework::Object::Object(float X, float Y)
{
	this->X = X;
	this->Y = Y;
	this->W = 0;
	this->H = 0;
	this->SizeSetted = false;
	this->SpriteIndex = uFramework::Object::SPRITE_NO_SETTED;
}

uFramework::Object::Object(float X, float Y, float W, float H)
{
	this->X = X;
	this->Y = Y;
	this->W = W;
	this->H = H;
	this->SizeSetted = true;
	this->SpriteIndex = uFramework::Object::SPRITE_NO_SETTED;
}


