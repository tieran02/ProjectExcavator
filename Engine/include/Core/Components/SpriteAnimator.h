#pragma once
#include "Component.h"
#include "Assets/Animation.h"
#include "SpriteRenderer.h"

class SpriteAnimator : public Component
{
public:
	SpriteAnimator(Animation* animation, float fps);
	SpriteAnimator();

	void Awake() override;
	void Update() override;
	void SetAnimation(Animation* animation);
	void SetFPS(float fps) { m_speed = fps; }

private:
	Animation* m_animation;
	SpriteRenderer* m_sprite_renderer;
	double m_tick;
	float m_speed;
	int m_currentIndex;
	int m_spriteIndex;
};
