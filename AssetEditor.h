#include "imgui.h"
#include "backends/imgui_impl_sdl.h"
#include "imgui_sdl.h"
#include "imgui_internal.h"
#include "Bitmap.h"
#include <filesystem>
#include <vector>
#include <iostream>
#include "SDL.h"

class AssetEditor
{
public:
	AssetEditor(SDL_Renderer* renderer, SDL_Window* window);

	void Update();

	std::vector<Bitmap*> content;

	Bitmap* AssetMouseDrag = nullptr;
	SDL_Renderer* p_Renderer;

};