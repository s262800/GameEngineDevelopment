#include <SDL.h>
#include <map>


class Input
{
public:
	void KeyIsPressed(SDL_KeyCode key);
	void KeyReleased(SDL_KeyCode key);


	Input();
	~Input();

private:
	std::map<SDL_Keycode, bool> keysPressed;

};
