#include <Scripts/Tile.h>

Tile::Tile(TileDef* tile_def, GameObject* game_object) : m_tileDef(tile_def), gameObject(game_object)
{
}

Tile::~Tile()
{
}
