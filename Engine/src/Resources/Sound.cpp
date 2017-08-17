#include <Resources/Sound.h>
#include "Core/Game.h"
#include "Debug/Debug.h"

Sound::Sound(const char* name, const char* path) : Asset(AssetType::SOUND, name)
{
	loadSound(path);
}

Sound::~Sound()
{
	result = sound->release();
	FMOD_ERRORCHECK(result);
}

void Sound::Load()
{
}

void Sound::loadSound(const char* path)
{
	result = Game::Instance()->GetAudioMaster()->System()->createSound(path, FMOD_3D, 0, &sound);
	FMOD_ERRORCHECK(result);
	result = sound->set3DMinMaxDistance(0.5f * Game::Instance()->GetAudioMaster()->DISTANCEFACTOR, 100 * Game::Instance()->GetAudioMaster()->DISTANCEFACTOR);
	FMOD_ERRORCHECK(result);
	result = sound->setMode(FMOD_LOOP_NORMAL);
	FMOD_ERRORCHECK(result);
}
