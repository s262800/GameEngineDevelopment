#pragma once

#include <string>
#include "SDL.h"
#include "SDL_render.h"
#include "Logger.h"
#include "Transform.hpp"
#include "Collider.h"


class Bitmap
{


public:
	Bitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency = false);
    ~Bitmap();

	Collider* GetCollider();
	void SetCollider();


	void Draw();
	SDL_Texture* GetTextureRef();

	std::string FileName = "";

	Transform* obj_transform;

protected:
	
	SDL_Renderer* m_pRenderer;
	float m_x, m_y;
	int m_h, m_w;
	Collider* collider = nullptr;

private:

	SDL_Surface* m_pbitmapSurface;
	SDL_Texture* m_pbitmapTexture;




	int defaultRes = 32;

};