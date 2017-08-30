#include <Core/Components/Camera.h>
#include "Core/Game.h"
#include "Assets/Shader.h"
#include "Assets/AssetManager.h"

Camera* Camera::MainCamera = nullptr;

Camera::Camera(float width, float height, float near, float far) : Component("Camera"), m_size(1), m_width(width), m_height(height),m_near(near),m_far(far)
{
	CreateProjectionMatrix(0, height, 0, width, near, far);
}

Camera::~Camera()
{
}

void Camera::CreateProjectionMatrix(float bottom, float top, float left, float right, float _near, float _far)
{
	this->m_projectionMatrix = Matrix4::Ortho(bottom, top*m_size, left, right*m_size, _near, _far);
}

void Camera::Awake()
{
}

void Camera::Update()
{
	Shader* shader = static_cast<Shader*>(AssetManager::Instance()->Get("sprite_shader"));
	if (shader != nullptr) {
		shader->Bind();
		shader->SetUniform("view", VPMatrix(), 1, false);
	}
}

void Camera::SetMain()
{
	MainCamera = this;
}

Math::Rectangle Camera::WorldBounds() const
{
	float Vert = this->m_size * (this->m_height * this->m_size);
	float Horz = Vert * (static_cast<float>(Game::Instance()->GetWindow()->Width()) / static_cast<float>(Game::Instance()->GetWindow()->Height()));
	Vector3 pos = GetGameObject().GetTransform().GetPosition();

	Math::Rectangle bounds;
	bounds.x = pos.x - Horz/2;
	bounds.y = pos.y - Vert/2;
	bounds.width = Horz;
	bounds.height = Vert;

	return bounds;
}

