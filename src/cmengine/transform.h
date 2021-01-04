#include "Component.h"

#include <rend/rend.h>

namespace cmengine
{

	struct Transform : public Component
	{
		void onInitialize();

		rend::mat4 getModel();
		void