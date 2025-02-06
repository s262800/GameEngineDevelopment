#include <SDL.h>
#include "Game.h"
#include "Input.h"
#include "Bitmap.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl.h"
#include "imgui_sdl.h"
#include "imgui_internal.h"


void SetUpIMGUI(Game* game)
{
	//imGUI Setup
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	SDL_DisplayMode DisplayMode;
	SDL_GetCurrentDisplayMode(0, &DisplayMode);
	ImGuiSDL::Initialize(game->m_Renderer, DisplayMode.w, DisplayMode.h);

	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForOpenGL(game->m_Window, SDL_GL_GetCurrentContext());

}

int main(int argc, char* argv[])
{
	Game* game = new Game();
	AssetEditor* assetEditpor = new AssetEditor(game->m_Renderer, game->m_Window);

	SetUpIMGUI(game);


	while (game->isRunning)
	{
		game->Update(); //Update the game
	}


	delete game;
	game = nullptr;


	return 0;


	SDL_Quit();

}


