#include "Transform.hpp"
#include "Bitmap.h"
#pragma once

class DynamicGameObject
{
public:
	DynamicGameObject(Bitmap* bitmap, int xScale, int yScale);
	~DynamicGameObject();

	void DrawObject(SDL_Renderer* renderer);
	
	Bitmap* obj_bitmap;

private:

	Transform* obj_transform;

	int xScale = 1, yScale = 1;

};