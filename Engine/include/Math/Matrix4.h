#pragma once

#include "Vector4.h"
#include "Vector3.h"

struct Matrix4
{
protected:

    float       n[4][4];

public:

    Matrix4()
    {
        n[0][0] = 1; n[0][1] = 0; n[0][2] = 0; n[0][3] = 0;
        n[1][0] = 0; n[1][1] = 1; n[1][2] = 0; n[1][3] = 0;
        n[2][0] = 0; n[2][1] = 0; n[2][2] = 1; n[2][3] = 0;
        n[3][0] = 0; n[3][1] = 0; n[3][2] = 0; n[3][3] = 1;
    }

    Matrix4(float n00, float n01, float n02, float n03,
             float n10, float n11, float n12, float n13,
             float n20, float n21, float n22, float n23,
             float n30, float n31, float n32, float n33)
    {
        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20; n[0][3] = n30;
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21; n[1][3] = n31;
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22; n[2][3] = n32;
        n[3][0] = n03; n[3][1] = n13; n[3][2] = n23; n[3][3] = n33;
    }

    Matrix4(const Vector4& a, const Vector4& b, const Vector4& c, const Vector4& d)
    {
        n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z; n[0][3] = a.w;
        n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z; n[1][3] = b.w;
        n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z; n[2][3] = c.w;
        n[3][0] = d.x; n[3][1] = d.y; n[3][2] = d.z; n[3][3] = d.w;
    }

    float& operator ()(int i, int j)
    {
        return (n[j][i]);
    }

    const float& operator ()(int i, int j) const
    {
        return (n[j][i]);
    }

    Vector4& operator [](int j)
    {
        return (*reinterpret_cast<Vector4 *>(n[j]));
    }

    const Vector4& operator [](int j) const
    {
        return (*reinterpret_cast<const Vector4 *>(n[j]));
    }

	static Matrix4 Ortho(float bottom, float top, float left, float right, float _near, float _far)
    {
		return Matrix4(2 / (right - left), 0, 0, 0,
						0, 2 / (top - bottom), 0, 0,
						0, 0, -2 / (_far - _near), 0,
						0,0,0, 1);
    }

};

//Multiply two matrix 4 together
inline Matrix4 operator *(const Matrix4& A, const Matrix4& B)
{
    return (Matrix4(A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0) + A(0,3) * B(3,0), //First Row
                    A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1) + A(0,3) * B(3,1),
                    A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2) + A(0,3) * B(3,2),
                    A(0,0) * B(0,3) + A(0,1) * B(1,3) + A(0,2) * B(2,3) + A(0,3) * B(3,3), //~First Row
                    A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0) + A(1,3) * B(3,0), //Second Row
                    A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1) + A(1,3) * B(3,1),
                    A(1,0) * B(0,2) + A(1,1) * B(1,2) + A(1,2) * B(2,2) + A(1,3) * B(3,2),
                    A(1,0) * B(0,3) + A(1,1) * B(1,3) + A(1,2) * B(2,3) + A(1,3) * B(3,3), //~Second Row
                    A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0) + A(2,3) * B(3,0), //Third Row
                    A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1) + A(2,3) * B(3,1),
                    A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2) + A(2,3) * B(3,2),
                    A(2,0) * B(0,3) + A(2,1) * B(1,3) + A(2,2) * B(2,3) + A(2,3) * B(3,3), //~Third Row
                    A(3,0) * B(0,0) + A(3,1) * B(1,0) + A(3,2) * B(2,0) + A(3,3) * B(3,0), //Fourth Row
                    A(3,0) * B(0,1) + A(3,1) * B(1,1) + A(3,2) * B(2,1) + A(3,3) * B(3,1),
                    A(3,0) * B(0,2) + A(3,1) * B(1,2) + A(3,2) * B(2,2) + A(3,3) * B(3,2),
                    A(3,0) * B(0,3) + A(3,1) * B(1,3) + A(3,2) * B(2,3) + A(3,3) * B(3,3))); //~Fourth Row

}

inline Vector4 operator *(const Matrix4& A, const Vector4& v)
{
	return (Vector4(A(0, 0) * v.x + A(0, 1) * v.y + A(0, 2) * v.z + A(0, 3) * v.w,
				    A(1, 0) * v.x + A(1, 1) * v.y + A(1, 2) * v.z + A(1, 3) * v.w,
				    A(2, 0) * v.x + A(2, 1) * v.y + A(2, 2) * v.z + A(2, 3) * v.w,
				    A(3, 0) * v.x + A(3, 1) * v.y + A(3, 2) * v.z + A(3, 3) * v.w));

}

inline Matrix4 Inverse(const Matrix4& M)
{
    const Vector3& a = reinterpret_cast<const Vector3&>(M[0]);
    const Vector3& b = reinterpret_cast<const Vector3&>(M[1]);
    const Vector3& c = reinterpret_cast<const Vector3&>(M[2]);
    const Vector3& d = reinterpret_cast<const Vector3&>(M[3]);

    const float& x = M(3,0);
    const float& y = M(3,1);
    const float& z = M(3,2);
    const float& w = M(3,3);

    Vector3 s = Cross(a, b);
    Vector3 t = Cross(c, d);
    Vector3 u = a * y - b * x;
    Vector3 v = c * w - d * z;

    float invDet = 1.0F / (Dot(s, v) + Dot(t, u));
    s *= invDet;
    t *= invDet;
    u *= invDet;
    v *= invDet;

    Vector3 r0 = Cross(b, v) + t * y;
    Vector3 r1 = Cross(v, a) - t * x;
    Vector3 r2 = Cross(d, u) + s * w;
    Vector3 r3 = Cross(u, c) - s * z;

    return (Matrix4(r0.x, r0.y, r0.z, -Dot(b, t),
                     r1.x, r1.y, r1.z,  Dot(a, t),
                     r2.x, r2.y, r2.z, -Dot(d, s),
                     r3.x, r3.y, r3.z,  Dot(c, s)));
}
