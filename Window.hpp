#pragma once
#include <SDL.h>
#include "ConstantValues.h"
#include "Logger.h"

/**
* Window class.
* This class handles creation for an sdl window
*/

class Window
{
public:
/**
* This method handles the creation of a window, getting the resolution from constant values
* @param windowName Passes in a window name when the function is called
* @return Returns a pointer to the SDL Window
*/

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