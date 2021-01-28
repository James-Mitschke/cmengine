#include "Soundsource.h"


namespace cmengine
{
	void Soundsource::initialize(std::shared_ptr<Sound> sound, rend::vec3 position)
	{
		alGenSources(1, &sid);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sid, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcei(sid, AL_BUFFER, sound->id);
		alSourcePlay(sid);
	}

	void Soundsource::onInitialize()
	{
		
	}

	void Soundsource::tick()
	{
		onTick();
	}

	void Soundsource::destroy()
	{
		onDestroy();
	}

	void Soundsource::onTick()
	{
		ALint state = 0;

		alGetSourcei(sid, AL_SOURCE_STATE, &state);
		
		if (state == AL_STOPPED)
		{
			destroy();
		}
	}

	void Soundsource::onDestroy()
	{
		alDeleteSources(1, &sid);
	}
}