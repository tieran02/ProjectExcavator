#include <Core/Components/SpriteRenderer.h>
#include "Core/Components/GameObject.h"
#include "Core/Components/Camera.h"
#include "Core/Scene_Management/SceneManager.h"

SpriteRenderer::SpriteRenderer( Sprite* sprite) : Component("SpriteRenderer", true), m_depth(-1), m_color(255, 255, 255, 255)
{
	this->m_spriteBatch = SceneManager::Instance()->GetCurrentScene().GetSpriteBatch();
	this->m_sprite = sprite;
}

SpriteRenderer::SpriteRenderer() : Component("SpriteRenderer", true), m_depth(-1), m_color(255,255,255,255)
{
	this->m_spriteBatch = SceneManager::Instance()->GetCurrentScene().GetSpriteBatch();
}

void SpriteRenderer::Render()
{
	if (this->m_sprite != nullptr)
	{
		Vector3 pos = GetGameObject().GetTransform().GetPosition();
		Math::Rectangle bounds = Math::Rectangle(pos.x, pos.y, 1, 1);
		Math::Rectangle cam = Camera::MainCamera->WorldBounds();
		
		if(cam.Overlap(bounds))
			this->m_spriteBatch->Draw(m_sprite, m_depth, &GetGameObject().GetTransform(), m_color);
	}
}

void SpriteRenderer::SetSprite(Sprite* sprite)
{
	this->m_sprite = sprite;
}

void SpriteRenderer::SetDepth(float depth)
{
	this->m_depth = depth;
}
