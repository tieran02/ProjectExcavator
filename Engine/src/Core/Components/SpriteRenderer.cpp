#include <Core/Components/SpriteRenderer.h>
#include "Core/Components/GameObject.h"

SpriteRenderer::SpriteRenderer(SpriteBatch* spriteBatch) : Component("SpriteRenderer", true), m_depth(-1), m_color(1,1,1,1)
{
	this->m_spriteBatch = spriteBatch;
}

void SpriteRenderer::Render()
{
	if(this->m_sprite != nullptr)
		this->m_spriteBatch->Draw(m_sprite, m_depth, &GetGameObject().GetTransform(), m_color);
}

void SpriteRenderer::SetSprite(Sprite* sprite)
{
	this->m_sprite = sprite;
}
