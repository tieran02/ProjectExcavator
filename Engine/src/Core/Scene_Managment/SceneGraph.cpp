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
	auto it = this->m_gameobjects.find(gameObject->GetID());
	destroyGameobject(it->second);
}

void SceneGraph::RemoveGameObject(const char* name)
{
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		if (it->second->GetName() == name)
		{
			destroyGameobject(it->second);
			return;
		}
	}
}

void SceneGraph::RemoveAllGameObjectsByName(const char* name)
{
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		if(it->second->GetName() == name)
			destroyGameobject(it->second);
	}
}

void SceneGraph::RemoveAllGameObjects()
{
	//Delete all gameobjects and components attached to them
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		delete it->second;
	}
	m_gameobjects.clear();
}

GameObject* SceneGraph::FindGameObject(GameObject* gameObject)
{
	auto it = this->m_gameobjects.find(gameObject->GetID());
	return it->second;
}

GameObject* SceneGraph::FindGameObject(const char* name)
{
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
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
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		if (it->second->GetName() == name)
		{
			game_objects.push_back(it->second);
		}
	}
	return game_objects;
}

void SceneGraph::Destroy()
{
	RemoveAllGameObjects();
}

void SceneGraph::Awake()
{
	for (auto it = this->m_gameobjects.begin(); it != this->m_gameobjects.end(); ++it)
	{
		GameObject* game_object = it->second;
		for (auto it1 = game_object->Components().begin(); it1 != game_object->Components().end(); ++it1)
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
		for (auto it1 = game_object->Components().begin(); it1 != game_object->Components().end(); ++it1)
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
		for (auto it1 = game_object->Components().begin(); it1 != game_object->Components().end(); ++it1)
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
		for (auto it1 = game_object->Components().begin(); it1 != game_object->Components().end(); ++it1)
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
		for (auto it1 = game_object->Components().begin(); it1 != game_object->Components().end(); ++it1)
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
		for (auto it1 = game_object->Components().begin(); it1 != game_object->Components().end(); ++it1)
		{
			(*it1)->Render();
		}
	}
}

void SceneGraph::destroyGameobject(GameObject* gameObject)
{
	//remove children
	for (auto it = gameObject->Children().begin(); it != gameObject->Children().end(); ++it)
	{
		auto child = this->m_gameobjects.find(it->second->GetID());
		this->m_gameobjects.erase(child);
	}
	//remove gameobject
	this->m_gameobjects.erase(gameObject->GetID());
	gameObject->Destroy(true);
}