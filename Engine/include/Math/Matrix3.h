#pragma once

#include "Vector3.h"

struct Matrix3
{
private:

    float		n[3][3];

public:

    Matrix3()
    {
        n[0][0] = 1; n[0][1] = 0; n[0][2] = 0;
        n[1][0] = 0; n[1][1] = 1; n[1][2] = 0;
        n[2][0] = 0; n[2][1] = 0; n[2][2] = 1;
    }

    Matrix3(float n00, float n01, float n02,
             float n10, float n11, float n12,
             float n20, float n21, float n22)
    {
        n[0][0] = n00; n[0][1] = n10; n[0][2] = n20;
        n[1][0] = n01; n[1][1] = n11; n[1][2] = n21;
        n[2][0] = n02; n[2][1] = n12; n[2][2] = n22;
    }

    Matrix3(const Vector3& a, const Vector3& b, const Vector3& c)
    {
        n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
        n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
        n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
    }

    float& operator ()(int i, int j)
    {
        return (n[j][i]);
    }

    const float& operator ()(int i, int j) const
    {
        return (n[j][i]);
    }

    Vector3& operator [](int j)
    {
        return (*reinterpret_cast<Vector3 *>(n[j]));
    }

    const Vector3& operator [](int j) const
    {
        return (*reinterpret_cast<const Vector3 *>(n[j]));
    }
};

inline Matrix3 operator *(const Matrix3& A, const Matrix3& B)
{
    return (Matrix3(A(0,0) * B(0,0) + A(0,1) * B(1,0) + A(0,2) * B(2,0),
                    A(0,0) * B(0,1) + A(0,1) * B(1,1) + A(0,2) * B(2,1),
                    A(0,0) * B(0,2) + A(0,1) * B(1,2) + A(0,2) * B(2,2),
                    A(1,0) * B(0,0) + A(1,1) * B(1,0) + A(1,2) * B(2,0),
                    A(1,0) * B(0,1) + A(1,1) * B(1,1) + A(1,2) * B(2,1),
                    A(1,0) * B(0,2) + A(1,1) * B(1,2) + A(1,2) * B(2,2),
                    A(2,0) * B(0,0) + A(2,1) * B(1,0) + A(2,2) * B(2,0),
                    A(2,0) * B(0,1) + A(2,1) * B(1,1) + A(2,2) * B(2,1),
                    A(2,0) * B(0,2) + A(2,1) * B(1,2) + A(2,2) * B(2,2)));
}

inline Vector3 operator *(const Matrix3& M, const Vector3& v)
{
    return (Vector3(M(0,0) * v.x + M(0,1) * v.y + M(0,2) * v.z,
                    M(1,0) * v.x + M(1,1) * v.y + M(1,2) * v.z,
                    M(2,0) * v.x + M(2,1) * v.y + M(2,2) * v.z));
}

inline float Determinant(const Matrix3& M)
{
    return (M(0,0) * (M(1,1) * M(2,2) - M(1,2) * M(2,1))
            + M(0,1) * (M(1,2) * M(2,0) - M(1,0) * M(2,2))
            + M(0,2) * (M(1,0) * M(2,1) - M(1,1) * M(2,0)));
}

inline Matrix3 Inverse(const Matrix3& M)
{
    const Vector3& a = M[0];
    const Vector3& b = M[1];
    const Vector3& c = M[2];

    Vector3 r0 = Cross(b, c);
    Vector3 r1 = Cross(c, a);
    Vector3 r2 = Cross(a, b);

    float invDet = 1.0F / Dot(r2, c);

    return (Matrix3(r0.x * invDet, r0.y * invDet, r0.z * invDet,
                     r1.x * invDet, r1.y * invDet, r1.z * invDet,
                     r2.x * invDet, r2.y * invDet, r2.z * invDet));
}