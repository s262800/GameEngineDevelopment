#include "Collider.h"




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