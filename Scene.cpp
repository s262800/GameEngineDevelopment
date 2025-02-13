#include "Scene.h"


//Functions for creating objects

Scene::Scene(SDL_Renderer* renderer)
{
	sceneData.GetSceneData();

	for (GenericObject obj : sceneData.GetSceneData().objectsInScene)
	{
		if (obj.type == ObjectType::EmptyRenderable)
		{
			CreateBitmap(renderer, obj.fileName, obj.xPos, obj.yPos, obj.isTransparent);
		}

		if (obj.type == ObjectType::StaticGameObject)
		{
			CreateStaticGameObject(renderer, obj.fileName, obj.xPos, obj.yPos, obj.isTransparent);
		}

		if (obj.type == ObjectType::DynamicGameObject)
		{
			CreateDynamicGameObject(renderer, obj.fileName, obj.xPos, obj.yPos, obj.isTransparent);
		}

		if (obj.type == ObjectType::PlayerObject)
		{
			CreatePlayer(renderer, obj.fileName, obj.xPos, obj.yPos, obj.isTransparent);
		}

	}

}

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




