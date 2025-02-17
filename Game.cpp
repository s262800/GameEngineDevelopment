#include "Game.h"
#include "DynamicGameObject.h"
#include "Player.h"
#include "Events.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl.h"
#include "imgui_sdl.h"
#include "imgui_internal.h"
#include "Renderer.hpp"
#include "Window.hpp"


Game::Game()
{
	Window* windowClass = new Window();
	m_Window = windowClass->CreateWindow("Window1");

	Renderer* rendererClass = new Renderer();
	m_Renderer = rendererClass->CreateRenderer(m_Window);


	scene = new Scene(m_Renderer, SceneNames::LEVEL1);
	players = scene->GetPlayers();
	textManager = new Text();
	input = new Input();
	events = new Events();
	

	//start up
	SDL_Init(SDL_INIT_VIDEO);	
	TTF_Init();


	SetDisplayColour(127, 127, 127, 255);
	assetEditor = new AssetEditor(m_Renderer, m_Window);
	sceneHierachyUI = new SceneHierachyUI(scene);
	textManager->OpenFonts();

	////test objects

	//ground1 = scene->CreateStaticGameObject(m_Renderer, "assets/groundTile1.bmp", 70, 670, true);
	//ground1->obj_transform->SetScale(12, 4);



	//player = scene->CreatePlayer(m_Renderer, "assets/robot.bmp", 100, 100, true);
	//player->obj_transform->SetScale(2, 2);
	//StaticGameObject* s = scene->CreateStaticGameObject(m_Renderer, "assets/robot.bmp", 200, 100, true);

	//std::vector<StaticGameObject*> sgos;
	//std::vector<Bitmap*> bmps;
	//std::vector<DynamicGameObject*> dgos;
	//sgos.push_back(ground1);
	////


	//Initialise objects in the scene and draw them

	//scene->InitialiseObjectLists(bmps, sgos, dgos);
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
	SetInput();

	SDL_RenderClear(m_Renderer);



	scene->DrawAll();
	scene->UpdateAll();
	UpdatePLayers();

	textManager->SetAllText(m_Renderer);


	//GUI
	ImGui::NewFrame();
	ImGui_ImplSDL2_NewFrame(m_Window);
	
	assetEditor->Update();
	sceneHierachyUI->Update();


	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());
	//END GUI

    SDL_RenderPresent(m_Renderer);

	SDL_Delay(16);
}

void Game::SetInput(void)
{
	SDL_Event event;
	//loop throuh all the events in the event list
	while (SDL_PollEvent(&event) != NULL)
	{
		// Check for keydown
		if (event.type == SDL_KEYDOWN)
		{
			input->EventKeyIsPressed(event.key.keysym.sym);
			CheckEvents();
		}
		//check for key up
		else if (event.type == SDL_KEYUP)
		{
			input->EventKeyReleased(event.key.keysym.sym);
			CheckEvents();
		}
		else if (event.type == SDL_QUIT)
		{
			return;
		}
	}

}

void Game::CheckEvents()
{
	for (auto key : input->GetKeys())
	{
		switch (key)
		{
		case SDLK_SPACE:
			events->FireEvent(new IEvent(E_PLAYER_JUMP, players));
			break;
		case SDLK_ESCAPE:
			isRunning = false;
			break;


		}


	}

}

void Game::UpdatePLayers()
{
	for (Player* p : players)
	{
		p->SetGrounded(p->GetCollider()->CheckCollision(ground1->GetCollider()));
	}
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





