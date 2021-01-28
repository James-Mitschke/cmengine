#include "Component.h"
#include "Entity.h"

namespace cmengine
{
	/// <summary>
	/// This tells any components that call tick to utilise the ontick function
	/// </summary>
	void Component::tick()
	{
		onTick();
	}

	/// <summary>
	/// This tells any components that call render to utilise the onrender function
	/// </summary>
	void Component::render()
	{
		onRender();
	}

	/// <summary>
	/// Provides a template for other classes using an initialize function
	/// </summary>
	void Component::onInitialize() { }

	/// <summary>
	/// Provides a template for other classes using an update function
	/// </summary>
	void Component::onTick() { }

	/// <summary>
	/// Provides a template for any classes that need a render function
	/// </summary>
	void Component::onRender() { }

	/// <summary>
	/// Gets entity and returns it
	/// </summary>
	/// <returns>A reference to entity</returns>
	std::shared_ptr<Entity> Component::getEntity()
	{
		return entity.lock();
	}

	/// <summary>
	/// Gets core through entity and returns it 
	/// </summary>
	/// <returns>A reference to core</returns>
	std::shared_ptr<Core> Component::getCore()
	{
		return getEntity()->getCore();
	}

}