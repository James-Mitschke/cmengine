#include <cmengine/cmengine.h>

struct Player : public Component
{
	void onTick()
	{
		/* if(getCore()->getKeyboard()->getKey("d"))
		{
			std::cout << "Moving Right!" << std::endl;
		} */
	}
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> pe = core->addEntity();
	//std::shared_ptr<Renderer> r = pe->addComponent<Renderer>();
	//r->getTransform()->setPosition(rend::vec3(0, 0, -10));
	
	pe->addComponent<Player>();

	core->start();

	return 0;
}
