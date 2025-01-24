#include "Bitmap.h"
#include "TextureManager.h"
#include <iostream>
using namespace std;




Bitmap::Bitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency)
{
	//Store renderer and file name variables
	m_pRenderer = renderer;
	FileName = fileName;


	TextureManager* textureManager = new TextureManager();

	m_pbitmapTexture = textureManager->Load(fileName, useTransparency, m_pRenderer);
	m_pbitmapSurface = textureManager->m_surface;

	//SDL_CreateTextureFromSurface(m_pRenderer, m_pbitmapSurface);

	if (!m_pbitmapTexture)
	{
		printf("Texture for bitamp '%s' not loaded \n", fileName.c_str());
		printf(" % s\n", SDL_GetError());
	}
	
	//Store position values
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
		//SDL_Rect destRect = { m_x, m_y, (xScale * defaultRes) ,(yScale * defaultRes)}; old way to set scale

		SDL_Rect destRect = { m_x, m_y, defaultRes , defaultRes};

		SDL_RenderCopy(m_pRenderer, m_pbitmapTexture, NULL, &destRect);
	}

	else
		cerr << "Drawing Error";
}

SDL_Texture* Bitmap::GetTextureRef()
{
	return m_pbitmapTexture;
}
