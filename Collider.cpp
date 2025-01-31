#include "Collider.h"




Collider::Collider(float w, float h, float x, float y)
{
	colliderW = w;
	colliderH = h;
	objX = x;
	objY = y;
}

Collider::~Collider()
{

}

bool Collider::CheckCollision(Collider* Other)
{
	if (
		(objX + colliderW >= Other->objX) && (objX <= Other->objX + Other->colliderW) &&
		(objY + colliderH >= Other->objY) && (objY <= Other->objY + Other->colliderH)
		)
	{
		return true;
	}

	return false;

}