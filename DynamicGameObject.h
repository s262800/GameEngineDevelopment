#pragma once
#include "Bitmap.h"


class DynamicGameObject : public Bitmap
{
public:
	DynamicGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency);
	~DynamicGameObject();

	virtual void Update();


	void SetGrounded(bool grounded);

protected:
	bool isGrounded = false;


private:
	Bitmap* bitmap;



};
