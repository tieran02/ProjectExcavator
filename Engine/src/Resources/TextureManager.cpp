//
// Created by tieran on 05/08/17.
//

#include <iostream>
#include "Resources/TextureManager.h"
#include "Debug/Debug.h"

Texture2D* TextureManager::GetTexture(const char* name)
{
    //Check if texture alredy exists in texture map
    auto it = this->m_textureMap.find(name);
    if (it != m_textureMap.end())
    {
        //Texture does exist
        return &this->m_textureMap[name];
    }else
		Debug::Log(LogLevel::logERROR, static_cast<std::string>("Texture doesn't exist! ") += name);
	return nullptr;
}

Texture2D *TextureManager::AddTexture(const char *path, const char* name) {
    auto it = this->m_textureMap.find(name);
    if (it == m_textureMap.end())
    {
        //Texture doesn't exist
		m_textureMap.emplace(name, path);
        return &this->m_textureMap[name];
    }else
	{
		std::string error = "Texture '";
		error.append(it->first);
		error.append("' alredy added");
		Debug::Log(LogLevel::logWARNING, error);
	}
    return nullptr;
}

void TextureManager::Destroy() {
	if(this != nullptr){
		this->m_textureMap.clear();
	}
}

void TextureManager::DeleteTexture(const char *name) {
    auto it = this->m_textureMap.find(name);
    if (it != m_textureMap.end())
    {
        const GLuint texture = it->second.GetTextureID();
		Debug::Log(LogLevel::logINFO, static_cast<std::string>("Deleted texture - ") += it->first);
		glDeleteTextures(1,&texture);
		it = this->m_textureMap.erase(it);
    }else
		Debug::Log(LogLevel::logERROR, static_cast<std::string>("Texture doesn't exist - ") += name);
}
