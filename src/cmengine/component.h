#ifndef CMENGINE_COMPONENT_H
#define CMENGINE_COMPONENT_H

#include <memory>

namespace cmengine
{
	struct Entity;
	struct Core;

	struct Component
	{
		friend struct cmengine::Entity;

		virtual void onInitialize();

		void tick();
		virtual void onTick();

		void render();
		virtual void onRender();

		std::shared_ptr<Entity> getEntity();
		std::shared_ptr<Core> getCore();

	private:
		std::weak_ptr<Entity> entity;
	};
}

#endif