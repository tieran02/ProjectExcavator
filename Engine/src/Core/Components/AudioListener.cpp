#include <Core/Components/AudioListener.h>
#include "Math/Vector3.h"
#include "Core/Game.h"
#include "Core/Components/GameObject.h"
#include "Debug/Debug.h"

void AudioListener::Awake()
{
}

void AudioListener::Update()
{
	Vector3& pos = GetGameObject().GetTransform().GetPosition();
	Vector3& vel = GetGameObject().GetTransform().Velocity();
	this->m_position = { pos.x* Game::Instance()->GetAudioMaster()->DISTANCEFACTOR,pos.y* Game::Instance()->GetAudioMaster()->DISTANCEFACTOR,pos.y* Game::Instance()->GetAudioMaster()->DISTANCEFACTOR };
	this->m_velocity = { vel.x,vel.y,vel.z };

	m_result = Game::Instance()->GetAudioMaster()->System()->set3DListenerAttributes(0, &m_position, &m_velocity, &forward, &up);
	FMOD_ERRORCHECK(m_result);

	m_result = Game::Instance()->GetAudioMaster()->System()->update();
	FMOD_ERRORCHECK(m_result);
}

void AudioListener::Destroy()
{
}
