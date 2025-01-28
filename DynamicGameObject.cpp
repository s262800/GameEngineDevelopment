#include "DynamicGameObject.h"



DynamicGameObject::DynamicGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency) 
	:Bitmap(renderer, fileName, xpos, ypos, useTransparency)
{
	
	//Set transform
	obj_transform = new Transform(xpos, ypos);
	


	Draw();

}



DynamicGameObject::~DynamicGameObject()
{

}

 void DynamicGameObject::Update()
{
	
}






