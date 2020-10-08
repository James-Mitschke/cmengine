#include <memory>
#include <vector>

namespace cmengine
{

struct Entity;

struct Core
{
	static std::shared_ptr<Core> initialize();

	std::shared_ptr<Entity> addEntity();

	void start(0;

private:
	std::vector<std::shared_ptr<Entity>> entities;
};

}
