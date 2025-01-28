#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <string>

#include "SDL.h"
#include "SDL_ttf.h"
#include "Bitmap.h"
#include "DynamicGameObject.h"
#include "Scene.h"
#include "Text.hpp"

using namespace std;

class SDL_Window;
class SDL_Renderer;
class AssetEditor;



class Game
{
private:
	AssetEditor* assetEditor;
	Text* textManager;
	Player* player;
	StaticGameObject* ground1;
public :

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;


	Scene* scene;

	Game();
	~Game();


	void CheckEvents(void);
	void Update(void);
	void SetDisplayColour(int r, int g, int b, int a);


};

#endif

