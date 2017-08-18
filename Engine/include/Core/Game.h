#pragma once

#define STB_IMAGE_IMPLEMENTATION
#include <Core/Window.h>
#include "AudioMaster.h"

class Game{
public:
    Game(int width, int height, const char *title);
    virtual ~Game();

	virtual void OnInitialise() {};
	virtual void OnUpdate(){};
	virtual void OnRender() {};

    void Destroy();

	Window* GetWindow()  { return &m_window; }
	AudioMaster* GetAudioMaster()  { return &m_audioMaster; }
	const double& GetTimeStep() const { return m_timeStep; }

	static Game* Instance() { return m_instance; }
protected:
	void Run();
private:
    bool m_isRunning;
	static Game* m_instance;
	double m_timeStep;

    Window m_window;
	AudioMaster m_audioMaster;

	void intialise();

    int create(int width, int height, const char *title);
    void loop();

};
