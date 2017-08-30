#pragma once
#include "Asset.h"
#include <glad/glad.h>

class Texture2D : public Asset
{
public:
	Texture2D(const char* name, const char* path, bool alpha);
	~Texture2D() override;

	void Bind() const;
	void Unbind() const;
	GLuint GetTextureID() const { return m_texture_ID; }
	const int& Height() const { return m_height; }
	const int&  Width() const { return m_width; }
private:
	int m_width, m_height, m_nrChannels;
	GLuint m_texture_ID;

	void createTexture(const char* path, bool alpha);
};
