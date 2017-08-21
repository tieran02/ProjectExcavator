#pragma once
#include "Math/Vector2.h"
#include "Math/Rectangle.h"

class SpriteRegion
{
public:
	/**
	 * \brief 
	 * \param index - sprite index of tilesheet (0 is bottom left)
	 * \param rows - how many rows in tilesheet
	 * \param columns - how many columns in tilesheet
	 */
	SpriteRegion(int index, int rows, int columns);
	SpriteRegion();

	~SpriteRegion(){}

	Vector2* TextureCoords();
	const int& Rows() const { return m_rows; }
	const int& Columns() const { return m_columns; }
private:
	Math::Rectangle m_rect;
	int m_rows, m_columns;
	int m_index;
	Vector2 m_texCoord[4];

	void calculateRegion();
};
