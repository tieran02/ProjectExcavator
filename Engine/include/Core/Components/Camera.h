#pragma once
#include <Core/Components/Transform.h>
#include "GameObject.h"
#include "Math/Rectangle.h"

class Camera : public Component
{
public:
	Camera(float width, float height, float near, float far);
	Camera() : Component("Camera"){ }
	~Camera() override;

	void CreateProjectionMatrix(float bottom, float top, float left, float right, float near, float far);

	void Awake() override;
	void Update() override;
	void SetMain();

	Matrix4 VPMatrix() const { return m_projectionMatrix * GetGameObject().GetTransform().TransformMatrix(); }

	static Camera* MainCamera;
	const float& GetSize() const { return m_size; }
	void SetSize(float size)
	{
		m_size = size;
		CreateProjectionMatrix(0, m_height * m_size, 0, m_width * m_size, m_near, m_far);
	}

	Math::Rectangle WorldBounds() const;

private:
	Matrix4 m_projectionMatrix;
	float m_size, m_width, m_height, m_near, m_far;

};
