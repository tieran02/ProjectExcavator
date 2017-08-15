#pragma once
#include "Core/Scene_Management/Scene.h"
#include <Core/Components/Transform.h>
#include "Rendering/SpriteBatch.h"
#include "Core/Components/Camera.h"

class testScene : public Scene
{
public:
	testScene(const char* name) : Scene(name){}
	void OnLoad() override;
	void OnUpdate() override;
	void OnRender() override;
private:
	Transform* t1;
};

