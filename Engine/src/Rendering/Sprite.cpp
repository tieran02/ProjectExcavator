//
// Created by tieran on 05/08/17.
//

#include <Resources/ResourceManager.h>
#include "Rendering/Sprite.h"

Sprite::Sprite(const char *path, const char *name, float width, float height, float depth) {
    Load(path,name,width,height,depth);
}

Sprite::Sprite(const char *path, const char *name, float width, float height) {
    Load(path,name,width,height);
}

Sprite::Sprite(const char *name, float width, float height, float depth) {
    Load(name,width,height,depth);
}

Sprite::Sprite(const char* name, float width, float height, float depth, Transform* transform)
{
	Load(name, width, height,depth,transform);
}

Sprite::Sprite(const char *name, float width, float height) {
    Load(name,width,height);
}

Sprite::~Sprite() {

}

void Sprite::Load(const char *path, const char *name, float width, float height, float depth) {
	this->m_texture = ResourceManager::TextureManagerInstance()->AddTexture(path,name);
    this->m_width = width;
    this->m_height = height;
    this->m_depth = depth;
}

void Sprite::Load(const char *path, const char *name, float width, float height) {
	this->m_texture = ResourceManager::TextureManagerInstance()->AddTexture(path,name);
    this->m_width = width;
    this->m_height = height;
}

void Sprite::Load(const char *name, float width, float height, float depth) {
	this->m_texture = ResourceManager::TextureManagerInstance()->GetTexture(name);
    this->m_width = width;
    this->m_height = height;
    this->m_depth = depth;
}

void Sprite::Load(const char *name, float width, float height) {
    this->m_texture = ResourceManager::TextureManagerInstance()->GetTexture(name);
    this->m_width = width;
    this->m_height = height;
}

void Sprite::Load(const char* name, float width, float height, float depth, Transform* transform)
{
	this->m_texture = ResourceManager::TextureManagerInstance()->GetTexture(name);
	this->m_width = width;
	this->m_height = height;
	this->m_depth = depth;
	this->m_transform = transform;
}
