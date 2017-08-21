#include <Assets/Sprite.h>
#include "Assets/AssetManager.h"

Sprite::Sprite(const char* name, const char* textureName, float width, float height, float pixlesPerUnit) : Asset(AssetType::SPRITE, name), m_texture(nullptr), m_width(width), m_height(height), m_pixlesPerUnit(pixlesPerUnit)
{
	this->m_texture = static_cast<Texture2D*>(AssetManager::Instance()->Get(textureName));
	this->m_region = SpriteRegion();
}

Sprite::Sprite(const char* name, const char* textureName, float width, float height, SpriteRegion region, float pixlesPerUnit) : Asset(AssetType::SPRITE, name), m_texture(nullptr), m_width(width), m_height(height), m_pixlesPerUnit(pixlesPerUnit)
{
	this->m_texture = static_cast<Texture2D*>(AssetManager::Instance()->Get(textureName));
	this->m_region = region;
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
