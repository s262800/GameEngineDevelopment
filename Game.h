#ifndef GAME_H
#define GAME_H
#include <stdio.h>


class SDL_Window;
class SDL_Renderer;

class Game
{
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

public:
	Game();
	~Game();

	void Update(void);
	void SetDisplayColour(int r, int g, int b, int a);
	void ShowRender(void);


};

#endif

