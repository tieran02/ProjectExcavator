#include "mainGame.h"
#include "Resources/ResourceManager.h"
#include "Core/Scene_Management/SceneManager.h"
#include "testScene.h"

void mainGame::OnInitialise()
{
	SceneManager::Instance()->AddScene("test",new testScene("test"));
	SceneManager::Instance()->LoadScene("test");
}
