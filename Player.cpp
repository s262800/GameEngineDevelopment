#include "Player.h"

Player::Player(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency)
	:DynamicGameObject(renderer, fileName, xpos, ypos, useTransparency)
{


}


void Player::Update()
{
	if (!isGrounded)
	{
		const float gravity = 0.98;

		yVelocity += gravity;

		m_y += yVelocity;
	}
	else {
		yVelocity = 0.0f;
	}
}

void Player::FixGroundCollision(Collider* ground)
{
	while (collider->CheckCollision(ground))
	{
		m_y -= 1;
	}
}

void Player::Jump()
{
	if (isGrounded)
	{
		isGrounded = false;
		yVelocity = -jumpForce;
	}
}




