#pragma once

#include <glad/glad.h>

class Texture2D {
public:
    Texture2D(){};
	Texture2D(const char* directory);
    ~Texture2D(){};
    void Bind();
    void Unbind();
    void CreateTextureFromFile(const char* directory);
	int GetTextureID() const { return m_texture_ID;}

private:
    int m_width, m_height, m_nrChannels;
    GLuint m_texture_ID;;
};