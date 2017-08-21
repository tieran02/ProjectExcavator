#pragma once
#include "Component.h"
#include "Assets/Sound.h"

class AudioSource : public Component
{
public:
	AudioSource(const char* name);
	AudioSource();

	void Awake() override;
	void Update() override;
	void Destroy() override;
	void SetSource(const char* name);
	void SetSource(Sound* sound);
	void Play();
	void Stop();

	Sound* GetSound() const { return m_sound; }

private:
	FMOD_RESULT	m_result;
	Sound* m_sound;
	FMOD::Channel* m_channel;
	FMOD_VECTOR m_position;
	FMOD_VECTOR m_velocity;
	bool m_paused;
};
