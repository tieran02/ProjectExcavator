#include <Core/Game.h>
#include <Core/Input.h>

#include <Math/Math.h>
#include "Resources/ResourceManager.h"
#include "Core/Scene_Management/SceneManager.h"

Game* Game::m_instance = 0;

Game::Game(int width, int height, const char *title) {
    this->create(width,height,title);
	m_instance = this;
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
    ResourceManager::Destroy();
    m_window.Destroy();
}

int Game::create(int width, int height, const char *title) {
    m_window.InitWindow(width,height,title);
    this->m_isRunning = true;
	return 0;
}


Quaternion q1;
void Game::loop() {
    while(m_isRunning){
        if(m_window.ShouldClose() || Input::KeyPress(KEY_ESCAPE)){
            m_isRunning = false;
            return;
        }
		this->OnUpdate();
		SceneManager::Instance()->UpdateScene();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->OnRender();
		SceneManager::Instance()->RenderScene();

        this->m_window.Refresh();
    }
}

