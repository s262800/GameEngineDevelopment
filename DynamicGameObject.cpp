#include "DynamicGameObject.h"



DynamicGameObject::DynamicGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency) 
	:Bitmap(renderer, fileName, xpos, ypos, useTransparency)
{
	obj_transform = new Transform();


}

DynamicGameObject::~DynamicGameObject()
{

}

//void DynamicGameObject::DrawObject(SDL_Renderer* renderer)
//{
//	obj_bitmap->Draw(renderer, xScale, yScale);
//}


