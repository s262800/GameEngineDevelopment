#pragma once
#include <string>
#include <SDL.h>
#include "Logger.h"

/**
* Renderer class.
* This class handles creation for an sdl renderer
*/

class Renderer
{
public:
	/**
* This method handles the creation of a renderer
* @param window Passes in an SDL Window when the function is called
* @return Returns a pointer to the SDL Renderer
*/

	SDL_Renderer* CreateRenderer(SDL_Window* window)
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
			std::string error = ("RENDERER intialisation failed: %\n", SDL_GetError());
			Logger::Error(error);
			printf("Press any key to continue \n");


			getchar();

			return nullptr;
		}

		return renderer;
	};

	SDL_Renderer* renderer;


};