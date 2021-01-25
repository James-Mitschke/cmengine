#include "Component.h"

#include <rend/rend.h>

namespace cmengine
{
	struct Transform : public Component
	{
		void onInitialize();

		rend::mat4 getModel();
		rend::vec3 position;
		rend::vec3 rotation;
		rend::vec3 scale;

		void setPosition(rend::vec3 position);
		void setRotation(rend::vec3 rotation);
		void setScale(rend::vec3 scale);
	};
}