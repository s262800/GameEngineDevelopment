#pragma once
#include "Transform.hpp"
#include "Bitmap.h"
class StaticGameObject : public Bitmap
{
public:
	StaticGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency);
	~StaticGameObject();


private:
	Bitmap* bitmap;


};