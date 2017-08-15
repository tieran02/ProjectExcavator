#include "Resources/AssetManager.h"
#include "Core/Components/Camera.h"
#include "Core/Components/SpriteRenderer.h"
#include "Core/Input.h"
#include "Core/Time.h"
#include "Core/Scene_Management/SceneManager.h"
#include "testScene.h"
#include <Resources/Sprite.h>


Transform* t1;

void testScene::OnLoad()
{
	AssetManager::Instance()->Add(new Texture2D("pepe_texture", "./res/pepe.jpg"));

	GameObject* camera = GetSceneGraph().AddGameObject("Camera");
	auto cam = static_cast<Camera*>(camera->AddComponent(new Camera));
	cam->SetMain();


	auto sprite = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("pepe", "pepe_texture", 256, 256)));

	GameObject* game_object = GetSceneGraph().AddGameObject("pepe");
	SpriteRenderer* sprite_renderer = static_cast<SpriteRenderer*>(game_object->AddComponent(new SpriteRenderer(GetSpriteBatch())));
	sprite_renderer->SetSprite(sprite);
	t1 = &game_object->GetTransform();
	sprite_renderer->GetColor().R = .25f;

	GameObject* game_object1 = GetSceneGraph().AddGameObject("pepe1");
	SpriteRenderer* sprite_renderer1 = static_cast<SpriteRenderer*>(game_object1->AddComponent(new SpriteRenderer(GetSpriteBatch())));
	sprite_renderer1->SetSprite(sprite);
	t1 = &game_object1->GetTransform();





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
