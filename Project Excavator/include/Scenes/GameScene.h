#pragma once
#include <Engine.h>

class GameScene : public Scene
{
public:
	GameScene(const char* name) : Scene(name) {}
	void OnLoad() override;
	void OnUpdate() override;
	void OnFixedUpdate() override;
	void OnRender() override;
};

