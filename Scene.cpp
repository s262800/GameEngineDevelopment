#include "Scene.h"


Bitmap* Scene::CreateBitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false)
{
	Bitmap* bmp = new Bitmap(renderer, fileName, xpos, ypos, useTransparency);

	return bmp;
}
