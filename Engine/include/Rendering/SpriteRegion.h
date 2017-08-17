#pragma once
#include "Math/Vector2.h"
#include "Math/Rectangle.h"

class SpriteRegion
{
public:
	SpriteRegion(float row, float column, float width, float height, Vector2 pixles);
	SpriteRegion();

	~SpriteRegion(){}

	Vector2* TextureCoords();
private:
	Math::Rectangle m_rect;
	float m_row, m_column, m_width, m_height;
	Vector2 m_pixles;
	Vector2 m_texCoord[4];

	void calculateRegion();
};
