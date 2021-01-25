#include <SDL2/SDL.h>
#include <rend/rend.h>
#include <AL/al.h>
#include <AL/alc.h>

#include <memory>
#include <vector>

namespace cmengine
{

	struct Renderer;
	struct Entity;
	//struct Keyboard;

	struct Core
{
		friend struct cmengine::Renderer;

		static std::shared_ptr<Core> initialize();

		std::shared_ptr<Entity> addEntity();
		//std::shared_ptr<Keyboard> addKeyboard();

		void start();

	private:
		std::vector<std::shared_ptr<Entity>> entities;
		std::weak_ptr<Core> self;
		SDL_Window* window;
		SDL_GLContext glContext;
		ALCdevice* ALdevice;
		ALCcontext* ALcontext;
		std::shared_ptr<rend::Context> context;
		//std::shared_ptr<Keyboard> keyboard; 
	};

}
