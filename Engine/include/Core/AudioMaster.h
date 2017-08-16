#pragma once
#include "fmod.hpp"

class AudioMaster
{
public:
	const float		DISTANCEFACTOR = 1.0f;          // Units per meter.  I.e feet would = 3.28.  centimeters would = 100.

	AudioMaster() = default;
	~AudioMaster() { Destroy(); }

	void Create();
	void Destroy();

	FMOD::System* System() const { return system; }
private:
	FMOD::System	*system;
	FMOD::Channel	*channel1 = 0, *channel2 = 0, *channel3 = 0;
	FMOD_RESULT		result;
	unsigned int    version;
	void            *extradriverdata = 0;
};