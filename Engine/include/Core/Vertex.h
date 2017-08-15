#pragma once

#include <Math/Vector2.h>
#include <Math/Vector3.h>

struct Vertex{
	Vertex() = default;
    Vertex(Vector3 vertex, Vector2 uv, Vector4 color) : Pos(vertex), UV(uv), Color(color){}
    Vector3 Pos;
    Vector2 UV;
	Vector4 Color;
};
