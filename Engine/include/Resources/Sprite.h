#pragma once
#include "Asset.h"
#include "Texture2D.h"
#include "Rendering/SpriteRegion.h"

class Sprite : public Asset
{
public:
	Sprite(const char* name, const char* textureName, float width, float height, float pixlesPerUnit = 100);
	Sprite(const char* name, const char* textureName, float row, float column,float width, float height, Vector2 pixles, float pixlesPerUnit = 100);
	~Sprite() override;

	void Load() override;

	Texture2D* GetTexture() const;
	void SetTexture(Texture2D* texture);
	float Width() const;
	float Height() const;
	float& PixlesPerUnit() { return m_pixlesPerUnit; }
	SpriteRegion* Region() { return &m_region; }

private:
	Texture2D* m_texture;
	SpriteRegion m_region;
	float m_width, m_height;
	float m_pixlesPerUnit;
};
