#pragma once
#include <Core/Components/Transform.h>
#include "GameObject.h"

class Camera : public Component
{
public:
	Camera(float bottom, float top, float left, float right, float near, float far);
	Camera() : Component("Camera"){ }
	~Camera() override;

	void CreateProjectionMatrix(float bottom, float top, float left, float right, float near, float far);

	void Awake() override;
	void Update() override;
	void SetMain();

	Matrix4 VPMatrix() const { return m_projectionMatrix * GetGameObject().GetTransform().TransformMatrix(); }

	static Camera* MainCamera;

private:
	Matrix4 m_projectionMatrix;

};
