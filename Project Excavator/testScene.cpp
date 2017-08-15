#include "testScene.h"
#include "Core/Game.h"
#include "Core/Scene_Management/SceneManager.h"
#include "Core/Input.h"
#include "Core/Time.h"
#include "Debug/Debug.h"
#include "Resources/AssetManager.h"
#include "Core/Components/SpriteRenderer.h"


void testScene::OnLoad()
{
	AssetManager::Instance()->Add(new Texture("pepe_texture", "./res/wall.jpg"));

	GameObject* camera = GetSceneGraph().AddGameObject("Camera");
	Camera* cam = static_cast<Camera*>(camera->AddComponent(new Camera));
	cam->SetMain();

	Sprite* sprite = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("pepe", "pepe_texture", 128, 128)));

	GameObject* game_object = GetSceneGraph().AddGameObject("pepe");
	SpriteRenderer* sprite_renderer = static_cast<SpriteRenderer*>(game_object->AddComponent(new SpriteRenderer(GetSpriteBatch())));
	sprite_renderer->SetSprite(sprite);
	t1 = &game_object->GetTransform();


}

void testScene::OnUpdate()
{
	if(Input::KeyPress(KEY_R))
	{
		SceneManager::Instance()->ReloadScene();
	}

	if(Input::KeyDown(KEY_D))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x + 500 * Time::DeltaTime, t1->GetPosition().y));
	}

	if (Input::KeyDown(KEY_A))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x - 500 * Time::DeltaTime, t1->GetPosition().y));
	}

	if (Input::KeyDown(KEY_W))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x, t1->GetPosition().y + 500 * Time::DeltaTime));
	}

	if (Input::KeyDown(KEY_S))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x , t1->GetPosition().y - 500 * Time::DeltaTime));
	}
}

void testScene::OnRender()
{

}
