#pragma once
#include "Resources/TextureAsset.h"

class Sprite {
public:
    Sprite() = default;
    Sprite(const char* name, float width, float height);

    ~Sprite();

    void Load(const char* name, float width, float height);

    TextureAsset* Texture() const{
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
	TextureAsset* m_texture;
    float m_width, m_height;
};
