#include "splashScreen.h"
#include "Resources/AssetManager.h"
#include "Core/Components/Camera.h"
#include "Core/Components/SpriteRenderer.h"
#include "Core/Game.h"
#include "Core/Time.h"
#include "Core/Scene_Management/SceneManager.h"

GameObject* game_object;
SpriteRenderer* sprite_renderer;
void splashScreen::OnLoad()
{
	Vector2 pos = Vector2(Game::Instance()->GetWindow()->Width(), Game::Instance()->GetWindow()->Height());
	AssetManager::Instance()->Add(new Texture2D("splash_texture", "./res/splash.jpg"));

	GameObject* camera = GetSceneGraph().AddGameObject("Camera");
	auto cam = static_cast<Camera*>(camera->AddComponent(new Camera));
	cam->SetMain();

	auto sprite = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("Splash", "splash_texture", pos.x*SpriteBatch::PIXLES_PER_UNIT, pos.y*SpriteBatch::PIXLES_PER_UNIT)));

	game_object = GetSceneGraph().AddGameObject("Splash");
	sprite_renderer = static_cast<SpriteRenderer*>(game_object->AddComponent(new SpriteRenderer(GetSpriteBatch())));
	sprite_renderer->SetSprite(sprite);
}

void splashScreen::OnUpdate()
{
	if (m_time > 3.0f) {
		sprite_renderer->GetColor().R -= .5f * Time::DeltaTime;
		sprite_renderer->GetColor().G -= .5f * Time::DeltaTime;
		sprite_renderer->GetColor().B -= .5f * Time::DeltaTime;
	}
	if (m_time > 5)
		SceneManager::Instance()->LoadScene("test");

	m_time += Time::DeltaTime;
}

void splashScreen::OnRender()
{
	glClearColor(0, 0, 0, 1);
}
