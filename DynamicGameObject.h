#pragma once
#include "Transform.hpp"
#include "Bitmap.h"


class DynamicGameObject : public Bitmap
{
public:
	DynamicGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency);
	~DynamicGameObject();

	void Update();


	//void DrawObject(SDL_Renderer* renderer);

private:

	Transform* obj_transform;
	Bitmap* bitmap;


};
