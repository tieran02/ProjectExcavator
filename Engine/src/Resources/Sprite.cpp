#include <Resources/Sprite.h>
#include "Resources/AssetManager.h"

Sprite::Sprite(const char* name, const char* textureName, float width, float height) : Asset(AssetType::SPRITE, name), m_texture(nullptr), m_width(width), m_height(height)
{
	this->m_texture = static_cast<Texture2D*>(AssetManager::Instance()->Get(textureName));
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
