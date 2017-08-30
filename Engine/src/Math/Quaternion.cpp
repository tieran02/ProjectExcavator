//
// Created by tieran on 03/08/17.
//

#include <Math/Matrix4.h>
#include "Math/Quaternion.h"

Matrix4 Quaternion::GetRotationMatrix(void) {
    float x2 = x * x;
    float y2 = y * y;
    float z2 = z * z;
    float xy = x * y;
    float xz = x * z;
    float yz = y * z;
    float wx = w * x;
    float wy = w * y;
    float wz = w * z;

    return (Matrix4(
            1.0F - 2.0F * (y2 + z2), 2.0F * (xy - wz), 2.0F * (xz + wy), 0,
            2.0F * (xy + wz), 1.0F - 2.0F * (x2 + z2), 2.0F * (yz - wx), 0,
            2.0F * (xz - wy), 2.0F * (yz + wx), 1.0F - 2.0F * (x2 + y2), 0,
            0,0,0,1));
}

void Quaternion::SetRotationMatrix(const Matrix4 &m) {
    float m00 = m(0,0);
    float m11 = m(1,1);
    float m22 = m(2,2);
    float sum = m00 + m11 + m22;

    if (sum > 0.0F)
    {
        w = sqrt(sum + 1.0F) * 0.5F;
        float f = 0.25F / w;

        x = (m(2,1) - m(1,2)) * f;
        y = (m(0,2) - m(2,0)) * f;
        z = (m(1,0) - m(0,1)) * f;
    }
    else if ((m00 > m11) && (m00 > m22))
    {
        x = sqrt(m00 - m11 - m22 + 1.0F) * 0.5F;
        float f = 0.25F / x;

        y = (m(1,0) + m(0,1)) * f;
        z = (m(0,2) + m(2,0)) * f;
        w = (m(2,1) - m(1,2)) * f;
    }
    else if (m11 > m22)
    {
        y = sqrt(m11 - m00 - m22 + 1.0F) * 0.5F;
        float f = 0.25F / y;

        x = (m(1,0) + m(0,1)) * f;
        z = (m(2,1) + m(1,2)) * f;
        w = (m(0,2) - m(2,0)) * f;
    }
    else
    {
        z = sqrt(m22 - m00 - m11 + 1.0F) * 0.5F;
        float f = 0.25F / z;

        x = (m(0,2) + m(2,0)) * f;
        y = (m(2,1) + m(1,2)) * f;
        w = (m(1,0) - m(0,1)) * f;
    }
}

Quaternion Quaternion::EulerAngles(Vector3 vec, float radians) {
    float s = sinf(radians/2);
	Quaternion q;
     q.x = vec.x * s;
	 q.y = vec.y * s;
	 q.z = vec.z * s;
	 q.w = cosf(radians/2);
	 return q;
}
