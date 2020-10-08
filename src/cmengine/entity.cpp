#include "Entity.h"

using namespace myengine
{

void Entity::tick()
{
	for(size_t ci = 0; ci < components_size(); ci++)
	{
		//components.at(ci)->tick();
	}
};

}