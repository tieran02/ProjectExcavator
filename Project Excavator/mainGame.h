#pragma once
#include "Core/Game.h"
#include "Rendering/SpriteBatch.h"


class mainGame : public Game
{
public:
	mainGame(int width, int height, const char* title) : Game(width, height, title)
	{
		this->Run();
	}

	void OnInitialise() override;


private:
};

