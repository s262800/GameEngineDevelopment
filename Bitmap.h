#pragma once

#include <string>
#include "SDL.h"
#include "SDL_render.h"
#include "Logger.h"


class Bitmap
{


public:
	Bitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false);
    ~Bitmap();

	bool CheckCollision(Bitmap* Other);
	void Draw();
	SDL_Texture* GetTextureRef();

	std::string FileName = "";

protected:
	
	SDL_Renderer* m_pRenderer;
	float m_x, m_y, m_h, m_w;

private:

	SDL_Surface* m_pbitmapSurface;
	SDL_Texture* m_pbitmapTexture;
	SDL_Rect CollisionRect;
	Logger* logger;




	int defaultRes = 32;

};