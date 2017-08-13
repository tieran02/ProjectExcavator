//
// Created by tieran on 03/08/17.
//

#include <Core/Components/Transform.h>


Matrix4 Transform::TransformMatrix() const {
    return this->m_translationMatrix * this->m_rotationMatrix * this->m_scaleMatrix;
}

const Matrix4 & Transform::TranslationMatrix() const {
    return this->m_translationMatrix;
}

const Matrix4 &Transform::ScaleMatrix() const {
    return this->m_scaleMatrix;
}

const Matrix4 &Transform::Rotationatrix() const {
    return this->m_rotationMatrix;
}

const Vector3 &Transform::GetPosition() const {
    return this->m_position;
}

const Vector2 Transform::GetPositionXY() const {
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

const Vector3 &Transform::GetScale() const {
    return this->m_scale;
}

void Transform::SetScale(Vector3 scale) {
    this->m_scale = scale;
    updateScaleMatrix();
}

const Quaternion &Transform::GetRotation() const {
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
