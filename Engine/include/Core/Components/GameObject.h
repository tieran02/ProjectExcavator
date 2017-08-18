#pragma once
#include <Core/Components/Component.h>
#include <vector>
#include "Transform.h"
#include "RigidBody.h"

class GameObject
{
public:
	GameObject();
	GameObject(const char* name);
	GameObject(const char* name, unsigned int id);
	~GameObject();

	void Create();
	void Destroy();

	Component* AddComponent(Component* componenet);
	Component* FindComponentName(const char* name);

	template <typename T> T* FindComponentByType();

	void SetParent(GameObject* gameObject);
	GameObject* FindChildByName(const char* name);
	std::vector<GameObject*> FindAllChildrenByName(const char* name);

	const char* GetName() const { return m_name; }

	Transform& GetTransform() const { return *m_transform; }

	std::vector<Component*> m_components;

	RigidBody* GetRigidBody() const { return m_rigidBody; }
	void SetRigidBody(RigidBody* rb) { m_rigidBody = rb; }

private:
	unsigned int m_instanceID;
	const char* m_name;
	const char* m_tag;
	GameObject* m_parent;
	Transform* m_transform;
	RigidBody* m_rigidBody;

	std::vector<GameObject*> m_children;

	void deleteComponents();
	void moveChildren();
};
