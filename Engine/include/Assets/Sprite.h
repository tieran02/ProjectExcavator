#pragma once
#include "Asset.h"
#include "Texture2D.h"
#include "Rendering/SpriteRegion.h"

class Sprite : public Asset
{
public:
	/**
	* \brief
	* \param name - name of the sprite in asset table
	* \param textureName - name of the texture to use
	* \param pixlesPerUnit - how many pixles in a single unit (E.G 64 pixles in a single unit)
	*/
	Sprite(const char* name, const char* textureName, float pixlesPerUnit = 100);

	/**
	* \brief
	* \param name - name of the sprite in asset table
	* \param textureName - name of the texture to use
	* \param region - sprite region of the required sprite in a tilesheet
	* \param pixlesPerUnit - how many pixles in a single unit (E.G 64 pixles in a single unit)
	*/
	Sprite(const char* name, const char* textureName, SpriteRegion region, float pixlesPerUnit = 100);
	~Sprite() override;

	void Load() override;

	Texture2D* GetTexture() const;
	void SetTexture(Texture2D* texture);
	float Width() const;
	float Height() const;
	//Pixles Per Unit is the amount of pixles that are in a single unit
	float& PixlesPerUnit() { return m_pixlesPerUnit; }
	//Sprite region for UVs
	SpriteRegion* Region() { return &m_region; }

private:
	Texture2D* m_texture;
	SpriteRegion m_region;
	float m_width, m_height;
	float m_pixlesPerUnit;
};
