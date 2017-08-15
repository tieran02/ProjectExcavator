#include <Resources/TextureAsset.h>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include "Debug/Debug.h"

TextureAsset::TextureAsset(const char* name, const char* path): Asset(AssetType::TEXTURE, name)
{
	createTexture(path);
}

TextureAsset::~TextureAsset()
{
	glDeleteTextures(1, &this->m_texture_ID);
	LOG_INFO("Texture '" << this->GetName() << "' Deleted");
}

void TextureAsset::Bind() const
{
	glBindTexture(GL_TEXTURE_2D, this->m_texture_ID);
}

void TextureAsset::Unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void TextureAsset::createTexture(const char* path)
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
