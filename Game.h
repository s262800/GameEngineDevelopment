#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <string>

#include "SDL.h"
#include "SDL_ttf.h"

using namespace std;

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

	TTF_Font* m_pSmallFont;
	TTF_Font* m_pBigFont;

public:
	Game();
	~Game();


	void CheckEvents(void);
	void UpdateText(string msg, int x, int y, TTF_Font* font, SDL_Color colour);
	void Update(void);
	void SetDisplayColour(int r, int g, int b, int a);


};

#endif

