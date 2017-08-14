#include <Core/Scene_Management/SceneGraph.h>

SceneGraph::SceneGraph() : gameObjectCount(0)
{
}

SceneGraph::~SceneGraph()
{
	Destroy();
}

GameObject* SceneGraph::AddGameObject(const char* name)
{
	m_gameobjects.insert(std::make_pair(gameObjectCount, new GameObject(name, gameObjectCount)));
	return m_gameobjects[gameObjectCount++];
}

void SceneGraph::RemoveGameObject(GameObject* gameObject)
{
}

void SceneGraph::RemoveGameObject(const char* name)
{
}

void SceneGraph::RemoveAllGameObjectsByName(const char* name)
{
}

void SceneGraph::RemoveAllGameObjects()
{
}

GameObject* SceneGraph::FindGameObject(GameObject* gameObject)
{
	return nullptr;
}

GameObject* SceneGraph::FindGameObject(const char* name)
{
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end();)
	{
		if(it->second->GetName() == name)
		{
			return it->second;
		}
	}
	return nullptr;
}

std::vector<GameObject*> SceneGraph::FindAllGameObjectsByName(const char* name)
{
	std::vector<GameObject*> game_objects;
	return game_objects;
}

void SceneGraph::Destroy()
{
	//Delete all gameobjects and components attached to them
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		delete it->second;
	}
	m_gameobjects.clear();
}

void SceneGraph::Awake()
{
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		GameObject* game_object = it->second;
		for (auto it1 = game_object->m_components.begin(); it1 != game_object->m_components.end(); ++it1)
		{
			(*it1)->Awake();
		}
	}
}

void SceneGraph::Start()
{
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		GameObject* game_object = it->second;
		for (auto it1 = game_object->m_components.begin(); it1 != game_object->m_components.end(); ++it1)
		{
			(*it1)->Start();
		}
	}
}

void SceneGraph::FixedUpdate()
{
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		GameObject* game_object = it->second;
		for (auto it1 = game_object->m_components.begin(); it1 != game_object->m_components.end(); ++it1)
		{
			(*it1)->FixedUpdate();
		}
	}
}

void SceneGraph::Update()
{
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		GameObject* game_object = it->second;
		for (auto it1 = game_object->m_components.begin(); it1 != game_object->m_components.end(); ++it1)
		{
			(*it1)->Update();
		}
	}
}

void SceneGraph::LateUpdate()
{
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		GameObject* game_object = it->second;
		for (auto it1 = game_object->m_components.begin(); it1 != game_object->m_components.end(); ++it1)
		{
			(*it1)->LateUpdate();
		}
	}
}

void SceneGraph::Render()
{
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		GameObject* game_object = it->second;
		for (auto it1 = game_object->m_components.begin(); it1 != game_object->m_components.end(); ++it1)
		{
			(*it1)->Render();
		}
	}
}

void SceneGraph::DestroyGameobject(GameObject* gameObject)
{
}
