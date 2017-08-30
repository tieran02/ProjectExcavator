#pragma once
#include "Engine.h"

struct TileDef
{
	TileDef() = default;
	TileDef(unsigned int id, const char* name, bool collectable, int minSpawn, int maxSpawn, float spawnChance, float durability, Sprite* sprite)
	{
		UID = id;
		Name = name;
		Collectable = collectable;
		Durability = durability;
		MinPos = minSpawn;
		MaxPos = maxSpawn;
		SpawnChance = spawnChance;
		Sprite = sprite;
		Animation = nullptr;
	}

	TileDef(unsigned int id, const char* name, bool collectable, int minSpawn, int maxSpawn, float spawnChance, float durability, Animation* animation)
	{
		UID = id;
		Name = name;
		Collectable = collectable;
		Durability = durability;
		MinPos = minSpawn;
		MaxPos = maxSpawn;
		SpawnChance = spawnChance;
		Sprite = nullptr;
		Animation = animation;
	}

	~TileDef(){}

	unsigned int UID;
	const char* Name;
	int MinPos;
	int MaxPos;
	float SpawnChance;
	float Durability;
	bool Collectable;
	Sprite* Sprite;
	Animation* Animation;
};

class Tile
{
public:
	Tile(){}
	Tile(TileDef* tile_def, GameObject* game_object);
	~Tile();
private:
	TileDef* m_tileDef;
	GameObject* gameObject;

};