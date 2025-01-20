#pragma once
#include "Bitmap.h"
#include "DynamicGameObject.h"
#include <vector>

class Scene
{
public:
	Bitmap* CreateBitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency);


private:

	std::vector<Bitmap*> Renderables;
	std::vector<DynamicGameObject*> DynamicGameObjects;

};

