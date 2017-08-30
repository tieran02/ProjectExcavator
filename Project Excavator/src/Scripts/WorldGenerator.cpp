#include <Scripts/WorldGenerator.h>



void WorldGenerator::Awake()
{
	this->m_world = World(128, 512);
	Generate();
}

GameObject* WorldGenerator::CreateGameObject(int x, int y, TileDef& tileDef)
{
	//if tile def is null then return nullptr
	if (tileDef.Animation == nullptr && tileDef.Sprite == nullptr)
		return nullptr;

	auto gameobject =  SceneManager::Instance()->GetCurrentScene().GetSceneGraph().AddGameObject(tileDef.Name);
	gameobject->GetTransform().SetPosition(Vector2(static_cast<float>(x), static_cast<float>(-y)));

	if(tileDef.Sprite != nullptr)
	{
		//tile is a sprite
		gameobject->AddComponent(new SpriteRenderer(tileDef.Sprite));
	}else
	{
		//tile is a animimation
		gameobject->AddComponent(new SpriteRenderer());
		gameobject->AddComponent(new SpriteAnimator(tileDef.Animation, 8));
	}

	//Add tile to world
	this->m_world.AddTile(x, y, tileDef, gameobject);

	return gameobject;
}

void WorldGenerator::Generate()
{
	this->m_world.AddTileDef(m_world.TileDefCount(), "Grass", false,3,3,100.0f,100.0f, "grass");
	this->m_world.AddTileDef(m_world.TileDefCount(), "Dirt", false, 4, 5, 100.0f, 100.0f, "dirt");
	this->m_world.AddTileDef(m_world.TileDefCount(), "Stone", false, 6, 31, 100.0f, 100.0f, "stone");

	for (unsigned int x = 0; x < this->m_world.Width();x++)
	{
		for (unsigned int y = 0; y < this->m_world.Height(); y++)
		{
			if(y == 3)
			{
				this->CreateGameObject(x,y, this->m_world.GetTileDef("Grass"));
			}
			else if(y >= 4 && y <= 5)
			{
				this->CreateGameObject(x, y, this->m_world.GetTileDef("Dirt"));
			}
			else if( y>= 6)
			{
				this->CreateGameObject(x, y, this->m_world.GetTileDef("Stone"));
			}

		}
	}
}	
