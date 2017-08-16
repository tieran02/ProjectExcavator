#include "Resources/AssetManager.h"
#include "Core/Components/Camera.h"
#include "Core/Components/SpriteRenderer.h"
#include "Core/Input.h"
#include "Core/Time.h"
#include "Core/Scene_Management/SceneManager.h"
#include "testScene.h"
#include <Resources/Sprite.h>
#include "Resources/Sound.h"
#include "Core/Components/AudioSource.h"
#include "Debug/Debug.h"
#include "Core/Components/AudioListener.h"


Transform* t1;
AudioSource* audio_source;

void testScene::OnLoad()
{
	AssetManager::Instance()->Add(new Texture2D("pepe_texture", "./res/pepe.jpg"));

	GameObject* camera = GetSceneGraph().AddGameObject("Camera");
	camera->GetTransform().SetScale(Vector3(100,100,100));
	auto cam = static_cast<Camera*>(camera->AddComponent(new Camera(0,1080,0,1920,.1f,5000.0f)));
	cam->SetMain();
	AudioListener* audio_listener = static_cast<AudioListener*>(camera->AddComponent(new AudioListener()));


	auto sprite = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("pepe", "pepe_texture", 32, 32)));
	auto music = static_cast<Sound*>(AssetManager::Instance()->Add(new Sound("music","./res/music.mp3")));

	GameObject* game_object = GetSceneGraph().AddGameObject("pepe");
	SpriteRenderer* sprite_renderer = static_cast<SpriteRenderer*>(game_object->AddComponent(new SpriteRenderer(GetSpriteBatch())));
	audio_source = static_cast<AudioSource*>(game_object->AddComponent(new AudioSource("music")));
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
		t1->SetPosition(Vector2(t1->GetPosition().x + 200 * Time::DeltaTime, t1->GetPosition().y));
	}

	if (Input::KeyDown(KEY_A))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x - 200 * Time::DeltaTime, t1->GetPosition().y));
	}

	if (Input::KeyDown(KEY_W))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x, t1->GetPosition().y + 200 * Time::DeltaTime));
	}

	if (Input::KeyDown(KEY_S))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x , t1->GetPosition().y - 200 * Time::DeltaTime));
	}

	if(Input::KeyPress(KEY_1))
	{
		audio_source->Play();
	}
	if (Input::KeyPress(KEY_2))
	{
		audio_source->Stop();
	}
	GameObject* game_object = GetSceneGraph().FindGameObject("pepe");
	LOG_INFO(game_object->GetTransform().GetPosition().x << " " << game_object->GetTransform().GetPosition().y << " " << game_object->GetTransform().GetPosition().z << " ");

}

void testScene::OnRender()
{

}
