#pragma once
#include "Component.h"
#include <Box2D/Box2D.h>
#include "Math/Vector2.h"

class RigidBody : public Component
{
public:
	RigidBody(Vector2 dimensions, bool dynamic);
	RigidBody(Vector2 dimensions, bool dynamic, bool fixedRotation , float mass, float friction);

	void Awake() override;
	void FixedUpdate() override;

	void SetVelocity(Vector2 velocity) const;
	Vector2 GetVelocity() const;

private:
	b2Body* m_body;
	b2Fixture* m_fixture;
	float m_mass;
	float m_friction;
	Vector2 m_dimension;
	bool m_dynamic;
	bool m_fixed;

	void addToWorld();
};
