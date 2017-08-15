#include <Resources/Sprite.h>
#include "Resources/AssetManager.h"

Sprite::Sprite(const char* name, const char* textureName, float width, float height) : Asset(AssetType::SPRITE, name), m_texture(nullptr), m_width(width), m_height(height)
{
	this->m_texture = static_cast<Texture*>(AssetManager::Instance()->Get(textureName));
}

Sprite::~Sprite()
{
}
