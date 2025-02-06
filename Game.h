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
#include "Events.h"
#include "Input.h"
#include "SceneHierachyUI.h"
#include "AssetEditor.h"

using namespace std;
using namespace GUI;

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
	SceneHierachyUI* sceneHierachyUI;
public :

	SDL_Window* m_Window;
	SDL_Renderer* m_Renderer;

	Input* input;
	Scene* scene;
	Events* events;
	Game();
	~Game();


	void CheckEvents(void);
	void Update(void);
	void SetDisplayColour(int r, int g, int b, int a);

	bool isRunning = true;
};

#endif

