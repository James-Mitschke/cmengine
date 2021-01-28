#ifndef CMENGINE_RESOURCE_H
#define CMENGINE_RESOURCE_H

#include <string>
#include <memory>

namespace cmengine
{

	struct Core;
	struct Resources;

	struct Resource
	{
		virtual ~Resource();
		virtual void onLoad();
		//virtual void onCreate();

		std::string getPath();
		std::shared_ptr<Core> getCore();

	private:
		friend struct cmengine::Resources;

		std::string path;
		std::weak_ptr<Core> core;

	};

}

#endif