#pragma once
#include "Math/Vector2.h"
#include "Math/Rectangle.h"

class SpriteRegion
{
public:
	SpriteRegion(int index, int width, int height);
	SpriteRegion();

	~SpriteRegion(){}

	Vector2* TextureCoords();
private:
	Math::Rectangle m_rect;
	int m_row, m_column, m_width, m_height;
	int m_index;
	Vector2 m_pixles;
	Vector2 m_texCoord[4];

	void calculateRegion();
};
