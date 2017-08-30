#pragma once
#include <vector>
#include <Scripts/Tile.h>

class World
{
public:
	World(unsigned int width, unsigned int height);
	~World();

	//Add Tile Defintion
	TileDef* AddTileDef(unsigned int id, const char* name, bool collectable, int minSpawn, int maxSpawn, float spawnChance, float durability, const char* assetName);
	int TileDefCount() const { return m_tileDefs.size(); }

	//Add Tile to world
	void AddTile(int x, int y, TileDef& tileDef, GameObject* gameObject);
	const unsigned int& Width() const { return m_width; }
	const unsigned int& Height() const { return m_height; }
	TileDef& GetTileDef(const char* name);
private:
	std::unordered_map<const char*, TileDef> m_tileDefs;
	unsigned int m_width;
	unsigned int m_height;
	std::vector<std::vector<Tile>> m_tiles;
};

