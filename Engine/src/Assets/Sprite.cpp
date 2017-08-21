#include <Assets/Sprite.h>
#include "Assets/AssetManager.h"

Sprite::Sprite(const char* name, const char* textureName, float pixlesPerUnit) : Asset(AssetType::SPRITE, name), m_texture(nullptr), m_pixlesPerUnit(pixlesPerUnit)
{
	this->m_texture = static_cast<Texture2D*>(AssetManager::Instance()->Get(textureName));
	this->m_region = SpriteRegion();
	this->m_height = this->m_texture->Height();
	this->m_width = this->m_texture->Width();
}


Sprite::Sprite(const char* name, const char* textureName, SpriteRegion region, float pixlesPerUnit) : Asset(AssetType::SPRITE, name), m_texture(nullptr), m_pixlesPerUnit(pixlesPerUnit)
{
	this->m_texture = static_cast<Texture2D*>(AssetManager::Instance()->Get(textureName));
	this->m_region = region;
	this->m_height = this->m_texture->Height() / region.Columns();
	this->m_width = this->m_texture->Width() / region.Rows();
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
