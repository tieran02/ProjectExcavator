#include <Engine.h>
#include <Scenes/splashScreen.h>

GameObject* game_object;
SpriteRenderer* sprite_renderer;
void splashScreen::OnLoad()
{
	SceneColor() = Color(255, 255, 255, 255);

	Vector2 pos = Vector2(static_cast<float>(Game::Instance()->GetWindow()->Width()), static_cast<float>(Game::Instance()->GetWindow()->Height()));
	AssetManager::Instance()->Add(new Texture2D("splash_texture", "./res/splash.jpg", false));

	GameObject* camera = GetSceneGraph().AddGameObject("Camera");
	auto cam = static_cast<Camera*>(camera->AddComponent(new Camera(pos.x, pos.y, .1f, 5000.0f)));
	cam->SetMain();

	auto sprite = static_cast<Sprite*>(AssetManager::Instance()->Add(new Sprite("Splash", "splash_texture", 1)));

	game_object = GetSceneGraph().AddGameObject("Splash");
	sprite_renderer = static_cast<SpriteRenderer*>(game_object->AddComponent(new SpriteRenderer()));
	sprite_renderer->SetSprite(sprite);
}

void splashScreen::OnUpdate()
{
	if (ElapsedSceneTime() > 4.0f) {
		sprite_renderer->GetColor().A -= .5f * static_cast<float>(Time::DeltaTime) * 255;

	}
	if (ElapsedSceneTime() > 6 || Input::KeyPress(KEY_SPACE))
		SceneManager::Instance()->LoadScene("game");

}

void splashScreen::OnRender()
{
}
