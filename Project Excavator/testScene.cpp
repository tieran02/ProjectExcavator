#include "Resources/AssetManager.h"
#include "Core/Components/Camera.h"
#include "Core/Components/SpriteRenderer.h"
#include "Core/Input.h"
#include "Core/Scene_Management/SceneManager.h"
#include "testScene.h"
#include <Resources/Sprite.h>
#include "Resources/Sound.h"
#include "Core/Components/AudioSource.h"
#include "Debug/Debug.h"
#include "Core/Components/AudioListener.h"

AudioSource* audio_source;

void testScene::OnLoad()
{
	SceneColor() = Color(98, 155, 247, 255);

	AssetManager::Instance()->Add(new Texture2D("spritesheet", "./res/SpriteSheet.png", true));
	AssetManager::Instance()->Add(new Texture2D("digger_texture", "./res/Digger.png", true));


	GameObject* camera = GetSceneGraph().AddGameObject("Camera");
	//camera->GetTransform().SetScale(Vector3(50, 50, 50));
	auto cam = static_cast<Camera*>(camera->AddComponent(new Camera(16,9,0.1f,5000.0f)));
	cam->SetSize(2.0f);
	cam->SetMain();
	AudioListener* audio_listener = static_cast<AudioListener*>(camera->AddComponent(new AudioListener()));

	auto digger = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("digger", "digger_texture",64,64,64)));
 	auto grass = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("grass", "spritesheet",0,7,64, 64,Vector2(64,64),64)));
	auto dirt = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("dirt", "spritesheet", 1, 7, 64, 64, Vector2(64, 64), 64)));
	auto stone = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("stone", "spritesheet", 2, 7, 64, 64, Vector2(64, 64), 64)));


	auto music = static_cast<Sound*>(AssetManager::Instance()->Add(new Sound("music","./res/music.mp3")));

	GameObject* game_object = GetSceneGraph().AddGameObject("digger");
	SpriteRenderer* sprite_renderer = static_cast<SpriteRenderer*>(game_object->AddComponent(new SpriteRenderer(GetSpriteBatch())));
	audio_source = static_cast<AudioSource*>(game_object->AddComponent(new AudioSource("music")));
	sprite_renderer->SetSprite(digger);
	game_object->GetTransform().SetPosition(Vector2(0, 4));
	RigidBody* rigid_body = static_cast<RigidBody*>(game_object->AddComponent(new RigidBody(Vector2(0.95f, 0.95f),true,1.0f,0.3f)));

	for (int i = -50; i < 50; i++)
	{

		GameObject* game_object1 = GetSceneGraph().AddGameObject("grass");
		SpriteRenderer* sprite_renderer1 = static_cast<SpriteRenderer*>(game_object1->AddComponent(new SpriteRenderer(GetSpriteBatch())));
		sprite_renderer1->SetSprite(grass);
		sprite_renderer1->SetDepth(1);
		game_object1->GetTransform().SetPosition(Vector2(i, -3));
		RigidBody* rigid_body1 = static_cast<RigidBody*>(game_object1->AddComponent(new RigidBody(Vector2(1, 1), false)));
	}

	for (int y = 4; y < 10; y++)
	{
		for (int i = -50; i < 50; i++)
		{

			GameObject* game_object1 = GetSceneGraph().AddGameObject("dirt");
			SpriteRenderer* sprite_renderer1 = static_cast<SpriteRenderer*>(game_object1->AddComponent(new SpriteRenderer(GetSpriteBatch())));
			sprite_renderer1->SetSprite(dirt);
			sprite_renderer1->SetDepth(1);
			game_object1->GetTransform().SetPosition(Vector2(i, -y));
			RigidBody* rigid_body1 = static_cast<RigidBody*>(game_object1->AddComponent(new RigidBody(Vector2(1, 1), false)));
		}
	}

}

void testScene::OnUpdate()
{
	if(Input::KeyPress(KEY_R))
	{
		SceneManager::Instance()->ReloadScene();
	}

	if(Input::KeyPress(KEY_1))
	{
		audio_source->Play();
	}
	if (Input::KeyPress(KEY_2))
	{
		audio_source->Stop();
	}
}

void testScene::OnFixedUpdate()
{
	GameObject* game_object = GetSceneGraph().FindGameObject("digger");
	if (Input::KeyDown(KEY_D))
	{
	}

	if (Input::KeyDown(KEY_A))
	{
	}

	if (Input::KeyDown(KEY_W))
	{
		game_object->GetRigidBody()->SetVelocity(Vector2(0, 10));

	}

	if (Input::KeyDown(KEY_S))
	{

	}
}

void testScene::OnRender()
{

}
