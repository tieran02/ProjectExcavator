#include "Scripts/World.h"
#include <Engine.h>

World::World(unsigned int width, unsigned int height): m_width(width), m_height(height)
{
	this->m_tiles.resize(width);
	for (unsigned int i = 0; i < width; ++i)
	{
		this->m_tiles[i].resize(height);
	}
}

World::~World()
{
	this->m_tiles.clear();
	this->m_tileDefs.clear();
}

TileDef* World::AddTileDef(unsigned int id, const char* name, bool collectable, int minSpawn, int maxSpawn, float spawnChance, float durability, const char* assetName)
{
	auto asset = AssetManager::Instance()->Get(assetName);

	if (asset != nullptr) 
	{
		if (dynamic_cast<Sprite*>(asset) != nullptr)
			this->m_tileDefs.emplace(std::piecewise_construct,
				std::make_tuple(name),
				std::make_tuple(id, name, collectable, minSpawn, maxSpawn, spawnChance, durability, static_cast<Sprite*>(asset)));
		else if (dynamic_cast<Animation*>(asset) != nullptr)
			this->m_tileDefs.emplace(std::piecewise_construct,
				std::make_tuple(name),
				std::make_tuple(id, name, collectable, minSpawn, maxSpawn, spawnChance, durability, static_cast<Animation*>(asset)));		else
		{
			LOG_ERROR("TileDef assets '" << assetName << "' is not a sprite or animation");
			return nullptr;
		}
		return &this->m_tileDefs[name];
	}
	else
		LOG_ERROR("TileDef assets '" << assetName << "' doesn't exist in asset manager");
	return nullptr;
}


void World::AddTile(int x, int y, TileDef& tileDef, GameObject* gameObject)
{
	if(x < static_cast<int>(this->m_width) && y < static_cast<int>(this->m_height))
		this->m_tiles[x][y] = Tile(&tileDef, gameObject);
	;
}

TileDef& World::GetTileDef(const char* name)
{
	return this->m_tileDefs[name];
}
