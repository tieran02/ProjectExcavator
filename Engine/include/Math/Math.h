#pragma once

#define M_PI		3.14159265358979323846  /* pi */
#define M_GRAVITY   6.6742

#include <algorithm>
#include <Math/Matrix3.h>
#include <Math/Matrix4.h>
#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Math/Vector4.h>
#include <Math/Radians.h>
#include <Math/Quaternion.h>

namespace Math
{
	template <class T>
	T Clamp01(const T& value)
	{
		return std::max(0.0f, std::min(value, 1.0f));
	}

	template <class T>
	T Clamp(const T& value, const T& min, const T& max)
	{
		return std::max(min, std::min(value, max));
	}

	template <class T>
	T MapValue(const T& value, const T& min, const T& max)
	{
		return (value - min) / (max - min);
	}

	template <class T>
	T Normalize(const T& value, const T& max)
	{
		return (value / max);
	}
};
