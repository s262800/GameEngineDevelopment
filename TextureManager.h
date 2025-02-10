#pragma once
#include <map>
#include <SDL.h>
#include <string>
#include "Logger.h"

struct TextureData
{
	SDL_Texture* tex;
	int width;
	int height;
};


class TextureManager
{
public:
	std::map<std::string, TextureData> m_textureMap;
	TextureManager();
	~TextureManager();

	SDL_Texture* Load(const std::string fileName, bool useTransparancy, SDL_Renderer* PRenderer, int& w, int& h);
	void Unload(const std::string fileName);

	SDL_Surface* m_surface;

};

