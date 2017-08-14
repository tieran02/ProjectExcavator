#pragma once

#include "Texture2D.h"
#include <Core/Components/Transform.h>

class Sprite {
public:
    Sprite() = default;
    Sprite(const char* path, const char* name, float width, float height, float depth);
    Sprite(const char* path, const char* name, float width, float height);
    Sprite(const char* name, float width, float height, float depth);
	Sprite(const char* name, float width, float height, float depth, Transform* transform);
    Sprite(const char* name, float width, float height);

    ~Sprite();

    void Load(const char* path, const char* name, float width, float height, float depth);
    void Load(const char* path, const char* name, float width, float height);
	void Load(const char* name, float width, float height, float depth, Transform* transform);
    void Load(const char* name, float width, float height, float depth);
    void Load(const char* name, float width, float height);

	float Depth() const{
        return m_depth;
    }

	Transform* GetTransform() const { return m_transform; }

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
	Transform* m_transform;
    float m_width, m_height;
    float m_depth;
};
