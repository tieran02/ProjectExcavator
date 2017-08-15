#pragma once
#include "Asset.h"
#include <glad/glad.h>

class Texture2D : public Asset
{
public:
	Texture2D(const char* name, const char* path);
	~Texture2D() override;

	void Bind() const;
	void Unbind() const;
	GLuint GetTextureID() const { return m_texture_ID; }
private:
	int m_width, m_height, m_nrChannels;
	GLuint m_texture_ID;

	void createTexture(const char*);
};
