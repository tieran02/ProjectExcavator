#pragma once
#include <cmath>

struct Vector3
{
    float		x, y, z;

    Vector3() = default;

    Vector3(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }

	static Vector3 One()
	{
		return Vector3(1.0f, 1.0f, 1.0f);
	}

	static Vector3 Zero()
	{
		return Vector3(0.0f, 0.0f, 0.0f);
	}

	static Vector3 Up()
	{
		return Vector3(0.0f, 1.0f, 0.0f);
	}

	static Vector3 Right()
	{
		return Vector3(1.0f, 0.0f, 0.0f);
	}

	static Vector3 Forward()
	{
		return Vector3(0.0f, 0.0f, 1.0f);
	}

    float& operator [](int i)
    {
        return ((&x)[i]);
    }

    const float& operator [](int i) const
    {
        return ((&x)[i]);
    }

    Vector3& operator *=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    Vector3& operator /=(float s)
    {
        s = 1.0F / s;
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    Vector3& operator +=(const Vector3& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        return (*this);
    }

    Vector3& operator -=(const Vector3& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return (*this);
    }
};

inline Vector3 operator *(const Vector3& v, float s)
{
    return (Vector3(v.x * s, v.y * s, v.z * s));
}

inline Vector3 operator *(float s, const Vector3& v)
{
	return (Vector3(v.x * s, v.y * s, v.z * s));
}

inline Vector3 operator /(const Vector3& v, float s)
{
    return (Vector3(v.x / s, v.y / s, v.z / s));
}

inline Vector3 operator -(const Vector3& v)
{
    return (Vector3(-v.x, -v.y, -v.z));
}

inline float Magnitude(const Vector3& v)
{
    return (sqrt(v.x * v.x + v.y *v.y + v.z * v.z));
}

inline Vector3 operator +(const Vector3& a, const Vector3& b)
{
    return (Vector3(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3 operator -(const Vector3& a, const Vector3& b)
{
    return (Vector3(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline bool operator!=(const Vector3& a, const Vector3& b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

inline Vector3 Normalize(const Vector3& v)
{
    return  (v/ Magnitude(v));
}

inline float Dot(const Vector3& a, const Vector3& b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline Vector3 Cross(const Vector3& a, const Vector3& b)
{
    return (Vector3(a.y * b.z - a.z * b.y,
                     a.z * b.x - a.x * b.z,
                     a.x * b.y - a.y * b.x));
}