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
			item["objectName"],
			objectType,
			item["sprite"],
			item["xpos"],
			item["ypos"],
			item["xScale"],
			item["yScale"],
			item["direction"],
			item["transparent"]
		);

	}

}

SceneValues SceneData::GetSceneData(SceneNames sceneName)
{
	std::string filePath;
	bool foundLevel = false;
	switch (sceneName)
	{
	case SceneNames::LEVEL1:
		filePath = "assets/Levels/Level1.json";
		foundLevel = true;
		break;
	case SceneNames::LEVEL2:
		filePath = "assets/Levels/Level2.json";
		foundLevel = true;
		break;
	default:
		break;

	}

	if (!foundLevel)
	{
		std::string error = "Level not found";
		Logger::Error(error);
		return currentScene;
	}
	
	ReadSceneValues(filePath);
	return currentScene;
}



ObjectType SceneData::getObjectEnumType(const std::string& type)
{
	if (type == "DGO")
		return ObjectType::DynamicGameObject;

	if (type == "SGO")
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
