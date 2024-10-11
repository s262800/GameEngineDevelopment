#ifndef GAME_H
#define GAME_H
#include <stdio.h>


class SDL_Window;
class SDL_Renderer;
class Bitmap;


class Game
{
private:
	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	Bitmap* m_monster;
	Bitmap* m_monsterTrans;
	Bitmap* m_monsterTransKeyed;

public:
	Game();
	~Game();


	void CheckEvents(void);
	void Update(void);
	void SetDisplayColour(int r, int g, int b, int a);


};

#endif

