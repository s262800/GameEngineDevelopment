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
#include "SceneNames.h"

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
	std::vector<Player*> players;
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


	void SetInput(void);
	void CheckEvents();
	void Update(void);
	void SetDisplayColour(int r, int g, int b, int a);
	void UpdatePLayers();

	bool isRunning = true;
};

#endif

