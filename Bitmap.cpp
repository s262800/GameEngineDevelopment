#include "Bitmap.h"
#include "SDL.h"
#include "SDL_render.h"

using namespace std;



Bitmap::Bitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency)
{
	m_pRenderer = renderer;

	m_pbitmapSurface = SDL_LoadBMP(fileName.c_str());
	if (!m_pbitmapSurface)
	{
		printf("Surface for bitmap '%' not loaded \n", fileName.c_str());
		printf("%\n", SDL_GetError());
		printf(fileName.c_str());

	}
	else
	{
		printf("loaded bmp");

		if (useTransparency)
		{
			Uint32 colourKey = SDL_MapRGB(m_pbitmapSurface->format, 255, 0, 255);
			SDL_SetColorKey(m_pbitmapSurface, SDL_TRUE, colourKey);

		}
		m_pbitmapTexture = SDL_CreateTextureFromSurface(m_pRenderer, m_pbitmapSurface);

		if (!m_pbitmapTexture)
		{
			printf("Texture for bitamp '%s' not loaded \n", fileName.c_str());
			printf(" % s\n", SDL_GetError());
		}
	}

	m_x = xpos;
	m_y = ypos;

}

Bitmap::~Bitmap()
{
	if (m_pbitmapTexture)
		SDL_DestroyTexture(m_pbitmapTexture);

	if (m_pbitmapSurface)
		SDL_FreeSurface;
}

void Bitmap::Draw()
{
	if (m_pbitmapTexture)
	{
		printf("drawn");

		SDL_Rect destRect = { m_x, m_y, m_pbitmapSurface->w, m_pbitmapSurface->h };
		SDL_RenderCopy(m_pRenderer, m_pbitmapTexture, NULL, &destRect);
	}
}
