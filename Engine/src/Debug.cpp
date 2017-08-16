#include <Debug/Debug.h>
#include "fmod_errors.h"


void(*Common_Private_Error)(FMOD_RESULT, const char *, int);

void FMOD_ERRORCHECK_fn(FMOD_RESULT result, const char* file, int line)
{
	if (result != FMOD_OK)
	{
		if (Common_Private_Error)
		{
			Common_Private_Error(result, file, line);
		}
		LOG_ERROR(FMOD_ErrorString(result) << " " << file << " " << line);
	}
}
