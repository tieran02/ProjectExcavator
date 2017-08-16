#include <Core/Game.h>
#include <Core/Input.h>

#include "Core/Scene_Management/SceneManager.h"
#include "Core/Time.h"
#include "Resources/AssetManager.h"

Game* Game::m_instance = 0;
double Time::DeltaTime = 0;
double Time::ElpasedTime = 0;

Game::Game(int width, int height, const char *title) {
    this->create(width,height,title);
	this->m_instance = this;
}

Game::~Game() {
    this->Destroy();
}

void Game::Run()
{
	this->intialise();

	loop();
	this->Destroy();
}

void Game::intialise() {
	glfwSwapInterval(0);
	this->OnInitialise();
}

void Game::Destroy() {
	SceneManager::Instance()->Destroy();
    AssetManager::Instance()->Destroy();
	this->m_window.Destroy();
	this->m_audioMaster.Destroy();
}

int Game::create(int width, int height, const char *title) {
	this->m_window.InitWindow(width,height,title);
	this->m_audioMaster.Create();
    this->m_isRunning = true;
	return 0;
}


double last = 0;
void Game::loop() {
    while(this->m_isRunning){
        if(this->m_window.ShouldClose() || Input::KeyPress(KEY_ESCAPE)){
			this->m_isRunning = false;
            return;
        }
		last = Time::ElpasedTime;
		Time::ElpasedTime = glfwGetTime();

		this->OnUpdate();
		SceneManager::Instance()->UpdateScene();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->OnRender();
		SceneManager::Instance()->RenderScene();

        this->m_window.Refresh();
		Time::DeltaTime = Time::ElpasedTime - last;
    }
}

