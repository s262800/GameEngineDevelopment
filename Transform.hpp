#pragma once
#include <vector>

class Transform
{

private:
	
	float posX, posY;
	float scaleX, scaleY;
	float rotX = 0, rotY = 0;

public:
	
	Transform(float pX, float pY, float sX = 1, float sY = 1, float rX = 0, float rY = 0)
	{
		SetPosition(pX, pY);
		SetScale(sX, sY);
		SetRotation(rX, rY);
	}

	~Transform()
	{
	}



	void SetPosition(float x, float y)
	{
		posX = x;
		posY = y;
	}

	void SetScale(float x, float y)
	{
		scaleX = x;
		scaleY = y;
	}

	void SetRotation(float x, float y)
	{
		rotX = x;
		rotY = y;
	}
	
	void UpdatePosX(float xDelta) 
	{ 
		posX += xDelta;
	}

	void UpdatePosY(float yDelta) 
	{
		posY += yDelta;
	}



	float GetXPos() const 
	{ 
		return posX; 
	}

	float GetYPos() const 
	{ 
		return posY; 
	}

	float GetXScale() const
	{
		return scaleX;
	}

	float GetYScale() const
	{
		return scaleY;
	}

};


