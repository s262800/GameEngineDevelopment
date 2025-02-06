#include "AssetEditor.h"

AssetEditor::AssetEditor(SDL_Renderer* renderer, SDL_Window* window)
{
	p_Renderer = renderer;

	
	std::string path = "./assets";
	for (const auto& entry : std::filesystem::directory_iterator(path)) //directory_iterator(path) //recursive_
	{
		if (entry.path().extension() == ".bmp" || entry.path().extension() == ".jpg" || entry.path().extension() == ".png")
		{
			Bitmap* Asset = new Bitmap(renderer, entry.path().string(), 0, 0, true);
			content.push_back(Asset);

		}
		else if (entry.is_directory())
		{
			std::cout << "dir " << entry << std::endl;
		}
		//debug
		std::cout << entry.path() << std::endl;
	}
}
void AssetEditor::Update()
{

	/////////////////////////////////For Draging
	if (ImGui::IsMouseReleased(ImGuiMouseButton_Left) && AssetMouseDrag != nullptr)
	{
		Logger::Info("Obj placed");
		int x, y;
		SDL_GetMouseState(&x, &y);
		Bitmap* bmp = new Bitmap(p_Renderer, AssetMouseDrag->FileName, x, y, true);
		//s->Transfrom.ParentSet(GameWindow::Instance().GetHirarcy());
		//sceneRoot.Children.push_back(&s->M_Transform);

		AssetMouseDrag = nullptr;
	}

	

	ImGui::Begin("Editor");
	ImGui::BeginChild("Content Window", ImVec2(), true);

	//ImGui::BeginTable("Content browser", 3);
	
	for (int i = 0; i < content.size(); i++)
	{
		ImGui::PushID(i);

		ImGui::ImageButton((ImTextureID)content[i]->GetTextureRef(), { 100,100 });


		/////////////////////////////////For Draging
		if (ImGui::BeginDragDropSource())
		{
			AssetMouseDrag = content[i];
			ImGui::Image((ImTextureID)content[i]->GetTextureRef(), { 100,100 });
			ImGui::EndDragDropSource();
		}
		/////////////////////////////////For Draging
		ImGui::PopID();
		ImGui::SameLine();
	}

	//ImGui::EndTabItem();

	ImGui::EndChild();
	ImGui::End();

	



}


