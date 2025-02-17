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

/** 
* Game class.
* This class controls the game itself during runtime
*/

class Game
{
private:
	AssetEditor* assetEditor;

	Text* textManager;
	std::vector<Player*> players;
	StaticGameObject* ground1;
	SceneHierachyUI* sceneHierachyUI;
public :

	/** A variable for an SDL window */
	SDL_Window* m_Window;
	/** A variable for an SDL renderer */
	SDL_Renderer* m_Renderer;

	/** A pointer variable for the input class*/
	Input* input;
	/** A pointer variable for the scene class*/
	Scene* scene;
	/** A pointer variable for the events class*/
	Events* events;

	/** The constructor, handles getting the scene data and setting up the renderer and window*/
	Game();

	/** The destructor*/
	~Game();

	/** A method for setting input */
	void SetInput(void);
	/** A method for Checking events, called every frame in update */
	void CheckEvents();
	/** An update method called every frame. Handles drawing and updating objects in scene */
	void Update(void);
	/** Sets the backgrounds display colour 
	* @param int r for the red value
	* @param int g for the green value
	* @param int b for the blue value
	* @param int a for the alpha value
	*/
	void SetDisplayColour(int r, int g, int b, int a);
	/** A method for handling updates specifically for players */
	void UpdatePLayers();

	/** boolean to check that the game is running */
	bool isRunning = true;
};

#endif

