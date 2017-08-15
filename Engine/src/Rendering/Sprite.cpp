#include "Rendering/Sprite.h"
#include "Resources/AssetManager.h"
#include "Resources/TextureAsset.h"

Sprite::Sprite(const char *name, float width, float height) {
    Load(name,width,height);
}

Sprite::~Sprite() {

}

void Sprite::Load(const char *name, float width, float height) {
	this->m_texture = static_cast<TextureAsset*>(AssetManager::Instance()->Get(name));
    this->m_width = width;
    this->m_height = height;
}

