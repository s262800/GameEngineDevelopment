#include "SceneHierachyUI.h"

namespace GUI {

	SceneHierachyUI::SceneHierachyUI(Scene* s)
	{
		scene = s;

	}

	void SceneHierachyUI::Update()
	{
		ImGui::Begin("Scene Hirarcy", 0, ImGuiWindowFlags_NoMove);
		ImGui::SetWindowPos({ 0, menuHeight });
		ImGui::SetWindowSize({ 150, screenH - menuHeight });
		/*for (Bitmap* gameObject : SceanHierarchy)
		{
			if (ImGui::TreeNode(gameObject->ObjectName.c_str()))
			{
				ImGui::TreePop();
				I_GUIWindow::EditorToShow = dynamic_cast<I_GUIWindow*>(gameObject);
			}
		}*/
		ImGuiTreeNodeFlags nodeFlags = ImGuiTreeNodeFlags_FramePadding | ImGuiTreeNodeFlags_DefaultOpen;
		bool isNodeOpen = ImGui::TreeNodeEx("Scene", nodeFlags, "Scene");
		if (isNodeOpen)
		{
			//cout << bitmap->ObjectName.c_str() << endl;
			//I_GUIWindow::SelectedObject = .ObjectName;



			for (int i = 0; i < scene->GetEmptyRenderables().size(); i++)
			{
				Bitmap* child = (Bitmap*)scene->GetEmptyRenderables()[i];
				child->Draw();

			}
			ImGui::TreePop();
		}

		ImGui::End();
	}
}

