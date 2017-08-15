#pragma once
#include "Asset.h"
#include <glad/glad.h>

class TextureAsset : public Asset
{
public:
	TextureAsset(const char* name, const char* path);
	~TextureAsset() override;

	void Bind() const;
	void Unbind() const;
	GLuint GetTextureID() const { return m_texture_ID; }
private:
	int m_width, m_height, m_nrChannels;
	GLuint m_texture_ID;

	void createTexture(const char*);
};
