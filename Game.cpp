#include "Game.h"


#include <SDL.h>

Game::Game()
{
	m_Window = nullptr;
	m_Renderer = nullptr;

	//start uo
	SDL_Init(SDL_INIT_VIDEO);
		
	TTF_Init();


	//create the window
	m_Window = SDL_CreateWindow(
		"My Window", //title
		250, //initial x pos#include "SDL_ttf.h"
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

	
//	m_monster = new Bitmap(m_Renderer, "assets/monster.bmp", 100, 100);
	//m_monsterTrans = new Bitmap(m_Renderer, "assets/monsterTrans.bmp", 200, 100);
	//m_monsterTransKeyed = new Bitmap(m_Renderer, "assets/monsterTrans.gmp", 300, 100, true);
	
	m_monster = new Bitmap(m_Renderer, "assets/robot.bmp", 100, 100);


	m_pSmallFont = TTF_OpenFont("assets/DejaVuSans.ttf", 15);
	m_pBigFont = TTF_OpenFont("assets/DejaVuSans.ttf", 50);
	


}

Game::~Game()
{
	//clean up.
	//don't forget - we destroy in the REVERSE order they were created

	TTF_CloseFont(m_pBigFont);
	TTF_CloseFont(m_pSmallFont);


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
	CheckEvents();
	SDL_RenderClear(m_Renderer);

	m_monster->Draw(128, 128);
	//m_monsterTrans->Draw();
	//m_monsterTransKeyed->Draw();

	
	UpdateText("Small Red", 50, 10, m_pSmallFont, { 255,0,0 });
	UpdateText("Small Blue", 50, 40, m_pSmallFont, { 0,0,255 });

	char char_array[] = "Big White";
	UpdateText(char_array, 50, 140, m_pBigFont, { 255,255,255 });

	string myString = "Big Green";
	UpdateText(myString, 50, 70, m_pBigFont, { 0,255,0 });

	int testNumber = 1234;
	string testString = "Test Number: ";
	testString += to_string(testNumber);
	UpdateText(testString, 50, 210, m_pBigFont, { 255,255,255 });
	

    SDL_RenderPresent(m_Renderer);
	SDL_Delay(16);
}

void Game::UpdateText(string msg, int x, int y, TTF_Font* font, SDL_Color colour)
{
	SDL_Surface* surface = nullptr;
	SDL_Texture* texture = nullptr;

	int texW = 0;
	int texH = 0;

	surface = TTF_RenderText_Solid(font, msg.c_str(), colour);

	if (!surface)
	{
		printf("SURFACE for font not loaded \n");
		printf("%s\n", SDL_GetError());
	}

	else
	{
		texture = SDL_CreateTextureFromSurface(m_Renderer, surface);
		if (!texture)
		{
			printf("SURFACE for font not loaded! \n");
			printf("%s\n", SDL_GetError());
		}
		else
		{
			SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
			SDL_Rect textRect = { x,y,texW,texH };

			SDL_RenderCopy(m_Renderer, texture, NULL, &textRect);
		}
	}

	if (texture)
		SDL_DestroyTexture(texture);

	if (surface)
		SDL_FreeSurface(surface);



}

void Game::SetDisplayColour(int r, int g, int b, int a)
{
	if (m_Renderer)
	{
		int result = SDL_SetRenderDrawColor
		(
			m_Renderer,
			r,
			g,
			b,
			a
		);



		//wipe the display to the colour we just set
		SDL_RenderClear(m_Renderer);

	}

}



