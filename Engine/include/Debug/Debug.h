#pragma once
#include <string>

enum LogLevel
{
	logERROR, logWARNING, logINFO
};

class Debug
{
public:
	static void Log(LogLevel level, std::string data);
};