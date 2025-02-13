#pragma once
#include <string>
#include <SDL.h>
#include "Logger.h"

class Renderer
{
public:


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