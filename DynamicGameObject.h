#pragma once
#include "Transform.hpp"
#include "Bitmap.h"


class DynamicGameObject : public Bitmap
{
public:
	DynamicGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency);
	~DynamicGameObject();

	virtual void Update();

	void SetGrounded(bool grounded) { isGrounded = grounded; }

protected:
	bool isGrounded = false;

private:

	Transform* obj_transform;
	Bitmap* bitmap;



};
