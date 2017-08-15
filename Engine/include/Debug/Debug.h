#pragma once
#include <iostream>

#define LOG_ERROR(x) do { std::cerr << "ERROR::" << x << std::endl; } while (0)
#define LOG_WARNING(x) do { std::cerr << "WARNING::" << x << std::endl; } while (0)
#define LOG_INFO(x) do { std::cout << "INFO::" << x << std::endl; } while (0)