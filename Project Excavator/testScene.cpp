#include "testScene.h"
#include "Resources/ResourceManager.h"
#include "Core/Game.h"
#include "Core/Scene_Management/SceneManager.h"


void testScene::OnLoad()
{
	ResourceManager::TextureManagerInstance()->AddTexture("./res/pepe.jpg", "pepe");
	spriteBatch.Init();

	GameObject* game_object = GetSceneGraph().AddGameObject("Camera");
	Camera* cam = static_cast<Camera*>(game_object->AddComponent(new Camera));
	cam->SetMain();
}

void testScene::OnUpdate()
{

	t1.SetPosition(Vector3(128, 128, 0));
}

void testScene::OnRender()
{
	spriteBatch.Begin();
	spriteBatch.Draw("pepe", 256, 256, -1, t1);


	spriteBatch.End();

	spriteBatch.Render();
}
