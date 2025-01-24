#include "Scene.h"


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

StaticGameObject* Scene::CreateStaticGameObject(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency)
{
	StaticGameObject* staticGameObj = new StaticGameObject(renderer, fileName, xpos, ypos, useTransparency);

	
	return staticGameObj;
}

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






