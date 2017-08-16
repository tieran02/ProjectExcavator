#pragma once
#include "Component.h"
#include <fmod.h>

class AudioListener : public Component
{
public:
	AudioListener() : Component("AudioListener"), m_result(){}

	void Awake() override;
	void Update() override;
	void Destroy() override;
private:
	FMOD_RESULT	m_result;
	FMOD_VECTOR m_position;
	FMOD_VECTOR m_velocity;
	FMOD_VECTOR forward = { 0.0f, 0.0f, 1.0f };
	FMOD_VECTOR up = { 0.0f, 1.0f, 0.0f };

};
