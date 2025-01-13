#pragma once
#include <SDL.h>
#include <vector>

class AssetEditor
{
public:
	AssetEditor(SDL_Renderer* renderer, SDL_Window* window);

	void Update();

	std::vector<Bitmap*> content;

	Bitmap* AssetMouseDrag = nullptr;
	SDL_Renderer* p_Renderer;

};