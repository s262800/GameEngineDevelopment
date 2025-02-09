#ifndef INPUT
#define INPUT


#include <SDL.h>
#include <map>
#include <vector>

class Input
{
public:
	void EventKeyIsPressed(SDL_Keycode key);
	void EventKeyReleased(SDL_Keycode key);


	std::vector<SDL_Keycode> GetKeys();

	Input();
	~Input();

private:
	std::map<SDL_Keycode, bool> keysPressed;

};

#endif
