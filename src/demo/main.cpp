#include <cmengine/cmengine.h>

struct Player : public Component
{
	void onTick()
	{

	}
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> pe = core->addEntity();
	std::shared_ptr<Renderer> r = pe->addComponent<Renderer>();
	pe->getTransform()->setPosition(rend::vec3(0, 0, -10));
	pe->getTransform()->setRotation(rend::vec3(0, 0, 50));
	//pe->getSound()->onLoad(G:\Music\Rise Against - Lanterns.mp3);
	
	//pe->addComponent<Player>();

	core->start();

	return 0;

}
