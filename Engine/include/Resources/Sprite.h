#pragma once
#include "Asset.h"
#include "Texture2D.h"

class Sprite : public Asset
{
public:
	Sprite(const char* name, const char* textureName, float width, float height);
	~Sprite() override;

	void Load() override;

	Texture2D* GetTexture() const;
	void SetTexture(Texture2D* texture);
	float Width() const;
	float Height() const;

private:
	Texture2D* m_texture;
	float m_width, m_height;
};
