#include <Core/Components/SpriteAnimator.h>
#include "Core/Time.h"
#include <Core/Components/GameObject.h>

SpriteAnimator::SpriteAnimator(Animation* animation, float fps) : m_animation(animation), m_sprite_renderer(nullptr), m_tick(0), m_speed(fps), m_currentIndex(animation->Start()), m_spriteIndex(0)
{
}

SpriteAnimator::SpriteAnimator(): m_animation(nullptr), m_sprite_renderer(nullptr), m_tick(0), m_speed(0), m_currentIndex(0), m_spriteIndex(0)
{
}

void SpriteAnimator::Awake()
{
	this->m_sprite_renderer = GetGameObject().FindComponentByType<SpriteRenderer>();
}

void SpriteAnimator::Update()
{
	if(this->m_animation != nullptr)
	{
		this->m_tick += Time::DeltaTime;

		if(this->m_tick >= 1.0f / this->m_speed)
		{
			if (this->m_currentIndex != this->m_animation->End()) 
			{
				this->m_currentIndex++;
				this->m_spriteIndex++;
			}
			else 
			{
				this->m_currentIndex = this->m_animation->Start();
				this->m_spriteIndex = 0;
			}

			this->m_sprite_renderer->SetSprite(this->m_animation->Sprites()[this->m_spriteIndex]);

			this->m_tick = 0;
		}
	}
}

void SpriteAnimator::SetAnimation(Animation* animation)
{
	this->m_animation = animation;
	this->m_currentIndex = animation->Start();

}
