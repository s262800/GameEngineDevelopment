#include "Input.h"

void Input::EventKeyIsPressed(SDL_Keycode key)
{
	keysPressed.insert_or_assign(key, true);

}

void Input::EventKeyReleased(SDL_Keycode key)
{
	keysPressed.insert_or_assign(key, false);
}




std::vector<SDL_Keycode> Input::GetKeys()
{
	std::vector<SDL_Keycode> s;
	
	for (const auto& [key, isTrue] : keysPressed)
	{
		if (isTrue == true)
		{
			s.push_back(key);
		}
	}

	return s;
}

Input::Input()
{

}

Input::~Input()
{

}
