#include <Core/Components/GameObject.h>
#include "Core/Components/Transform.h"

GameObject::GameObject()
{
	this->m_name = "GameObject";
	this->m_tag = "";
	this->m_parent = nullptr;
	Create();
}

GameObject::GameObject(const char* name)
{
	this->m_name = name;
	this->m_tag = "";
	this->m_parent = nullptr;
	Create();
}

GameObject::GameObject(const char* name, unsigned id)
{
	this->m_name = name;
	this->m_tag = "";
	this->m_parent = nullptr;
	this->m_instanceID = id;
	Create();
}

GameObject::~GameObject()
{
	Destroy();
}

void GameObject::Create()
{
	this->m_transform = static_cast<Transform*>(this->AddComponent(new Transform));
}

void GameObject::Destroy()
{
	moveChildren();
	deleteComponents();
}

Component* GameObject::AddComponent(Component* componenet)
{
	componenet->m_gameObject = this;
	this->m_components.push_back(componenet);
	return this->m_components.back();
}

Component* GameObject::FindComponentName(const char* name)
{
	for (auto it = this->m_components.begin(); it != this->m_components.end(); ++it)
	{
		if((*it)->GetName() == name)
		{
			return *it;
		}
	}
	return nullptr;
}

template <typename T>
T* GameObject::FindComponentByType()
{
	return nullptr;
}

void GameObject::SetParent(GameObject* gameObject)
{
	this->m_parent = gameObject;
}

GameObject* GameObject::FindChildByName(const char* name)
{

	return nullptr;
}

std::vector<GameObject*> GameObject::FindAllChildrenByName(const char* name)
{
	std::vector<GameObject*> children;
	return children;
}

void GameObject::moveChildren()
{
	for (auto it = this->m_children.begin(); it != this->m_children.end(); ++it)
	{
		(*it)->SetParent(nullptr);
	}
}

void GameObject::deleteComponents()
{
	for (auto it = this->m_components.begin(); it != this->m_components.end(); ++it)
	{
		delete *it;
	}
	this->m_components.clear();
}
