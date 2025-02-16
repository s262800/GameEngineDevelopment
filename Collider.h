#pragma once
#include "box2d/box2d.h"

class Collider
{
public:

	~Collider();
	
	bool CheckCollision(Collider* Other);


private:
	float colliderW, colliderH;
	float objX, objY;
};

