#pragma once

#include <Math/Vector2.h>
#include <Math/Vector3.h>

struct Vertex{
	Vertex() = default;
    Vertex(Vector3 vertex, Vector2 uv) : Pos(vertex), UV(uv){}
    Vector3 Pos;
    Vector2 UV;
};
