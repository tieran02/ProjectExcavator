#include <Core/Components/ComponentManager.h>
ComponentManager* ComponentManager::m_instance = 0;

Component* ComponentManager::AddComponent(Component* component)
{
	this->m_components.push_back(component);
	return this->m_components.back();
}

void ComponentManager::RemoveComponent(Component* component)
{
	auto it = std::find(this->m_components.begin(), this->m_components.end(), component);
	this->m_components.erase(it);
	delete component;
}

void ComponentManager::Awake()
{
	for (auto& component : this->m_components)
	{
		component->Awake();
	}
}

void ComponentManager::Start()
{
	for (auto& component : this->m_components)
	{
		component->Start();
	}
}

void ComponentManager::Update()
{
	for(auto& component : this->m_components)
	{
		component->Update();
		component->Render();
		component->LateUpdate();
	}
}

void ComponentManager::FixedUpdate()
{
	for (auto& component : this->m_components)
	{
		component->FixedUpdate();
	}
}

