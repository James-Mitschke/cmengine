#include "Sound.h"
#include "stb_vorbis.h"
#include "Exception.h"


namespace cmengine
{
	/// <summary>
	/// Provides functionality for the user to load custom vorbis encoded .ogg files for usage from the game engine
	/// </summary>
	void Sound::onLoad()
	{
		alGenBuffers(1, &id);

		ALenum format = 0;
		ALsizei freq = 0;
		std::vector<char> bufferData;
		loadOgg(getPath() + ".ogg", bufferData, format, freq);

		alBufferData(id, format, &bufferData.at(0), static_cast<ALsizei>(bufferData.size()), freq);
	}

	/// <summary>
	/// Takes in parameters defined in onLoad to seperate the sound file into a readable format for the game engine so that it's ready to output when called by a soundsource
	/// </summary>
	void Sound::loadOgg(const std::string& fileName, std::vector<char> &buffer, ALenum &format, ALsizei &freq)
	{
		int channels = 0;
		int sampleRate = 0;

		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(fileName.c_str(), &channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw Exception("Failed to open file '" + fileName + "'");
		}

		// Record the format required by OpenAL
		if (channels == 1)
		{
			format = AL_FORMAT_MONO16;
		}

		else
		{
			format = AL_FORMAT_STEREO16;
		}

		// Record the sample rate required by OpenAL
		freq = sampleRate;
		buffer.resize(samples * 2);

		memcpy(&buffer.at(0), output, buffer.size());

		// Clean up the read data
		free(output);
	}
}