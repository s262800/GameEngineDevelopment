#ifndef SCENEDATA_H
#define SCENEDATA_H

#pragma once
#include "packages\nlohmann.json.3.11.3\build\native\include\nlohmann\json.hpp"
#include "Logger.h"

using json = nlohmann::json;
using ordered_json = nlohmann::ordered_json;

	enum class ObjectType {

		EmptyRenderable,
		DynamicGameObject,
		StaticGameObject
	};

	struct GenericObject {
		ObjectType type;
		std::string fileName;
		int xPos;
		int yPos;
		int direction;
		bool isTransparent;
	};

	struct Scene {
		std::string sceneName;
		std::vector<GenericObject> objectsInScene;

	};


	class SceneData
	{
	public:
		void ReadSceneValues(std::string sceneFilePath);
		Scene GetSceneData() { return currentScene; };


	private:
		Scene currentScene;
		ObjectType getObjectEnumType(const std::string& type);

	};

#endif

