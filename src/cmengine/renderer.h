#include "Component.h"

#include <rend/rend.h>
#include <AL/al.h>
#include <AL/alc.h>

#include <memory>

namespace cmengine
{
	struct Renderer : public Component
	{
		void onInitialize();
		void onRender();

	private:
		std::shared_ptr<rend::Shader> shader;
		std::shared_ptr<rend::Buffer> shape;
	};
}