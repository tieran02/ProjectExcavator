#pragma once
#include "Engine.h"
#include "World.h"

class WorldGenerator : public Component
{
public:
	WorldGenerator() : Component("WorldGenerator"), m_world(1,1){}

	void Awake() override;
	GameObject* CreateGameObject(int x, int y, TileDef& tileDef);
	void Generate();
private:
	World m_world;
};
