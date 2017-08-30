#pragma once
#include <vector>
#include "Component.h"
//Handles all componets attached to gameobjects
class ComponentManager
{
public:

	static ComponentManager* Instance()
	{
		if (m_instance == nullptr)
			m_instance = new ComponentManager();
		return m_instance;
	}

	std::vector<Component*>& Components() { return m_components; }

	Component* AddComponent(Component* component);
	void RemoveComponent(Component* component);

	void Awake();
	void Start();
	void Update();
	void FixedUpdate();

private:
	std::vector<Component*> m_components;
	static ComponentManager* m_instance;
};
