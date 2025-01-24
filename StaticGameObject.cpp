#include "StaticGameObject.h"

StaticGameObject::StaticGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency) 
	:Bitmap(renderer, fileName, xpos, ypos, useTransparency)
{
	Draw();
}

StaticGameObject::~StaticGameObject()
{
}
