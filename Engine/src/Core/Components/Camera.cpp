#include <Resources/ResourceManager.h>
#include <Core/Components/Camera.h>
#include "Core/Game.h"

Camera* Camera::MainCamera = nullptr;

Camera::Camera(float bottom, float top, float left, float right, float _near, float _far) : Component("Camera")
{
	CreateProjectionMatrix(bottom, top, left, right, _near, _far);
}

Camera::~Camera()
{
}

void Camera::CreateProjectionMatrix(float bottom, float top, float left, float right, float _near, float _far)
{
	this->m_projectionMatrix = Matrix4::Ortho(bottom, top, left, right, _near, _far);
}

void Camera::Awake()
{
	CreateProjectionMatrix(0, Game::Instance()->GetWindow()->Height(), 0, Game::Instance()->GetWindow()->Width(), 0.1f, 1000.0f);
}

void Camera::Update()
{
	Shader* shader = ResourceManager::ShaderManagerInstance()->GetShader("sprite");
	if (shader != nullptr) {
		shader->Bind();
		shader->SetUniform("view", VPMatrix(), 1, false);
	}
}

void Camera::SetMain()
{
	MainCamera = this;
}

