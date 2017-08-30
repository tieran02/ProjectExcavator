#include <Core/Components/GameObject.h>
#include "Core/Components/Transform.h"
#include "Debug/Debug.h"
#include "Core/Components/ComponentManager.h"

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
	deleteComponents();
}

void GameObject::Create()
{
	this->m_transform = static_cast<Transform*>(this->AddComponent(new Transform));
}

void GameObject::Destroy(bool destroyChildren)
{
	if (!destroyChildren)
		moveChildren();
	else
		deleteChildren();
	deleteComponents();
}

Component* GameObject::AddComponent(Component* componenet)
{
	//Check if component should be unique and make sure it is not already added
	if (componenet->IsUnique())
	{
		for (auto it = this->m_components.begin(); it != this->m_components.end(); ++it)
		{
			if ((*it)->GetName() == componenet->GetName()) 
			{
				LOG_WARNING("Component '" << componenet->GetName() << "' already added and is unqie");
				return nullptr;
			}
		}
	}

	componenet->m_gameObject = this;
	ComponentManager::Instance()->AddComponent(componenet);
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

void GameObject::SetParent(GameObject* gameObject)
{
	if (gameObject != nullptr)
	{
		this->m_parent = gameObject;
		gameObject->AddChild(this);
	}
	else
	{
		//move gameobject outside of parent
		if(this->m_parent != nullptr)
		{
			this->m_parent->RemoveChild(this);
			this->m_parent = nullptr;
		}
	}
}

void GameObject::AddChild(GameObject* gameObject)
{
	//check if gameobject is not already a child
	auto it = this->m_children.find(gameObject->GetID());
	if(it == this->m_children.end())
	{
		this->m_children.insert(std::make_pair(gameObject->GetID(), gameObject));
	}

}

void GameObject::RemoveChild(GameObject* gameObject)
{
	auto it = this->m_children.find(gameObject->GetID());
	this->m_children.erase(it);
}

GameObject* GameObject::FindChildByName(const char* name)
{
	for (auto it = this->m_children.begin(); it != this->m_children.end(); ++it)
	{
		if ((*it).second->GetName() == name)
		{
			return it->second;
		}
	}
	return nullptr;
}

std::vector<GameObject*> GameObject::FindAllChildrenByName(const char* name)
{
	std::vector<GameObject*> children;
	for (auto it = this->m_children.begin(); it != this->m_children.end(); ++it)
	{
		if ((*it).second->GetName() == name)
		{
			children.push_back(it->second);
		}
	}
	return children;
}

void GameObject::moveChildren()
{
	for (auto it = this->m_children.begin(); it != this->m_children.end(); ++it)
	{
		(*it).second->SetParent(nullptr);
	}
}

void GameObject::deleteChildren()
{
	for (auto it = this->m_children.begin(); it != this->m_children.end(); ++it)
	{
		delete it->second;
	}
	this->m_children.clear();
}

void GameObject::deleteComponents()
{
	for (auto it = this->m_components.begin(); it != this->m_components.end(); ++it)
	{
		ComponentManager::Instance()->RemoveComponent(*it);
	}
	this->m_components.clear();
}
