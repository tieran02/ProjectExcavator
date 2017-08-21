#pragma once
#include "Component.h"
#include "Rendering/SpriteBatch.h"
#include <Assets/Sprite.h>
#include <Rendering/Color.h>

class SpriteRenderer : public Component
{
public:
	SpriteRenderer(SpriteBatch* spriteBatch);

	void Render() override;
	void SetSprite(Sprite* sprite);
	void SetDepth(float depth);

	Color& GetColor() { return m_color; }
private:
	Sprite* m_sprite;
	float m_depth;
	Color m_color;
	SpriteBatch* m_spriteBatch;
};
