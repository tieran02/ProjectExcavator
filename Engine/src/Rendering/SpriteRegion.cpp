#include <Rendering/SpriteRegion.h>
#include "Debug/Debug.h"
#include "Math/Math.h"

SpriteRegion::SpriteRegion(float row, float column, float width, float height, Vector2 pixles): m_rect(0, 0, 0, 0), m_row(row), m_column(column), m_width(width), m_height(height), m_pixles(pixles)
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
	float numRows = this->m_width / this->m_pixles.x;
	float numColumns = this->m_height / this->m_pixles.y;

	//Check if region is within sprite sheet
	if (this->m_row < numRows && this->m_column < numColumns)
	{
		float x = this->m_row * this->m_pixles.x;
		float y = this->m_column * this->m_pixles.y;
		this->m_rect = Math::Rectangle(x, y, m_pixles.x, m_pixles.y);
	}
	else
	{
		//if out of bounds return first region
		LOG_WARNING("Sprite Region Out of Bounds!");
		this->m_rect = Math::Rectangle(0, 0, m_pixles.x, m_pixles.y);
	}

	//Calculate Tex coords
	this->m_texCoord[0] = Vector2(Math::Clamp01((m_rect.TopLeft().x +0.5f) / this->m_width), Math::Clamp01((m_rect.TopLeft().y + 0.5f) / this->m_height)); // Top Left
	this->m_texCoord[1] = Vector2(Math::Clamp01((m_rect.TopRight().x + 0.5f) / this->m_width), Math::Clamp01((m_rect.TopRight().y + 0.5f) / this->m_height));	//Top Right
	this->m_texCoord[2] = Vector2(Math::Clamp01((m_rect.BottomRight().x + 0.5f) / this->m_width), Math::Clamp01((m_rect.BottomRight().y + 0.5f) / this->m_height));	//Bottom Right
	this->m_texCoord[3] = Vector2(Math::Clamp01((m_rect.BottomLeft().x + 0.5f) / this->m_width), Math::Clamp01((m_rect.BottomLeft().y + 0.5f) / this->m_height)); //Bottom Left
}
