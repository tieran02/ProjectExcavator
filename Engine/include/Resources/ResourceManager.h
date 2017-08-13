#pragma once

#include "TextureManager.h"
#include "ShaderManager.h"

class ResourceManager
{
public:
    ResourceManager(){};
    ~ResourceManager(){};

    static TextureManager* TextureManagerInstance();
    static ShaderManager* ShaderManagerInstance();

    static void Destroy();

private:
    static TextureManager* textureManagerInstance;
    static ShaderManager* shaderManagerInstance;
};
