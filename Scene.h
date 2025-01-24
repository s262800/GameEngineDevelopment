#pragma once
#include "Bitmap.h"
#include "DynamicGameObject.h"
#include "StaticGameObject.h"
#include <vector>


class Scene
{
public:
	Bitmap* CreateBitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency);
	DynamicGameObject* CreateDynamicGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false);
	StaticGameObject* CreateStaticGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false);

	void InitialiseObjectLists(std::vector<Bitmap*> bmps, std::vector<StaticGameObject*> sGOs, std::vector<DynamicGameObject*> dGos);
	void UpdateAll();
	void DrawAll();
	
	void SetVectors(std::vector<Bitmap*> bmps, std::vector<StaticGameObject*> sGOs, std::vector<DynamicGameObject*> dGos);
	
	
	std::vector<Bitmap*> GetEmptyRenderables() { return EmptyRenderables; }
	std::vector<StaticGameObject*> GetStaticGameObjects() { return StaticGameObjects; }
	std::vector<DynamicGameObject*> GetDynamicGameObjects() { return DynamicGameObjects; }


private:
	std::vector<Bitmap*> EmptyRenderables;
	std::vector<StaticGameObject*> StaticGameObjects;
	std::vector<DynamicGameObject*> DynamicGameObjects;


};

