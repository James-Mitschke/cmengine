#ifndef CMENGINE_SOUND_H
#define CMENGINE_SOUND_H

#include "Resource.h"
#include <AL/al.h>
#include <string>
#include <vector>

namespace cmengine
{
	struct Soundsource;

	struct Sound : public Resource
	{
		friend struct cmengine::Soundsource;

		void onLoad();
		void loadOgg(const std::string& fileName, std::vector<char>& buffer, ALenum& format, ALsizei& freq);

		ALuint id = 0;
	};
}

#endif