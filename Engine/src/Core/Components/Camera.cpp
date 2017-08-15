#include <Core/Components/Camera.h>
#include "Core/Game.h"
#include "Resources/ShaderAsset.h"
#include "Resources/AssetManager.h"

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
	ShaderAsset* shader = static_cast<ShaderAsset*>(AssetManager::Instance()->Get("sprite_shader"));
	if (shader != nullptr) {
		shader->Bind();
		shader->SetUniform("view", VPMatrix(), 1, false);
	}
}

void Camera::SetMain()
{
	MainCamera = this;
}

