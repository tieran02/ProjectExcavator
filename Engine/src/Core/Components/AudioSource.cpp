#include <Core/Components/AudioSource.h>
#include "Resources/AssetManager.h"
#include "Core/Components/GameObject.h"
#include "Core/Game.h"
#include "Debug/Debug.h"

AudioSource::AudioSource(const char* name) : Component("AudioSource"), m_result(), m_sound(nullptr), m_channel(nullptr), m_paused(true)
{
	this->m_sound = static_cast<Sound*>(AssetManager::Instance()->Get(name));
}

AudioSource::AudioSource() : Component("AudioSource"), m_result(), m_sound(nullptr), m_channel(nullptr), m_paused(true)
{
}

void AudioSource::Awake()
{

}

void AudioSource::Update()
{
	if (!this->m_paused) {
		Vector3& pos = GetGameObject().GetTransform().GetPosition();
		Vector3& vel = GetGameObject().GetTransform().Velocity();
		this->m_position = { pos.x* Game::Instance()->GetAudioMaster()->DISTANCEFACTOR,pos.y* Game::Instance()->GetAudioMaster()->DISTANCEFACTOR,pos.y* Game::Instance()->GetAudioMaster()->DISTANCEFACTOR };
		this->m_velocity = { vel.x,vel.y,vel.z };
		m_result = m_channel->set3DAttributes(&m_position, &m_velocity);
		FMOD_ERRORCHECK(m_result);
	}
}

void AudioSource::Destroy()
{
}

void AudioSource::SetSource(const char* name)
{
	this->m_sound = static_cast<Sound*>(AssetManager::Instance()->Get(name));
}

void AudioSource::SetSource(Sound* sound)
{
	this->m_sound = sound;
}

void AudioSource::Play()
{
	if (m_paused) {
		m_result = Game::Instance()->GetAudioMaster()->System()->playSound(m_sound->GetSound(), 0, true, &m_channel);
		FMOD_ERRORCHECK(m_result);
		m_result = m_channel->set3DAttributes(&m_position, &m_velocity);
		FMOD_ERRORCHECK(m_result);
		m_result = m_channel->set3DMinMaxDistance(.5f, 5000.0f);
		FMOD_ERRORCHECK(m_result);
		m_result = m_channel->setPaused(!m_paused);
		FMOD_ERRORCHECK(m_result);
		m_paused = false;
	}
}

void AudioSource::Stop()
{
	if (!m_paused) {
		m_result = m_channel->setPaused(!m_paused);
		FMOD_ERRORCHECK(m_result);
		m_paused = true;
	}
}
