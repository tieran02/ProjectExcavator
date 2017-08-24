#pragma once
#include <Core/Components/Component.h>
#include <vector>
#include "Transform.h"
#include "RigidBody.h"
#include <unordered_map>

class GameObject
{
public:
	GameObject();
	GameObject(const char* name);
	GameObject(const char* name, unsigned int id);
	~GameObject();

	void Create();
	void Destroy(bool destroyChildren);

	Component* AddComponent(Component* componenet);
	Component* FindComponentName(const char* name);

	template <typename T> T* FindComponentByType()
	{
		for (auto itr = m_components.begin(); itr != m_components.end(); ++itr)
		{
			if (T* type = dynamic_cast<T*>(*itr))
			{
				return type;
			}
		}
		return nullptr;
	};

	void SetParent(GameObject* gameObject);
	GameObject* GetParent() const { return m_parent; }
	void AddChild(GameObject* gameObject);
	void RemoveChild(GameObject* gameObject);

	GameObject* FindChildByName(const char* name);
	std::vector<GameObject*> FindAllChildrenByName(const char* name);

	const char* GetName() const { return m_name; }
	const int GetID() const { return m_instanceID; }

	Transform& GetTransform() const { return *m_transform; }

	std::vector<Component*>& Components() { return m_components; }
	std::unordered_map<unsigned int, GameObject*>& Children() { return m_children; }

	RigidBody* GetRigidBody() const { return m_rigidBody; }
	void SetRigidBody(RigidBody* rb) { m_rigidBody = rb; }

private:
	unsigned int m_instanceID;
	const char* m_name;
	const char* m_tag;
	GameObject* m_parent;
	Transform* m_transform;
	RigidBody* m_rigidBody;

	std::vector<Component*> m_components;
	std::unordered_map<unsigned int,GameObject*> m_children;

	void deleteComponents();
	void moveChildren();
	void deleteChildren();
};
