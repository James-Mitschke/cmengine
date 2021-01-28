#include "Entity.h"
#include "Component.h"

namespace cmengine
{
	/// <summary>
	/// Provides a tick function for all entities
	/// </summary>
	void Entity::tick()
	{
		for(size_t ci = 0; ci < components.size(); ci++)
		{
			components.at(ci)->tick();
		}
	}

	/// <summary>
	/// Provides a render function for all entities
	/// </summary>
	void Entity::render()
	{
		for (size_t ci = 0; ci < components.size(); ci++)
		{
			components.at(ci)->render();
		}
	}

	/// <summary>
	/// Provides a reference to the core via the entity
	/// </summary>
	/// <returns>A reference to core</returns>
	std::shared_ptr<Core> Entity::getCore()
	{
		return core.lock();
	}

	/// <summary>
	///	Provides a reference to an entity's transform properties
	/// </summary>
	/// <returns>A reference to an entity's transform properties</returns>
	std::shared_ptr<Transform> Entity::getTransform()
	{
		return transform.lock();
	}

	/// <summary>
	/// Provides a reference to an entity's soundsource
	/// </summary>
	/// <returns>A reference to an entity's soundsource</returns>
	std::shared_ptr<Soundsource> Entity::getSoundsource()
	{
		return soundsource.lock();
	}
}