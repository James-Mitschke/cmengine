#ifndef CMENGINE_EXCEPTION_H
#define CMENGINE_EXCEPTION_H

#include <exception>
#include <string>

namespace cmengine
{

	struct Exception : public std::exception
	{
		Exception(const std::string& message);
		virtual ~Exception() throw();
		virtual const char* what() const throw();

	private:
		std::string message;

	};
}

#endif