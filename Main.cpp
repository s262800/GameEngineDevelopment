#include <SDL.h>
#include "Game.h"
#include "Input.h"
#include "Bitmap.h"
#include "EventSystem.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl.h"
#include "imgui_sdl.h"
#include "imgui_internal.h"
#include "AssetEditor.h"


int main(int argc, char* argv[])
{
	Game* game = new Game();
	Input* input = new Input();


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


	AssetEditor(game->m_Renderer, game->m_Window);


	
	if (game && input)

	{
		Uint8 r = 127, g = 127, b = 127, a = 255;

		while (input->KeyIsPressed(KEY_ESCAPE))
		{
	
			input->Update();	

			if (input->KeyIsPressed(KEY_R))
			{
				//if (++r > 255) r = 0;
			}

			if (input->KeyIsPressed(KEY_G))
			{
				//if (++g > 255) g = 0;
			}


			if (input->KeyIsPressed(KEY_B))
			{
				//if (++b > 255) b = 0;
			}

			if (input->KeyIsPressed(KEY_A))
			{
				
			}

			if (input->KeyIsPressed(KEY_D))
			{
				
			}
			
			//game->SetDisplayColour(r, g, b, a);
			game->Update();
			

		}


		delete input;
		input = nullptr;


		delete game;
		game = nullptr;
	}

	
	





	return 0;


	SDL_Quit();

}
