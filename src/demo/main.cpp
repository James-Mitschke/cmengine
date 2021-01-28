#include <cmengine/cmengine.h>

struct Player : public Component
{
	/// <summary>
	/// Initializes the entity system, attaches a sound, a renderer and a sound source. Then sets the position of the shape and rotation of the shape contained in the renderer.
	/// Also this starts the sound (Which is currently some forest sounds) playing .
	/// </summary>
	void onInitialize()
	{
		std::shared_ptr<Sound> music = getCore()->getResources()->load<Sound>("Forest");
		
		std::shared_ptr<Soundsource> musicloc = getEntity()->addComponent<Soundsource>();
		std::shared_ptr<Entity> pe = getCore()->addEntity();
		std::shared_ptr<Renderer> r = pe->addComponent<Renderer>();

		pe->getTransform()->setPosition(rend::vec3(0, 0, -10));
		pe->getTransform()->setRotation(rend::vec3(0, 0, 50));

		rend::vec3 position = pe->getTransform()->position;
		musicloc->initialize(music, position);
	}
};

/// <summary>
/// The main program that causes everything else to run, by initializing core, adding the entity system and then adding the "Player" entity onto that system before finally starting the program.
/// </summary>
/// <returns>Nothing, this program ends when the red cross in the top right of the window is closed</returns>
int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> pe = core->addEntity();

	pe->addComponent<Player>();

	core->start();

	return 0;

}
