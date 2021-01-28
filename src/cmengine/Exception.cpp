#include "Exception.h"

namespace cmengine
{
	/// <summary>
	/// This class acts as a way of implementing a custom exception for errors/bugs in the game engine
	/// </summary>
	Exception::Exception(const std::string& message)
	{
		this->message = message;
	}

	Exception::~Exception() throw() { }

	const char* Exception::what() const throw()
	{
		return message.c_str();
	}
}
