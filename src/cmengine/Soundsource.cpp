#include "Soundsource.h"


namespace cmengine
{

	/// <summary>
	/// Takes in a sound that has been defined, and then the position of the entity the sound is being attached to
	/// </summary>
	void Soundsource::initialize(std::shared_ptr<Sound> sound, rend::vec3 position)
	{
		alGenSources(1, &sid);
		alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSource3f(sid, AL_POSITION, position.x, position.y, position.z);
		alSourcei(sid, AL_BUFFER, sound->id);
		alSourcePlay(sid);
	}

	/// <summary>
	/// Provides an empty onInitialize for compatibility reasons
	/// </summary>
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

	/// <summary>
	/// Provides a function that waits for a sound to be stopped before calling destroy function
	/// </summary>
	void Soundsource::onTick()
	{
		ALint state = 0;

		alGetSourcei(sid, AL_SOURCE_STATE, &state);
		
		if (state == AL_STOPPED)
		{
			destroy();
		}
	}

	/// <summary>
	/// Destroys the sound source from the entity to prevent memory leaking
	/// </summary>
	void Soundsource::onDestroy()
	{
		alDeleteSources(1, &sid);
	}
}