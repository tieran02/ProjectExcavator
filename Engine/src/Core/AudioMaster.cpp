#include <Core/AudioMaster.h>
#include "Debug/Debug.h"

void AudioMaster::Create()
{
	/*
	Create a System object and initialize.
	*/
	result = FMOD::System_Create(&system);
	FMOD_ERRORCHECK(result);

	result = system->getVersion(&version);
	FMOD_ERRORCHECK(result);

	if (version < FMOD_VERSION)
	{
		LOG_ERROR("FMOD lib version %08x doesn't match header version %08x" << version << FMOD_VERSION);
	}

	result = system->init(100, FMOD_INIT_NORMAL, extradriverdata);
	FMOD_ERRORCHECK(result);

	/*
	Set the distance units. (meters/feet etc).
	*/
	result = system->set3DSettings(1.0, DISTANCEFACTOR, 1.0f);
	FMOD_ERRORCHECK(result);
}

void AudioMaster::Destroy()
{
	result = system->close();
	FMOD_ERRORCHECK(result);
	result = system->release();
	FMOD_ERRORCHECK(result);
}
