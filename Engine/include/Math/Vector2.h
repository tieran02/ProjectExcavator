#pragma once
#include <cmath>

struct Vector2
{
    float x,y;

    Vector2() = default;

    Vector2(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

	static Vector2 One()
	{
		return Vector2(1.0f, 1.0f);
	}

	static Vector2 Zero()
	{
		return Vector2(0.0f, 0.0f);
	}

    float& operator [](int i)
    {
        return ((&x)[i]);
    }

    const float& operator [](int i) const
    {
        return ((&x)[i]);
    }

    Vector2& operator *=(float s)
    {
        x *= s;
        y *= s;
        return (*this);
    }

    Vector2& operator /=(float s)
    {
        x /= s;
        y /= s;
        return (*this);
    }

    Vector2& operator +=(const Vector2& v)
    {
        x += v.x;
        y += v.y;
        return (*this);
    }

    Vector2& operator -=(const Vector2& v)
    {
        x -= v.x;
        y -= v.y;
        return (*this);
    }
};

inline Vector2 operator *(const Vector2& v, float s)
{
    return (Vector2(v.x * s, v.y * s));
}

inline Vector2 operator /(const Vector2& v, float s)
{
    return (Vector2(v.x / s, v.y / s));
}

inline Vector2 operator -(const Vector2& v)
{
    return (Vector2(-v.x, -v.y));
}

inline Vector2 operator +(const Vector2& a, const Vector2& b)
{
    return (Vector2(a.x + b.x, a.y + b.y));
}

inline Vector2 operator -(const Vector2& a, const Vector2& b)
{
    return (Vector2(a.x - b.x, a.y - b.y));
}

inline bool operator!=(const Vector2& a, const Vector2& b)
{
	return a.x == b.x && a.y == b.y;
}

inline float Magnitude(const Vector2& v)
{
    return (sqrt(v.x * v.x + v.y *v.y));
}

inline Vector2 Normalize(const Vector2& v)
{
    return  (v/ Magnitude(v));
}

inline float Dot(const Vector2& a, const Vector2& b)
{
    return (a.x * b.x + a.y * b.y);
}
