#include "testScene.h"
#include "Resources/ResourceManager.h"
#include "Core/Game.h"
#include "Core/Scene_Management/SceneManager.h"
#include "Core/Input.h"


void testScene::OnLoad()
{
	ResourceManager::TextureManagerInstance()->AddTexture("./res/pepe.jpg", "pepe");
	spriteBatch.Init();

	GameObject* game_object = GetSceneGraph().AddGameObject("Camera");
	Camera* cam = static_cast<Camera*>(game_object->AddComponent(new Camera));
	t1 = static_cast<Transform*>(game_object->FindComponentName("Transform"));
	cam->SetMain();
}

void testScene::OnUpdate()
{
	if(Input::KeyPress(KEY_R))
	{
		SceneManager::Instance()->ReloadScene();
	}

	if(Input::KeyDown(KEY_D))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x + 1, t1->GetPosition().y));
	}

	if (Input::KeyDown(KEY_A))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x - 1, t1->GetPosition().y));
	}

	if (Input::KeyDown(KEY_W))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x, t1->GetPosition().y + 1));
	}

	if (Input::KeyDown(KEY_S))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x , t1->GetPosition().y - 1));
	}
}

void testScene::OnRender()
{
	spriteBatch.Begin();
	spriteBatch.Draw("pepe", 256, 256, -1, t1);


	spriteBatch.End();

	spriteBatch.Render();
}
