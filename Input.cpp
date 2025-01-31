#include "Input.h"

void Input::EventKeyIsPressed(SDL_Keycode key)
{
	keysPressed.insert_or_assign(key, true);

}

void Input::EventKeyReleased(SDL_Keycode key)
{
	keysPressed.insert_or_assign(key, false);
}




Input::Input()
{

}

Input::~Input()
{

}
