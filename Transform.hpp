#pragma once
#include <vector>


struct ObjectTransform
{
	int xPos = 0;
	int yPos = 0;
	float xScale = 1;
	float yScale = 1;
	float xRot = 0;
	float yRot = 0;
};

class Transform
{
private:
	
	float posX, posY;
	float scaleX, scaleY;
	float rotX = 0, rotY = 0;


public:
	
	Transform()
	{
	}

	~Transform()
	{
	}

	void SetObjectTransform(ObjectTransform* ot)
	{
		posX = ot->xPos;
		posY = ot->yPos;
		scaleX = ot->xScale;
		scaleY = ot->yScale;
		rotX = ot->xRot;
		rotY = ot->yRot;
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


