#include "Resource.h"

namespace cmengine
{
	/// <summary>
	/// This class is a basic resource loading system that gets a reference to core, and also returns file paths
	/// </summary>

	Resource::~Resource() { }
	void Resource::onLoad() { }

	std::string Resource::getPath()
	{
		return path;
	}

	std::shared_ptr<Core> Resource::getCore()
	{
		return core.lock();
	}

}