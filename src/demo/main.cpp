#include <cmengine/cmengine.h>

struct Player : public Component
{
	void onInitialize()
	{
		std::shared_ptr<Sound> music = getCore()->getResources()->load<Sound>("Forest");
		
		std::shared_ptr<Soundsource> musicloc = getEntity()->addComponent<Soundsource>();
		std::shared_ptr<Entity> pe = getCore()->addEntity();
		std::shared_ptr<Renderer> r = pe->addComponent<Renderer>();

		pe->getTransform()->setPosition(rend::vec3(0, 0, -10));
		pe->getTransform()->setRotation(rend::vec3(0, 0, 0));

		rend::vec3 position = pe->getTransform()->position;
		musicloc->initialize(music, position);
	}
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> pe = core->addEntity();

	pe->addComponent<Player>();

	//std::shared_ptr<Soundsource> musicloc = pe->getComponent<Player>()->onInitialize();

	core->start();

	return 0;

}
