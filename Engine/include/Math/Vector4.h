#pragma once
#include <cmath>
#include <Math/Vector3.h>

struct Vector4
{
    float		x, y, z, w;

    Vector4() = default;

    Vector4(float a, float b, float c, float d)
    {
        x = a;
        y = b;
        z = c;
        w = d;
    }

	Vector4(Vector3 v, float d)
    {
		x = v.x;
		y = v.y;
		z = v.z;
		w = d;
    }

    float& operator [](int i)
    {
        return ((&x)[i]);
    }

    const float& operator [](int i) const
    {
        return ((&x)[i]);
    }

    Vector4& operator *=(float s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return (*this);
    }

    Vector4& operator /=(float s)
    {
        s = 1.0F / s;
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return (*this);
    }

    Vector4& operator +=(const Vector4& v)
    {
        x += v.x;
        y += v.y;
        z += v.z;
        w += v.w;
        return (*this);
    }

    Vector4& operator -=(const Vector4& v)
    {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        w -= v.w;
        return (*this);
    }

	Vector3 XYZ()
    {
		return Vector3(x, y, z);
    }
};

inline Vector4 operator *(const Vector4& v, float s)
{
    return (Vector4(v.x * s, v.y * s, v.z * s, v.w * s));
}


inline Vector4 operator /(const Vector4& v, float s)
{
    return (Vector4(v.x / s, v.y / s, v.z / s, v.w / s));
}

inline Vector4 operator -(const Vector4& v)
{
    return (Vector4(-v.x, -v.y, -v.z, -v.w));
}

inline Vector4 operator +(const Vector4& a, const Vector4& b)
{
    return (Vector4(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w));
}

inline Vector4 operator -(const Vector4& a, const Vector4& b)
{
    return (Vector4(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w));
}

inline bool operator!=(const Vector4& a, const Vector4& b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}

inline float Magnitude(const Vector4& v)
{
    return (sqrt(v.x * v.x + v.y *v.y + v.z * v.z + v.w * v.w));
}

inline Vector4 Normalize(const Vector4& v)
{
    return  (v/ Magnitude(v));
}

inline float Dot(const Vector4& a, const Vector4& b)
{
    return (a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w);
}