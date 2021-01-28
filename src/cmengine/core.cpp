#include "Core.h"
#include "Entity.h"
#include "Exception.h"
#include "Renderer.h"
#include "Transform.h"
#include "Resources.h"

namespace cmengine
{

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;

		rtn->window = SDL_CreateWindow("cmengine",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			800, 600,
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

			if (!rtn->window)
			{
				throw Exception("Failed to create window");
			}

			rtn->glContext = SDL_GL_CreateContext(rtn->window);

			if (!rtn->glContext)
			{
				throw Exception("Failed to create OpenGL context");
			}

			rtn->ALdevice = alcOpenDevice(NULL);

			if (!rtn->ALdevice)
			{
				throw Exception("Failed to open default device!");
			}

			rtn->ALcontext = alcCreateContext(rtn->ALdevice, NULL);

			if (!rtn->ALcontext)
			{
				alcCloseDevice(rtn->ALdevice);
				throw Exception("Failed to create context!");
			}

			if (!alcMakeContextCurrent(rtn->ALcontext))
			{
				alcDestroyContext(rtn->ALcontext);
				alcCloseDevice(rtn->ALdevice);
				throw Exception("Failed to make context current!");
			}

			glewInit();
			rtn->context = std::make_shared<rend::Context>();
			//rtn->keyboard = std::make_shared<Keyboard>();
			rtn->resources = std::make_shared<Resources>();
			rtn->resources->core = rtn;

		return rtn;
	}


	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
		rtn->core = self;
		rtn->self = rtn;

		entities.push_back(rtn);

		rtn->transform = rtn->addComponent<Transform>();

		return rtn;
	}

	std::shared_ptr<Resources> Core::getResources()
	{
		return resources;
	}

	void Core::start()
	{
		bool running = true;
		SDL_Event e = { 0 };

		while (running)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					running = false;
				}
			}


			for (size_t ei = 0; ei < entities.size(); ei++)
			{
				entities.at(ei)->tick();
			}

			glClearColor(1, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			

			for (size_t ei = 0; ei < entities.size(); ei++)
			{
				entities.at(ei)->render();
			}

			/*
			* 
			* glClear(GL_DEPTH_BUFFER_BIT);
			* glDisable(GL_DEPTH_TEST);
			for (size_t ei = 0; ei < entities.size(); ei++)
			{
				entities.at(ei)->gui();
			}
			* glEnable(GL_DEPTH_TEST);
			*/

			SDL_GL_SwapWindow(window);
		}
	}
}