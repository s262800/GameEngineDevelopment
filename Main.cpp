#include <SDL.h>
#include "Game.h"
#include "Input.h"
#include "Bitmap.h"




int main(int argc, char* argv[])
{
	Game* game = new Game();
	Input* input = new Input();

	if (game && input)
	{
		Uint8 r = 127, g = 127, b = 127, a = 255;

		while (input->KeyIsPressed(KEY_ESCAPE))
		{
			input->Update();

			if (input->KeyIsPressed(KEY_R))
			{
				if (++r > 255) r = 0;
			}

			if (input->KeyIsPressed(KEY_G))
			{
				if (++g > 255) g = 0;
			}


			if (input->KeyIsPressed(KEY_B))
			{
				if (++b > 255) b = 0;
			}
			
			game->SetDisplayColour(r, g, b, a);
			game->Update();
			

		}


		delete input;
		input = nullptr;


		delete game;
		game = nullptr;
	}

	return 0;


	SDL_Quit();

}
