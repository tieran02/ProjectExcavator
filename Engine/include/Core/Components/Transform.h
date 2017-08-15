#pragma once

#include <Math/Math.h>
#include "Component.h"

class Transform : public Component{

public:
	Transform() : Component("Transform", true)
	{
		m_scale = Vector3(1, 1, 1);
	}

    Matrix4 TransformMatrix() const;
    const Matrix4 & TranslationMatrix() const;
    const Matrix4& ScaleMatrix() const;
    const Matrix4& Rotationatrix() const;

    const Vector3& GetPosition() const;
    const Vector2 GetPositionXY() const;
    void  SetPosition(Vector3 pos);
    void  SetPosition(Vector2 pos);
    const Vector3& GetScale()const;
    void  SetScale(Vector3 scale);
    const Quaternion& GetRotation() const;
    void SetRotation(Quaternion rot);

private:
    Matrix4 m_translationMatrix;
    Matrix4 m_scaleMatrix;
    Matrix4 m_rotationMatrix;

    Vector3 m_position;
    Vector3 m_scale;
    Quaternion m_rotation;

    void updateTranslationMatrix();
    void updateScaleMatrix();
    void updateRotationMatrix();
};
