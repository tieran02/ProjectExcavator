#pragma once
#include "Core/Scene_Management/Scene.h"

class splashScreen : public Scene
{
public:
	splashScreen(const char* name) : Scene(name) {}
	void OnLoad() override;
	void OnUpdate() override;
	void OnRender() override;
};

