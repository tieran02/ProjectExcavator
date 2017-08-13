#pragma once

#define M_PI		3.14159265358979323846  /* pi */

#include <Math/Matrix3.h>
#include <Math/Matrix4.h>
#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Math/Vector4.h>
#include <Math/Radians.h>
#include <Math/Quaternion.h>
#include <algorithm>

inline float Clamp01(float value)
{
	return std::max(0.0f, std::min(value, 1.0f));
}

inline float Clamp(float value, float min, float max)
{
	return std::max(min, std::min(value, max));
}

