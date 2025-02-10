#include "TextureManager.h"



TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
	for (auto value : m_textureMap)
	{
		SDL_DestroyTexture(value.second.tex);
		value.second.tex = nullptr;
	}
}

void TextureManager::Unload(const std::string fileName)
{
	auto searchResult = m_textureMap.find(fileName);
	if(searchResult != m_textureMap.end())
	{
		SDL_DestroyTexture(m_textureMap[fileName].tex);
		m_textureMap[fileName].tex = nullptr;
		m_textureMap.erase(searchResult);
	}
}

SDL_Texture* TextureManager::Load(const std::string fileName, bool useTransparancy, SDL_Renderer* PRenderer, int& w, int& h)
{
	SDL_Texture* m_pbitmapTexture = nullptr;
	
	//check map for file name existance
	auto searchresult = m_textureMap.find(fileName);
	if (searchresult != m_textureMap.end())
	{
		TextureData texData = m_textureMap[fileName];
		w = texData.width;
		h = texData.height;
		


	}
	else // not found, load, save and return
	{

		//if file does not exist in map
		m_surface = SDL_LoadBMP(fileName.c_str());

		if (!m_surface)
		{
			std::string Error = ("SURFACE for bitmap '%s' not loaded\n", fileName.c_str());
			Logger::Error(Error);
			std::string SDLError = ("%s\n", SDL_GetError());
			Logger::Error(SDLError);
		}
		else
		{
			if (useTransparancy)
			{
				Uint32 colourKey = SDL_MapRGB(m_surface->format, 255, 0, 255);
				SDL_SetColorKey(m_surface, SDL_TRUE, colourKey);
			}
			m_pbitmapTexture = SDL_CreateTextureFromSurface(PRenderer, m_surface);
			if (!m_pbitmapTexture)
			{
				std::string Error = ("TEXTURE for bitmap '%s' not loaded!\n", fileName.c_str());
				Logger::Error(Error);
				std::string SDLError = ("%s\n", SDL_GetError());
				Logger::Error(SDLError);
			}

			//m_textureMap[fileName] = m_pbitmapTexture;
			w = m_surface->w;
			h = m_surface->h;
		}
	}
	
	return m_pbitmapTexture;
}


