#include <cmengine/cmengine.h>

struct Player : public Component
{
	int dummy;
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> pe = core->addEntity();
	std::shared_ptr<Player> pc = pe->addComponent<Player>();

	core->Start;

	return 0;
};
