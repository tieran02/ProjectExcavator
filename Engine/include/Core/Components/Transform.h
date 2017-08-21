#pragma once

#include <Math/Math.h>
#include "Component.h"

class Transform : public Component{

public:
	Transform() : Component("Transform", true)
	{
		m_scale = Vector3(1, 1, 1);
	}

	void Update() override;

    Matrix4 TransformMatrix() const;
    Matrix4& TranslationMatrix();
    Matrix4& ScaleMatrix();
    Matrix4& Rotationatrix();

    Vector3& GetPosition();
    Vector2 GetPositionXY() const;
    void  SetPosition(Vector3 pos);
    void  SetPosition(Vector2 pos);
    Vector3& GetScale();
    void  SetScale(Vector3 scale);
    Quaternion& GetRotation();
    void SetRotation(Quaternion rot);
	Vector3& Velocity() { return m_velocity; }

	Vector2 Up() const;

	Vector2 Right() const;

private:
    Matrix4 m_translationMatrix;
    Matrix4 m_scaleMatrix;
    Matrix4 m_rotationMatrix;

    Vector3 m_position;
	Vector3 m_velocity;
	Vector3 m_lastPos;
    Vector3 m_scale;
    Quaternion m_rotation;

    void updateTranslationMatrix();
    void updateScaleMatrix();
    void updateRotationMatrix();
};
