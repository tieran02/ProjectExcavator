#include <Scenes/GameScene.h>
#include "Scripts/WorldGenerator.h"


void GameScene::OnLoad()
{
	SceneColor() = Color(98, 155, 247, 255);

	//Load Resources
	//Textures
	AssetManager::Instance()->Add(new Texture2D("spritesheet", "./res/SpriteSheet.png", true));
	AssetManager::Instance()->Add(new Texture2D("digger_animation", "./res/DiggerAnimation.png", true));
	//Sprites
	AssetManager::Instance()->Add(new Sprite("grass", "spritesheet", SpriteRegion(56, 8, 8), 64));
	AssetManager::Instance()->Add(new Sprite("dirt", "spritesheet", SpriteRegion(57, 8, 8), 64));
	AssetManager::Instance()->Add(new Sprite("stone", "spritesheet", SpriteRegion(58, 8, 8), 64));
	//Animations
	AssetManager::Instance()->Add(new Animation("digger_idle", "digger_animation", 8, 2, 0, 7, 64));
	AssetManager::Instance()->Add(new Animation("digger_running", "digger_animation", 8, 2, 8, 15, 64));
	//Sounds


	//Add Camera
	auto camera_object = GetSceneGraph().AddGameObject("Camera");
	auto camera = static_cast<Camera*>(camera_object->AddComponent(new Camera(16, 9, 0.1f, 5000.0f)));
	camera->SetMain();

	//Player
	auto player_object = GetSceneGraph().AddGameObject("Player");

	//Level Generator
	auto level_object = GetSceneGraph().AddGameObject("Level");
	level_object->AddComponent(new WorldGenerator());
}

void GameScene::OnUpdate()
{
	if (Input::KeyPress(KEY_R))
	{
		SceneManager::Instance()->ReloadScene();
	}


	if (Input::KeyPress(KEY_F1))
	{
		Camera::MainCamera->SetSize(0.75f);
	}
	if (Input::KeyPress(KEY_F2))
	{
		Camera::MainCamera->SetSize(1);
	}
	if (Input::KeyPress(KEY_F3))
	{
		Camera::MainCamera->SetSize(2);
	}
	if (Input::KeyPress(KEY_F4))
	{
		Camera::MainCamera->SetSize(4);
	}
	if (Input::KeyPress(KEY_F5))
	{
		Camera::MainCamera->SetSize(10);
	}
	if (Input::KeyPress(KEY_F6))
	{
		Camera::MainCamera->SetSize(20);
	}

}

void GameScene::OnFixedUpdate()
{
}

void GameScene::OnRender()
{
}
