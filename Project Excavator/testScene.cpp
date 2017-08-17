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
	SceneColor() = Color(98, 155, 247, 255);

	AssetManager::Instance()->Add(new Texture2D("spritesheet", "./res/SpriteSheet.png", true));

	GameObject* camera = GetSceneGraph().AddGameObject("Camera");
	camera->GetTransform().SetScale(Vector3(100,100,100));
	auto cam = static_cast<Camera*>(camera->AddComponent(new Camera(0,1080,0,1920,.1f,5000.0f)));
	cam->SetMain();
	AudioListener* audio_listener = static_cast<AudioListener*>(camera->AddComponent(new AudioListener()));


 	auto grass = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("grass", "spritesheet",0,7,64, 64,Vector2(64,64),64)));
	auto dirt = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("dirt", "spritesheet", 1, 7, 64, 64, Vector2(64, 64), 64)));
	auto stone = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("stone", "spritesheet", 2, 7, 64, 64, Vector2(64, 64), 64)));


	auto music = static_cast<Sound*>(AssetManager::Instance()->Add(new Sound("music","./res/music.mp3")));

	GameObject* game_object = GetSceneGraph().AddGameObject("grass");
	SpriteRenderer* sprite_renderer = static_cast<SpriteRenderer*>(game_object->AddComponent(new SpriteRenderer(GetSpriteBatch())));
	audio_source = static_cast<AudioSource*>(game_object->AddComponent(new AudioSource("music")));
	sprite_renderer->SetSprite(grass);

	GameObject* game_object1 = GetSceneGraph().AddGameObject("dirt");
	SpriteRenderer* sprite_renderer1 = static_cast<SpriteRenderer*>(game_object1->AddComponent(new SpriteRenderer(GetSpriteBatch())));
	sprite_renderer1->SetSprite(dirt);

	GameObject* game_object2 = GetSceneGraph().AddGameObject("stone");
	SpriteRenderer* sprite_renderer2 = static_cast<SpriteRenderer*>(game_object2->AddComponent(new SpriteRenderer(GetSpriteBatch())));
	sprite_renderer2->SetSprite(stone);
	game_object2->GetTransform().SetPosition(Vector2(1, 0));

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
		t1->SetPosition(Vector2(t1->GetPosition().x + 2 * Time::DeltaTime, t1->GetPosition().y));
	}

	if (Input::KeyDown(KEY_A))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x - 2 * Time::DeltaTime, t1->GetPosition().y));
	}

	if (Input::KeyDown(KEY_W))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x, t1->GetPosition().y + 2 * Time::DeltaTime));
	}

	if (Input::KeyDown(KEY_S))
	{
		t1->SetPosition(Vector2(t1->GetPosition().x , t1->GetPosition().y - 2 * Time::DeltaTime));
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

void testScene::OnRender()
{

}
