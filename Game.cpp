#include "Game.h"
#include <SDL.h>
#include "Bitmap.h"

Game::Game()
{
	m_Window = nullptr;
	m_Renderer = nullptr;

	//start uo
	SDL_Init(SDL_INIT_VIDEO);

	//create the window
	m_Window = SDL_CreateWindow(
		"My Window", //title
		250, //initial x pos
		50, //initial y pos
		640, //width, in pixelss
		480, //height, in pixels
		0 // window behaviour flags
	);


	if (!m_Window)
	{
		printf("WINDOW initialisation failed: %s\n", SDL_GetError());
		printf("Press any key to continue\n");
		getchar();
		return;

	}

	//create renderer
	m_Renderer = SDL_CreateRenderer(
		m_Window,
		-1,
		0

	);

	if (!m_Renderer)
	{
		printf("RENDERER intialisation failed: %\n", SDL_GetError());
		printf("Press any key to continue \n");
		getchar();

		return;
	}

	m_monster = new Bitmap(m_Renderer, "assets/monster.bmp", 100, 100);
	m_monsterTrans = new Bitmap(m_Renderer, "assets/monsterTrans.bmp", 200, 100);
	m_monsterTransKeyed = new Bitmap(m_Renderer, "assets/monsterTrans.gmp", 300, 100, true);



}

Game::~Game()
{
	//clean up.
	//don't forget - we destroy in the REVERSE order they were created

	if (m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
	}
	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
	}

	if (m_monsterTransKeyed)
		delete m_monsterTransKeyed;
	if (m_monsterTrans)
		delete m_monsterTrans;
	if (m_monster)
		delete m_monster;
}

void Game::CheckEvents(void)
{
}

void Game::Update(void)
{
	printf("update");
	CheckEvents();
	SDL_RenderClear(m_Renderer);

	m_monster->Draw();
	m_monsterTrans->Draw();
	m_monsterTransKeyed->Draw();

    SDL_RenderPresent(m_Renderer);
	SDL_Delay(16);
}

void Game::SetDisplayColour(int r, int g, int b, int a)
{
	if (m_Renderer)
	{
		int result = SDL_SetRenderDrawColor(
			m_Renderer,
			r,
			g,
			b,
			a
		);


		//wipe the display to the colour we just set
		SDL_RenderClear(m_Renderer);

		//show what we've drawn
		SDL_RenderPresent(m_Renderer);

		//pause for 5 secs
		SDL_Delay(5000);
	}

}



