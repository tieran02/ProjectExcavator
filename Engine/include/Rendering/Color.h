#pragma once
#include "Math/Vector4.h"

class Color
{
public:
	Color(float r, float g, float b, float a) : R(r), G(g), B(b), A(a){}
	Color(float r, float g, float b) : R(r), G(g), B(b), A(1) {}
	Color() : R(1), G(1), B(1), A(1) {}

	float R, G, B, A;
	Vector4 Vec4() const { return Vector4(R, G, B, A); };
};
