#include <AL/al.h>
#include <string>
#include <vector>

namespace cmengine
{
	struct Sound
	{
		void onLoad(const std::string& path);
		void loadOgg(const std::string& fileName, std::vector<char>& buffer, ALenum& format, ALsizei& freq);

	private:
		ALuint id;
	};
}
