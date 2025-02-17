#pragma once
#include "Bitmap.h"
#include "Events.h"


class DynamicGameObject : public Bitmap, public IEventHandler
{
public:
	DynamicGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency);
	~DynamicGameObject();

	virtual void Update();


	void SetGrounded(bool grounded);

	void OnEvent(IEvent* event);



protected:
	bool isGrounded = false;
    EventType eventType;

private:
	Bitmap* bitmap;



};
