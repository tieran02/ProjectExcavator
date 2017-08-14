#pragma once

#include "Texture2D.h"

class Sprite {
public:
    Sprite() = default;
    Sprite(const char* path, const char* name, float width, float height);
    Sprite(const char* name, float width, float height);

    ~Sprite();

    void Load(const char* path, const char* name, float width, float height);
    void Load(const char* name, float width, float height);

    Texture2D* Texture() const{
        return m_texture;
    }

	float Width() const
	{
		return m_width;
	}

	float Height() const
	{
		return m_height;
	}

private:
    Texture2D* m_texture;
    float m_width, m_height;
};
