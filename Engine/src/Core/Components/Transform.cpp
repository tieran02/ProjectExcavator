//
// Created by tieran on 03/08/17.
//

#include <Core/Components/Transform.h>
#include "Core/Time.h"


void Transform::Update()
{
	this->m_velocity = (this->m_position - this->m_lastPos) * (1.0f / Time::DeltaTime);

	this->m_lastPos = m_position;
}

Matrix4 Transform::TransformMatrix() const {
    return this->m_translationMatrix * this->m_rotationMatrix * this->m_scaleMatrix;
}

Matrix4& Transform::TranslationMatrix()  {
    return this->m_translationMatrix;
}

Matrix4 &Transform::ScaleMatrix() {
    return this->m_scaleMatrix;
}

Matrix4 &Transform::Rotationatrix() {
    return this->m_rotationMatrix;
}

Vector3 &Transform::GetPosition()  {
    return this->m_position;
}

Vector2 Transform::GetPositionXY() const {
    return Vector2(this->m_position.x,this->m_position.y);
}

void Transform::SetPosition(Vector3 pos) {
    this->m_position = pos;
    updateTranslationMatrix();
}

void Transform::SetPosition(Vector2 pos) {
    this->m_position = Vector3(pos.x,pos.y,this->m_position.z);
    updateTranslationMatrix();
}

Vector3 &Transform::GetScale() {
    return this->m_scale;
}

void Transform::SetScale(Vector3 scale) {
    this->m_scale = scale;
    updateScaleMatrix();
}

Quaternion &Transform::GetRotation() {
    return this->m_rotation;
}

void Transform::SetRotation(Quaternion rot) {
    this->m_rotation = rot;
    updateRotationMatrix();
}

void Transform::updateTranslationMatrix() {
    this->m_translationMatrix(0,3) = this->m_position.x;
    this->m_translationMatrix(1,3) = this->m_position.y;
    this->m_translationMatrix(2,3) = this->m_position.z;
}

void Transform::updateScaleMatrix() {
    this->m_scaleMatrix(0,0) = this->m_scale.x;
    this->m_scaleMatrix(1,1) = this->m_scale.y;
    this->m_scaleMatrix(2,2) = this->m_scale.z;
}

void Transform::updateRotationMatrix() {
    this->m_rotationMatrix = this->m_rotation.GetRotationMatrix();
}
