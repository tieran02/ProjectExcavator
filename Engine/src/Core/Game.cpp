#include <Core/Game.h>
#include <Core/Input.h>

#include "Core/Scene_Management/SceneManager.h"
#include "Core/Time.h"
#include "Resources/AssetManager.h"
#include "Debug/Debug.h"

Game* Game::m_instance = 0;
double Time::DeltaTime = 0;
double Time::ElpasedTime = 0;
double Time::FixedDeltaTime = 0;

Game::Game(int width, int height, const char *title) {
    this->create(width,height,title);
	this->m_instance = this;
	this->m_timeStep = 1.0 / 60.0;
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
double accumulator = 0.0;
void Game::loop() {
    while(this->m_isRunning){
        if(this->m_window.ShouldClose() || Input::KeyPress(KEY_ESCAPE)){
			this->m_isRunning = false;
            return;
        }
		Time::ElpasedTime = glfwGetTime();
		Time::DeltaTime = Time::ElpasedTime - last;
		accumulator += Time::DeltaTime;
		last = Time::ElpasedTime;

		//fixedupdate
	    while (accumulator >= this->m_timeStep)
	    {
			Time::FixedDeltaTime = accumulator;
			accumulator -= this->m_timeStep;
			SceneManager::Instance()->FixedUpdateScene();
	    }

		this->OnUpdate();
		SceneManager::Instance()->UpdateScene();

		Color color = SceneManager::Instance()->GetCurrentScene().SceneColor().Normilized();
        glClearColor(color.R, color.G, color.B, color.A);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		this->OnRender();
		SceneManager::Instance()->RenderScene();

        this->m_window.Refresh();

    }
}

