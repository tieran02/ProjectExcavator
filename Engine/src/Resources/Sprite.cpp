#include <Resources/Sprite.h>
#include "Resources/AssetManager.h"

Sprite::Sprite(const char* name, const char* textureName, float width, float height, float pixlesPerUnit) : Asset(AssetType::SPRITE, name), m_texture(nullptr), m_width(width), m_height(height), m_pixlesPerUnit(pixlesPerUnit)
{
	this->m_texture = static_cast<Texture2D*>(AssetManager::Instance()->Get(textureName));
	this->m_region = SpriteRegion();
}

Sprite::Sprite(const char* name, const char* textureName, float row, float column, float width, float height, Vector2 pixles, float pixlesPerUnit) : Asset(AssetType::SPRITE, name), m_texture(nullptr), m_width(width), m_height(height), m_pixlesPerUnit(pixlesPerUnit)
{
	this->m_texture = static_cast<Texture2D*>(AssetManager::Instance()->Get(textureName));
	this->m_region = SpriteRegion(row, column, m_texture->Width(), m_texture->Height(), pixles);
}


Sprite::~Sprite()
{
}

void Sprite::Load()
{
}

Texture2D* Sprite::GetTexture() const
{
	return this->m_texture;
}

void Sprite::SetTexture(Texture2D* texture)
{
	this->m_texture = texture;
}

float Sprite::Width() const
{
	return this->m_width;
}

float Sprite::Height() const
{
	return this->m_height;
}
