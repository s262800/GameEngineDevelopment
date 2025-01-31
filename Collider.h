#pragma once

class Collider
{
public:
	Collider(float w, float h, float x, float y);
	~Collider();
	
	bool CheckCollision(Collider* Other);
	


private:
	float colliderW, colliderH;
	float objX, objY;
};

