#pragma once
#include <Core/Scene_Management/Scene.h>

class testScene : public Scene
{
public:
	testScene(const char* name) : Scene(name){}
	void OnLoad() override;
	void OnUpdate() override;
	void OnRender() override;
};

