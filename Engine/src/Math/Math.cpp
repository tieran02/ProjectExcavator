#include <Math/Math.h>
#include <algorithm>

float Math::Clamp01(float value)
{
	return std::max(0.0f, std::min(value, 1.0f));
}

float Math::Clamp(float value, float min, float max)
{
	return std::max(min, std::min(value, max));
}
