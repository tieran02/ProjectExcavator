#pragma once
#include "Asset.h"
#include "../../../libs/include/release/fmod.hpp"
#include "Math/Vector3.h"

class Sound : public Asset
{
public:
	Sound(const char* name, const char* path);
	~Sound() override;

	void Load() override;
	FMOD::Sound* GetSound() const { return sound; }
private:
	void loadSound(const char* path);
	FMOD_RESULT  result;
	FMOD::Sound* sound;
};
