#include "Transform.hpp"
#include "Bitmap.h"
#pragma once

class DynamicGameObject : public Bitmap
{
public:
	DynamicGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency);
	~DynamicGameObject();


	//void DrawObject(SDL_Renderer* renderer);

private:

	Transform* obj_transform;
	Bitmap* bitmap;
	int xScale = 1, yScale = 1;

};
