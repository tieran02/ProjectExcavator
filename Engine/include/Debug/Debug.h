#pragma once
#include <iostream>
#include <fmod.h>

#define LOG_ERROR(x) do { std::cerr << "ERROR::" << x << std::endl; } while (0)
#define LOG_WARNING(x) do { std::cerr << "WARNING::" << x << std::endl; } while (0)
#define LOG_INFO(x) do { std::cout << "INFO::" << x << std::endl; } while (0)

void FMOD_ERRORCHECK_fn(FMOD_RESULT result, const char *file, int line);
#define FMOD_ERRORCHECK(_result) FMOD_ERRORCHECK_fn(_result, __FILE__, __LINE__)

