#pragma once
#ifndef SCENE_H
#define SCENE_H



#include "Bitmap.h"
#include "DynamicGameObject.h"
#include "Player.h"
#include "StaticGameObject.h"
#include <vector>
#include "Logger.h"
#include "ConstantValues.h"
#include "SceneData.h"


class Scene
{
public:
	std::string sceneName;
	std::string sceneFilePath;
	SceneData sceneData;

	Scene(SDL_Renderer* renderer);
	
	//Create Objects
	Bitmap* CreateBitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency);
	DynamicGameObject* CreateDynamicGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false);
	StaticGameObject* CreateStaticGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false);

	Player* CreatePlayer(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false);

	void InitialiseObjectLists(std::vector<Bitmap*> bmps, std::vector<StaticGameObject*> sGOs, std::vector<DynamicGameObject*> dGos);
	
	//Update Objects
	void UpdateAll();
	void DrawAll();
	

	//Create the renderer and window
	SDL_Renderer* CreateRenderer(SDL_Window* window);
	SDL_Window* CreateWindow(const char* windowName);
	
	void SetVectors(std::vector<Bitmap*> bmps, std::vector<StaticGameObject*> sGOs, std::vector<DynamicGameObject*> dGos);
	
	std::vector<Bitmap*> GetEmptyRenderables() { return EmptyRenderables; }
	std::vector<StaticGameObject*> GetStaticGameObjects() { return StaticGameObjects; }
	std::vector<DynamicGameObject*> GetDynamicGameObjects() { return DynamicGameObjects; }

	Player* player;

private:
	std::vector<Bitmap*> EmptyRenderables;
	std::vector<StaticGameObject*> StaticGameObjects;
	std::vector<DynamicGameObject*> DynamicGameObjects;
	




};
#endif

