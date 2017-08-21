#pragma once

struct Quaternion
{
    float		x, y, z, w;

    Quaternion(){
        x = y = z = 0;
        w = 1;
    }

    Quaternion(float a, float b, float c, float s)
    {
        x = a; y = b; z = c;
        w = s;
    }

    Quaternion(const Vector3& v, float s)
    {
        x = v.x; y = v.y; z = v.z;
        w = s;
    }

    void EulerAngles(Vector3 vec, float radians);

    Matrix4 GetRotationMatrix(void);
    void SetRotationMatrix(const Matrix4& m);

	Vector3 XYZ() const
	{
		return Vector3(x, y, z);
	}
};

inline Quaternion operator *(const Quaternion& q1, const Quaternion& q2)
{
    return (Quaternion(
            q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y,
            q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x,
            q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w,
            q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z));
}

inline Vector3 operator *(const Quaternion& q, const Vector3& v)
{
	Vector3 t = Cross(q.XYZ(), v) * 2;
	return  v + q.w * t + Cross(q.XYZ(), t);
}

inline bool operator!=(const Quaternion& a, const Quaternion& b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}