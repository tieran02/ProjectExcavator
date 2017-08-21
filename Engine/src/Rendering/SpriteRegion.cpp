#include <Rendering/SpriteRegion.h>
#include "Debug/Debug.h"
#include "Math/Math.h"

SpriteRegion::SpriteRegion(int index, int width, int height): m_rect(0, 0, 0, 0), m_width(width), m_height(height), m_index(index)
{
	calculateRegion();
}

SpriteRegion::SpriteRegion(): m_row(0), m_column(0), m_width(0), m_height(0)
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

	int x = this->m_index % m_width;
	int y = this->m_index / m_height;

	this->m_rect = Math::Rectangle(x/ (float)m_width, y / (float)m_height, 1.0f / m_width, 1.0f / m_height);



	//Calculate Tex coords
	this->m_texCoord[0] = Vector2(Math::Clamp01((m_rect.TopLeft().x ) ), Math::Clamp01((m_rect.TopLeft().y ))); // Top Left
	this->m_texCoord[1] = Vector2(Math::Clamp01((m_rect.TopRight().x ) ), Math::Clamp01((m_rect.TopRight().y )));	//Top Right
	this->m_texCoord[2] = Vector2(Math::Clamp01((m_rect.BottomRight().x ) ), Math::Clamp01((m_rect.BottomRight().y )));	//Bottom Right
	this->m_texCoord[3] = Vector2(Math::Clamp01((m_rect.BottomLeft().x ) ), Math::Clamp01((m_rect.BottomLeft().y ))); //Bottom Left
}
