
#include <iostream>
#include "Rendering/Texture2D.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Texture2D::Texture2D(const char* directory)
{
	CreateTextureFromFile(directory);
}

Texture2D::~Texture2D()
{
	glDeleteTextures(1, &this->m_texture_ID);
}

void Texture2D::Bind()
{
    glBindTexture(GL_TEXTURE_2D, this->m_texture_ID);
}

void Texture2D::Unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::CreateTextureFromFile(const char* path)
{
	//Generate texture ID and load texture data
	glGenTextures(1, &this->m_texture_ID);
	stbi_set_flip_vertically_on_load(true);
	unsigned char* image = stbi_load(path, &this->m_width, &this->m_height, &this->m_nrChannels, 0);
	// Assign texture to ID
	glBindTexture(GL_TEXTURE_2D, this->m_texture_ID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(image);
}
