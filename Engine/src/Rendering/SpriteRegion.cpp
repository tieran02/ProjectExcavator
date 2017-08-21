#include <Rendering/SpriteRegion.h>
#include "Debug/Debug.h"
#include "Math/Math.h"

SpriteRegion::SpriteRegion(int index, int rows, int columns): m_rect(0, 0, 0, 0), m_rows(rows), m_columns(columns), m_index(index)
{
	calculateRegion();
}

SpriteRegion::SpriteRegion(): m_rows(0), m_columns(0)
{
	this->m_texCoord[0] = Vector2(0.0f, 1.0f); // Top Left
	this->m_texCoord[1] = Vector2(1.0f, 1.0f);	//Top Right
	this->m_texCoord[2] = Vector2(1.0f, 0.0f);	//Bottom Right
	this->m_texCoord[3] = Vector2(0.0f, 0.0f); //Bottom Left
}

Vector2* SpriteRegion::TextureCoords()
{
	return this->m_texCoord;
}

void SpriteRegion::calculateRegion()
{

	int x = this->m_index % m_rows;
	int y = this->m_index / m_rows;

	this->m_rect = Math::Rectangle(x/ (float)m_rows, y / (float)m_columns, 1.0f / m_rows, 1.0f / m_columns);



	//Calculate Tex coords
	this->m_texCoord[0] = Vector2(Math::Clamp01((m_rect.TopLeft().x ) ), Math::Clamp01((m_rect.TopLeft().y ))); // Top Left
	this->m_texCoord[1] = Vector2(Math::Clamp01((m_rect.TopRight().x ) ), Math::Clamp01((m_rect.TopRight().y )));	//Top Right
	this->m_texCoord[2] = Vector2(Math::Clamp01((m_rect.BottomRight().x ) ), Math::Clamp01((m_rect.BottomRight().y )));	//Bottom Right
	this->m_texCoord[3] = Vector2(Math::Clamp01((m_rect.BottomLeft().x ) ), Math::Clamp01((m_rect.BottomLeft().y ))); //Bottom Left
}
