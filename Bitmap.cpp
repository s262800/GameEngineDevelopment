#include "Bitmap.h"
#include "TextureManager.h"

using namespace std;



Bitmap::Bitmap(SDL_Renderer* renderer, std::string fileName, int xpos, int ypos, bool useTransparency)
{
	obj_transform = new Transform(xpos, ypos);
	//Store renderer and file name variables
	m_pRenderer = renderer;
	FileName = fileName;


	TextureManager* textureManager = new TextureManager();

	m_pbitmapTexture = textureManager->Load(fileName, useTransparency, m_pRenderer);
	m_pbitmapSurface = textureManager->m_surface;

	//SDL_CreateTextureFromSurface(m_pRenderer, m_pbitmapSurface);

	if (!m_pbitmapTexture)
	{
		string Error = ("Texture for bitamp '%s' not loaded \n" , fileName.c_str());
		string SDLError = (" % s\n", SDL_GetError());
		Logger::Error(Error);
		Logger::Error(SDLError);
	}
	
	//Store position values
	m_x = xpos;
	m_y = ypos;

	//Set width and height from surface
	m_h = m_pbitmapSurface->h;
	m_w = m_pbitmapSurface->w;
}

Bitmap::~Bitmap()
{
	if (m_pbitmapTexture)
		SDL_DestroyTexture(m_pbitmapTexture);

	if (m_pbitmapSurface)
		SDL_FreeSurface;
}

Collider* Bitmap::GetCollider()
{
	return collider;
}

void Bitmap::SetCollider()
{
	collider = new Collider(m_w, m_h, m_x, m_y);
}

void Bitmap::Draw()
{
	if (m_pbitmapTexture)
	{

		SDL_Rect destRect = { m_x, m_y, (obj_transform->GetXScale() * defaultRes) ,(obj_transform->GetYScale() * defaultRes)};

		m_w = obj_transform->GetXScale() * defaultRes;
		m_h = obj_transform->GetYScale()* defaultRes;

		SetCollider();

		//SDL_Rect destRect = { m_x, m_y, defaultRes , defaultRes };

		SDL_RenderCopy(m_pRenderer, m_pbitmapTexture, NULL, &destRect);
	}

	else
		Logger::Error("No bitmap texture");
}

SDL_Texture* Bitmap::GetTextureRef()
{
	return m_pbitmapTexture;
}


//bool Bitmap::CheckCollision(Bitmap* Other)
//{
//	if (
//		(m_x + m_w >= Other->m_x) && (m_x <= Other->m_x + Other->m_w) &&
//		(m_y + m_h >= Other->m_y) && (m_y <= Other->m_y + Other->m_h)
//		)
//	{
//		return true;
//	}
//	return false;
//}


