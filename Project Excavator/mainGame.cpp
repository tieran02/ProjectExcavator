#include "mainGame.h"
#include "Core/Scene_Management/SceneManager.h"
#include "testScene.h"
#include "splashScreen.h"

void mainGame::OnInitialise()
{
	SceneManager::Instance()->AddScene("splash", new splashScreen("splash"));
	SceneManager::Instance()->AddScene("test",new testScene("test"));
	SceneManager::Instance()->LoadScene("splash");
}
