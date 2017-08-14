#include <Debug/Debug.h>
#include <iostream>

void Debug::Log(LogLevel level, std::string data)
{
	switch (level)
	{
	case LogLevel::logERROR:
		std::cerr << "ERROR:: " << data << std::endl;
		break;
	case LogLevel::logWARNING:
		std::cout << "WARNING:: " << data << std::endl;
		break;
	case LogLevel::logINFO:
		std::cout << "INFO:: " << data << std::endl;
		break;
	}
}
