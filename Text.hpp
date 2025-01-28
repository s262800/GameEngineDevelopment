#pragma once
#include <stdio.h>
#include <string>
#include "SDL.h"
#include "SDL_ttf.h"

using namespace std;

class Text
{
private:

public:

	Text()
	{

	};

	~Text()
	{
		TTF_CloseFont(m_pBigFont);
		TTF_CloseFont(m_pSmallFont);
	};

	
	SDL_Renderer* renderer;
	TTF_Font* m_pSmallFont;
	TTF_Font* m_pBigFont;


	void OpenFonts()
	{
		m_pSmallFont = TTF_OpenFont("assets/DejaVuSans.ttf", 15);
		m_pBigFont = TTF_OpenFont("assets/DejaVuSans.ttf", 50);
	};


	void SetAllText(SDL_Renderer* m_Renderer)
	{
		renderer = m_Renderer;
		UpdateText("Small Red", 50, 10, m_pSmallFont, { 255,0,0 });
		UpdateText("Small Blue", 50, 40, m_pSmallFont, { 0,0,255 });

		char char_array[] = "Big White";
		UpdateText(char_array, 50, 140, m_pBigFont, { 255,255,255 });

		string myString = "Big Green";
		UpdateText(myString, 50, 70, m_pBigFont, { 0,255,0 });

		int testNumber = 1234;
		std::string testString = "Test Number: ";
		testString += to_string(testNumber);
		UpdateText(testString, 50, 210, m_pBigFont, { 255,255,255 });
	}

	void UpdateText(std::string msg, int x, int y, TTF_Font* font, SDL_Color colour)
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
			texture = SDL_CreateTextureFromSurface(renderer, surface);
			if (!texture)
			{
				printf("SURFACE for font not loaded! \n");
				printf("%s\n", SDL_GetError());
			}
			else
			{
				SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
				SDL_Rect textRect = { x,y,texW,texH };

				SDL_RenderCopy(renderer, texture, NULL, &textRect);
			}
		}

		if (texture)
			SDL_DestroyTexture(texture);

		if (surface)
			SDL_FreeSurface(surface);

	};
};