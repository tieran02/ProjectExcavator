//
// Created by tieran on 05/08/17.
//

#include "Resources/ResourceManager.h"

TextureManager* ResourceManager::textureManagerInstance = 0;
ShaderManager* ResourceManager::shaderManagerInstance = 0;

TextureManager *ResourceManager::TextureManagerInstance() {
    if (textureManagerInstance == nullptr)
        textureManagerInstance = new TextureManager();

    return textureManagerInstance;
}

void ResourceManager::Destroy() {
    textureManagerInstance->Destroy();
    shaderManagerInstance->Destroy();
}

ShaderManager *ResourceManager::ShaderManagerInstance() {
    if(shaderManagerInstance == nullptr)
        shaderManagerInstance = new ShaderManager();

    return shaderManagerInstance;
}
