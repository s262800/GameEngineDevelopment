#include "DynamicGameObject.h"



DynamicGameObject::DynamicGameObject(Bitmap* bitmap, int scaleX, int scaleY)
{
	obj_bitmap = bitmap;
	obj_transform = new Transform();
	xScale = scaleX;
	yScale = scaleY;

}

DynamicGameObject::~DynamicGameObject()
{

}

void DynamicGameObject::DrawObject(SDL_Renderer* renderer)
{
	obj_bitmap->Draw(renderer, xScale, yScale);
}


