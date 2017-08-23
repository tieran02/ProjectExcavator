#include "Assets/AssetManager.h"
#include "Core/Components/Camera.h"
#include "Core/Components/SpriteRenderer.h"
#include "Core/Input.h"
#include "Core/Scene_Management/SceneManager.h"
#include "testScene.h"
#include <Assets/Sprite.h>
#include "Assets/Sound.h"
#include "Core/Components/AudioSource.h"
#include "Debug/Debug.h"
#include "Core/Components/AudioListener.h"
#include "Assets/Animation.h"
#include "Core/Components/SpriteAnimator.h"

AudioSource* audio_source;
Camera* cam;

void testScene::OnLoad()
{
	SceneColor() = Color(98, 155, 247, 255);

	AssetManager::Instance()->Add(new Texture2D("spritesheet", "./res/SpriteSheet.png", true));
	AssetManager::Instance()->Add(new Texture2D("digger_animation", "./res/DiggerAnimation.png", true));
	AssetManager::Instance()->Add(new Texture2D("tilesheet", "./res/sheet1.png", true));


	GameObject* camera = GetSceneGraph().AddGameObject("Camera");
	cam = static_cast<Camera*>(camera->AddComponent(new Camera(16,9,0.1f,5000.0f)));
	cam->SetSize(1.0f);
	cam->SetMain();
	AudioListener* audio_listener = static_cast<AudioListener*>(camera->AddComponent(new AudioListener()));

	auto digger = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("digger", "digger_animation",SpriteRegion(0,8, 2),64)));
	auto diggerIdle = static_cast<Animation*>(AssetManager::Instance()->Add(new Animation("digger_idle", "digger_animation",8,2,0,7,64)));
	auto diggerRunning = static_cast<Animation*>(AssetManager::Instance()->Add(new Animation("digger_running", "digger_animation", 8, 2, 8, 15, 64)));

 	auto grass = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("grass", "spritesheet", SpriteRegion(56, 8, 8),64)));
	auto dirt = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("dirt", "spritesheet", SpriteRegion(57, 8, 8), 64)));
	auto stone = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("stone", "spritesheet", SpriteRegion(58, 8, 8), 64)));


	auto music = static_cast<Sound*>(AssetManager::Instance()->Add(new Sound("music","./res/music.mp3")));

	GameObject* game_object = GetSceneGraph().AddGameObject("digger");
	SpriteRenderer* sprite_renderer = static_cast<SpriteRenderer*>(game_object->AddComponent(new SpriteRenderer(GetSpriteBatch(),digger)));
	auto* sprite_animator = static_cast<SpriteAnimator*>(game_object->AddComponent(new SpriteAnimator(diggerRunning,16)));


	audio_source = static_cast<AudioSource*>(game_object->AddComponent(new AudioSource("music")));
	game_object->GetTransform().SetPosition(Vector2(0, 4));
	RigidBody* rigid_body = static_cast<RigidBody*>(game_object->AddComponent(new RigidBody(Vector2(1.0f, 0.95f),true,true,1.0f,0.3f)));

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
			sprite_renderer1->SetDepth(1);
			game_object1->GetTransform().SetPosition(Vector2(i, -y));
			RigidBody* rigid_body1 = static_cast<RigidBody*>(game_object1->AddComponent(new RigidBody(Vector2(1, 1), false)));

			if(y > 4)
			{
				sprite_renderer1->SetSprite(stone);
			}else
				sprite_renderer1->SetSprite(dirt);
		}
	}

}

void testScene::OnUpdate()
{
	if(Input::KeyPress(KEY_R))
	{
		SceneManager::Instance()->ReloadScene();
	}

	if(Input::KeyUp(KEY_1))
	{
		audio_source->Play();
	}
	if (Input::KeyUp(KEY_2))
	{
		audio_source->Stop();
	}

	if (Input::KeyPress(KEY_3))
	{
		glfwSwapInterval(0);
	}
	if (Input::KeyPress(KEY_4))
	{
		glfwSwapInterval(1);
	}

	if(Input::KeyPress(KEY_F1))
	{
		cam->SetSize(0.75f);
	}
	if (Input::KeyPress(KEY_F2))
	{
		cam->SetSize(1.0f);
	}
	if (Input::KeyPress(KEY_F3))
	{
		cam->SetSize(1.5f);
	}
	if (Input::KeyPress(KEY_F4))
	{
		cam->SetSize(2.0f);
	}
}

void testScene::OnFixedUpdate()
{
	GameObject* game_object = GetSceneGraph().FindGameObject("digger");
	game_object->GetRigidBody()->SetVelocity(Vector2(0, game_object->GetRigidBody()->GetVelocity().y));

	if (Input::KeyDown(KEY_D))
	{
		Quaternion q;
		q.EulerAngles(Vector3(0, 1, 0), Radians::FromDegrees(0));
		game_object->GetTransform().SetRotation(q);
		game_object->GetRigidBody()->SetVelocity(Vector2(game_object->GetTransform().Right().x * 5.0f, game_object->GetRigidBody()->GetVelocity().y));

	}

	if (Input::KeyDown(KEY_A))
	{
		Quaternion q;
		q.EulerAngles(Vector3(0, 1, 0), Radians::FromDegrees(180));
		game_object->GetTransform().SetRotation(q);
		game_object->GetRigidBody()->SetVelocity(Vector2(game_object->GetTransform().Right().x * 5.0f, game_object->GetRigidBody()->GetVelocity().y));

	}

	if (Input::KeyPress(KEY_W))
	{
		game_object->GetRigidBody()->SetVelocity(Vector2(game_object->GetRigidBody()->GetVelocity().x, 10));

	}

	if (Input::KeyDown(KEY_S))
	{

	}
}

void testScene::OnRender()
{

}
