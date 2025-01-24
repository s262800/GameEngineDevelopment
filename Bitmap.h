#pragma once

#include <string>
#include "SDL.h"
#include "SDL_render.h"


class Bitmap
{


public:
	Bitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false);
    ~Bitmap();


	void Draw();
	SDL_Texture* GetTextureRef();

	std::string FileName = "";

protected:
	
	SDL_Renderer* m_pRenderer;

private:

	SDL_Surface* m_pbitmapSurface;
	SDL_Texture* m_pbitmapTexture;



	int m_x, m_y;

	int defaultRes = 32;

};