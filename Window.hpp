#pragma once
#include <SDL.h>
#include "ConstantValues.h"
#include "Logger.h"

class Window
{
public:
	SDL_Window* CreateWindow(const char* windowName)
	{


		SDL_Window* window;

		//create the window
		window = SDL_CreateWindow(
			windowName, //title
			screenPosX, //initial x pos
			screenPosY, //initial y pos
			screenW, //width, in pixelss
			screenH, //height, in pixels
			0 // window behaviour flags
		);


		if (!window)
		{
			std::string error = ("WINDOW initialisation failed: %s\n", SDL_GetError());
			Logger::Error(error);
			;		printf("Press any key to continue\n");
			getchar();

			return nullptr;

		}

		return window;

	}

};