#pragma once
#include "imgui.h"
#include "backends/imgui_impl_sdl.h"
#include "imgui_sdl.h"
#include "imgui_internal.h"
#include <filesystem>
#include <vector>
#include <iostream>
#include "SDL.h"
#include "Scene.h"

namespace GUI {

	class SceneHierachyUI
	{

	public:
		SceneHierachyUI(Scene* s);
		void Update();
		Scene* scene;
		float menuHeight = 100;
	};
}

