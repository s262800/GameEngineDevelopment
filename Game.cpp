#include "Game.h"
#include "DynamicGameObject.h"
#include "Player.h"

#include "imgui.h"
#include "backends/imgui_impl_sdl.h"
#include "imgui_sdl.h"
#include "imgui_internal.h"
#include "AssetEditor.h"

Game::Game()
{
	m_Window = nullptr;
	m_Renderer = nullptr;
	scene = new Scene();
	textManager = new Text();

	//start up
	SDL_Init(SDL_INIT_VIDEO);	
	TTF_Init();

	m_Window = scene->CreateWindow("My Window");
	m_Renderer = scene->CreateRenderer(m_Window);
	SetDisplayColour(127, 127, 127, 255);
	assetEditor = new AssetEditor(m_Renderer, m_Window);
	textManager->OpenFonts();

	//test objects

	ground1 = scene->CreateStaticGameObject(m_Renderer, "assets/groundTile1.bmp", 70, 270, true);
	ground1->obj_transform->SetScale(6, 2);

	player = scene->CreatePlayer(m_Renderer, "assets/robot.bmp", 100, 100, true);
	StaticGameObject* s = scene->CreateStaticGameObject(m_Renderer, "assets/robot.bmp", 200, 100, true);

	std::vector<StaticGameObject*> sgos;
	std::vector<Bitmap*> bmps;
	std::vector<DynamicGameObject*> dgos;
	sgos.push_back(ground1);
	//


	//Initialise objects in the scene and draw them

	scene->InitialiseObjectLists(bmps, sgos, dgos);
	scene->DrawAll();

}

Game::~Game()
{
	//clean up.
	//Destroy in the REVERSE order they were created

	textManager->~Text();


	if (m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
	}
	if (m_Window)
	{
		SDL_DestroyWindow(m_Window);
	}
}



void Game::Update(void)
{
	CheckEvents();
	SDL_RenderClear(m_Renderer);
	
	scene->DrawAll();
	scene->UpdateAll();

	textManager->SetAllText(m_Renderer);

	player->SetGrounded(player->CheckCollision(ground1));
	player->FixGroundCollision(ground1);

	//GUI
	ImGui::NewFrame();
	ImGui_ImplSDL2_NewFrame(m_Window);
	
	assetEditor->Update();

	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());
	//END GUI


    SDL_RenderPresent(m_Renderer);
	SDL_Delay(16);
}

void Game::CheckEvents(void)
{
}


void Game::SetDisplayColour(int r, int g, int b, int a)
{
	if (m_Renderer)
	{
		int result = SDL_SetRenderDrawColor
		(
			m_Renderer,
			r,
			g,
			b,
			a
		);



		//wipe the display to the colour we just set
		SDL_RenderClear(m_Renderer);

	}

}



