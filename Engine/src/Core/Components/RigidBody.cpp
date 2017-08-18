#include <Core/Components/RigidBody.h>
#include <Core/Components/GameObject.h>
#include "Core/Scene_Management/SceneManager.h"

RigidBody::RigidBody(Vector2 dimensions, bool dynamic) : Component("RigidBody", true), m_body(nullptr), m_fixture(nullptr), m_mass(0), m_friction(0.0f), m_dimension(dimensions), m_dynamic(dynamic)
{
}

RigidBody::RigidBody(Vector2 dimensions, bool dynamic,float mass, float friction) : Component("RigidBody", true), m_body(nullptr), m_fixture(nullptr), m_mass(mass), m_friction(friction), m_dimension(dimensions), m_dynamic(dynamic)
{
}

void RigidBody::Awake()
{
	addToWorld();
	GetGameObject().SetRigidBody(this);
}


void RigidBody::FixedUpdate()
{
	GetGameObject().GetTransform().SetPosition(Vector2(m_body->GetPosition().x, m_body->GetPosition().y));
	Quaternion q;
	q.EulerAngles(Vector3(0, 0, 1), m_body->GetAngle());
	GetGameObject().GetTransform().SetRotation(q);
}

void RigidBody::SetVelocity(Vector2 velocity)
{
	this->m_body->SetLinearVelocity(b2Vec2(velocity.x, velocity.y));
}


void RigidBody::addToWorld()
{
	b2BodyDef bodyDef;
	if(m_dynamic)
		bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(GetGameObject().GetTransform().GetPosition().x, GetGameObject().GetTransform().GetPosition().y);
	m_body = SceneManager::Instance()->GetCurrentScene().PhysicsWorld()->CreateBody(&bodyDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(m_dimension.x / 2.0f, m_dimension.y / 2.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = m_mass;
	fixtureDef.friction = m_friction;
	m_fixture = m_body->CreateFixture(&fixtureDef);
}
