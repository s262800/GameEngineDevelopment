#include "Input.h"

void Input::KeyIsPressed(SDL_KeyCode key)
{
	keysPressed.insert_or_assign(key, true);
}

void Input::KeyReleased(SDL_KeyCode key)
{
	keysPressed.insert_or_assign(key, false);
}


Input::Input()
{

}

Input::~Input()
{

}
