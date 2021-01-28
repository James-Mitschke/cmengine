#ifndef CMENGINE_SOUNDSOURCE_H
#define CMENGINE_SOUNDSOURCE_H

#include "Component.h"
#include "Sound.h"

#include "AL/al.h"
#include "rend/rend.h"

namespace cmengine
{
	struct Sound;

	struct Soundsource : public Component
	{
		void initialize(std::shared_ptr<Sound> sound, rend::vec3 position);
		void onInitialize();
		void tick();
		void onTick();
		void destroy();
		void onDestroy();

		ALuint sid = 0;
	};
}

#endif