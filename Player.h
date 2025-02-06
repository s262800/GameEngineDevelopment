#pragma once
#include "DynamicGameObject.h"
#include "StaticGameObject.h"


class Player : public DynamicGameObject
{
public:
	Player(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency);

	void Update() override;

	void FixGroundCollision(Collider* ground);
	void Jump();

private:
	float yVelocity;

	const float jumpForce = 30.0f;


};

