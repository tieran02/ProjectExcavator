#include "mainGame.h"
#include "Core/Scene_Management/SceneManager.h"
#include "Scenes/splashScreen.h"
#include "Scenes/GameScene.h"
#include "Scenes/testScene.h"

void mainGame::OnInitialise()
{
	SceneManager::Instance()->AddScene("splash", new splashScreen("splash"));
	SceneManager::Instance()->AddScene("game",new GameScene("game"));
	SceneManager::Instance()->AddScene("test", new testScene("test"));

	SceneManager::Instance()->LoadScene("test");
}
