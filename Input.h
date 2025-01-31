#ifndef INPUT
#define INPUT


#include <SDL.h>
#include <map>


class Input
{
public:
	void EventKeyIsPressed(SDL_Keycode key);
	void EventKeyReleased(SDL_Keycode key);


	Input();
	~Input();

private:
	std::map<SDL_Keycode, bool> keysPressed;

};

#endif
