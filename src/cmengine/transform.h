#include "Component.h"

#include <rend/rend.h>

namespace cmengine
{
	struct Transform : public Component
	{
		void onInitialize();

		/// <summary>
		/// Allows the user to access the model matrix of an entity to redefine how they see fit
		/// </summary>
		/// <returns>A reference to the entity's model matrix</returns>
		rend::mat4 getModel();

		/// <summary>
		/// This variable holds the entity's position and can be modified directly
		/// </summary>
		rend::vec3 position;

		/// <summary>
		/// This variable holds the entity's rotation and can be modified directly
		/// </summary>
		rend::vec3 rotation;

		/// <summary>
		/// This variable holds the entity's scale and can be modified directly
		/// </summary>
		rend::vec3 scale;

		/// <summary>
		/// Allows defining a new position for the entity this is attached to by the user providing a vector containing the new position
		/// </summary>
		void setPosition(rend::vec3 position);

		/// <summary>
		/// Allows defining a new rotation for the entity this is attached to by the user providing a vector containing the new rotation
		/// </summary>
		void setRotation(rend::vec3 rotation);

		/// <summary>
		/// Allows defining a new scale for the entity this is attached to by the user providing a vector containing the new scale 
		/// </summary>
		void setScale(rend::vec3 scale);
	};
}