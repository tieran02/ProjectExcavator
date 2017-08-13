#pragma once

#include <unordered_map>
#include "Rendering/Texture2D.h"

class TextureManager
{
public:
    TextureManager(){}

    Texture2D* AddTexture(const char *path, const char* name);

    Texture2D* GetTexture(const char* name);

    void Destroy();
    void DeleteTexture(const char* name);

    std::unordered_map<const char*, Texture2D> TextureMap() { return this->m_textureMap; };
private:
    std::unordered_map<const char*, Texture2D> m_textureMap;
};