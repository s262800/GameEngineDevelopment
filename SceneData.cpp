#include "SceneData.h"
#include <fstream>

void SceneData::ReadSceneValues(std::string sceneFilePath)
{
	std::ifstream input(sceneFilePath.c_str());

	if (!input)
	{
		std::string error = ("JSON FILE: " , sceneFilePath , "Could not be opened.");
		Logger::Error(error);
	}

	json parsedData = json::parse(input);

	currentScene.sceneName = parsedData["name"];

	for (auto& item : parsedData["objects"])
	{
		ObjectType objectType = getObjectEnumType(item["objectType"]);
		currentScene.objectsInScene.emplace_back(
			objectType,
			item["sprite"],
			item["xpos"],
			item["ypos"],
			item["direction"],
			item["transparent"]
		);

	}

}

ObjectType SceneData::getObjectEnumType(const std::string& type)
{
	if (type == "DGO")
		return ObjectType::DynamicGameObject;
	

	if (type == "STO")
		return ObjectType::StaticGameObject;
	
	if (type == "ER")
		return ObjectType::EmptyRenderable;
	if (type == "Player")
		return ObjectType::PlayerObject;
	
	else
	{
		Logger::Error("Could not get object's type, returning empty renderable");
		return ObjectType::EmptyRenderable;
	}
}
