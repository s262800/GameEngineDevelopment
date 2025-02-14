#include "Scene.h"


//Constructor gets the scene data and creates the necessary objects

Scene::Scene(SDL_Renderer* renderer, SceneNames sceneName)
{
	std::vector<DynamicGameObject*> dgos;
	std::vector<StaticGameObject*> sgos;
	std::vector<Bitmap*> ers;
	std::vector<Player*> players;


	for (GenericObject obj : sceneData.GetSceneData(sceneName).objectsInScene)
	{
		if (obj.type == ObjectType::EmptyRenderable)
		{
			Bitmap* er = ers.emplace_back(CreateBitmap(renderer, obj.fileName, obj.xPos, obj.yPos, obj.isTransparent));
	
		}

		if (obj.type == ObjectType::StaticGameObject)
		{
			StaticGameObject* sgo = sgos.emplace_back(CreateStaticGameObject(renderer, obj.fileName, obj.xPos, obj.yPos, obj.isTransparent));

		}

		if (obj.type == ObjectType::DynamicGameObject)
		{
			dgos.emplace_back(CreateDynamicGameObject(renderer, obj.fileName, obj.xPos, obj.yPos, obj.isTransparent));
		}

		if (obj.type == ObjectType::PlayerObject)
		{
			players.emplace_back(CreatePlayer(renderer, obj.fileName, obj.xPos, obj.yPos, obj.isTransparent));
		}
	}

	SetVectors(ers, sgos, dgos);

}

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
	Player* p = new Player(renderer, fileName, xpos, ypos, useTransparency);
	return p;


}

StaticGameObject* Scene::CreateStaticGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency)
{
	StaticGameObject* staticGameObj = new StaticGameObject(renderer, fileName, xpos, ypos, useTransparency);

	
	return staticGameObj;
}


//Functions for managing objects in scene

void Scene::SetVectors(std::vector<Bitmap*> bmps, std::vector<StaticGameObject*> sGOs, std::vector<DynamicGameObject*> dGos)
{
	if (!bmps.empty())
	{
		EmptyRenderables.assign(bmps.begin(), bmps.end());
	}

	else
		Logger::Error("No bitmaps in scene");

	if (!sGOs.empty())
	{
		StaticGameObjects.assign(sGOs.begin(), sGOs.end());
	}
	else
		Logger::Error("No static gameobjects in scene");

	if (!dGos.empty())
	{
		DynamicGameObjects.assign(dGos.begin(), dGos.end());
	}
	else
		Logger::Error("No dynamic gameobjects in scene");
}


void Scene::UpdateAll()
{
	for (auto dGO : GetDynamicGameObjects())
	{
		dGO->Update();
	}
	
	for (auto p : GetPlayers())
	{
		p->Update();
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

	for (auto p : GetPlayers())
	{
		p->Draw();
	}


}






