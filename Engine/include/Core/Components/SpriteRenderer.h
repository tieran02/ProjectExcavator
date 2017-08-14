#pragma once
#include "Component.h"
#include "Rendering/Sprite.h"
#include "Rendering/SpriteBatch.h"

class SpriteRenderer : public Component
{
public:
	SpriteRenderer(SpriteBatch* spriteBatch);

	void Render() override;
	void SetSprite(Sprite* sprite);

private:
	Sprite* m_sprite;
	float m_depth;
	SpriteBatch* m_spriteBatch;
};
