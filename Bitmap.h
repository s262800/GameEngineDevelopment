#pragma once

#include <string>
#include "SDL.h"
#include "SDL_render.h"
//class SDL_Surface;
//class SDL_Texture;
//class SDL_Renderer;

class Bitmap
{
private:

	SDL_Surface* m_pbitmapSurface;
	SDL_Texture* m_pbitmapTexture;
	SDL_Renderer* m_pRenderer;

	int m_x, m_y;

	int defaultRes = 32;

public:
	Bitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false);
    ~Bitmap();

	void Draw(SDL_Renderer* renderer, int xScale, int yScale);



};