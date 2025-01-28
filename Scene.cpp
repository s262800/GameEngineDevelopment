#include "Scene.h"


//Functions for creating objects

Bitmap* Scene::CreateBitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false)
{
	Bitmap* bmp = new Bitmap(renderer, fileName, xpos, ypos, useTransparency);

	return bmp;
}

DynamicGameObject* Scene::CreateDynamicGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency)
{
	DynamicGameObject* dGameObj = new DynamicGameObject(renderer, fileName, xpos, ypos, useTransparency);

	return dGameObj;
}

Player* Scene::CreatePlayer(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency)
{
	player = new Player(renderer, fileName, xpos, ypos, useTransparency);
	return player;


}

StaticGameObject* Scene::CreateStaticGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency)
{
	StaticGameObject* staticGameObj = new StaticGameObject(renderer, fileName, xpos, ypos, useTransparency);

	
	return staticGameObj;
}


//Functions for managing objects in scene

void Scene::InitialiseObjectLists(std::vector<Bitmap*> bmps, std::vector<StaticGameObject*> sGOs, std::vector<DynamicGameObject*> dGOs)
{
	
	SetVectors(bmps, sGOs, dGOs);



}

void Scene::UpdateAll()
{
	for (auto dGO : GetDynamicGameObjects())
	{
		dGO->Update();
	}
	
	if (player != nullptr)
	{
		player->Update();
	}
}

void Scene::DrawAll()
{
	for (auto dGO : GetDynamicGameObjects())
	{
		dGO->Draw();
	}
	for (auto sGO : GetStaticGameObjects())
	{
		sGO->Draw();
	}
	for (auto eR : GetEmptyRenderables())
	{
		eR->Draw();
	}

	if (player != nullptr)
	{
		player->Draw();
	}


}

SDL_Window* Scene::CreateWindow(const char* windowName)
{
	SDL_Window* window;

	//create the window
	window = SDL_CreateWindow(
		windowName, //title
		250, //initial x pos
		50, //initial y pos
		1920, //width, in pixelss
		1080, //height, in pixels
		0 // window behaviour flags
	);


	if (!window)
	{
		printf("WINDOW initialisation failed: %s\n", SDL_GetError());
		printf("Press any key to continue\n");
		getchar();
		return nullptr;

	}

	return window;
}


SDL_Renderer* Scene::CreateRenderer(SDL_Window* window)
{
	SDL_Renderer* renderer;
	
	//create renderer
	renderer = SDL_CreateRenderer(
		window,
		-1,
		0

	);

	if (!renderer)
	{
		printf("RENDERER intialisation failed: %\n", SDL_GetError());
		printf("Press any key to continue \n");
		getchar();

		return nullptr;
	}

	return renderer;


}

void Scene::SetVectors(std::vector<Bitmap*> bmps, std::vector<StaticGameObject*> sGOs, std::vector<DynamicGameObject*> dGos)
{
	if (!bmps.empty())
	{
		EmptyRenderables.assign(bmps.begin(), bmps.end());
	}

	else
		printf("Error");

	if (!sGOs.empty())
	{
		StaticGameObjects.assign(sGOs.begin(), sGOs.end());
	}
	else
		printf("Error1");

	if (!dGos.empty())
	{
		DynamicGameObjects.assign(dGos.begin(), dGos.end());
	}
	else
		printf("Error2");
}




