#include <Core/Scene_Management/SceneManager.h>
#include "Debug/Debug.h"
#include "Resources/ResourceManager.h"

SceneManager* SceneManager::m_instance = 0;

void SceneManager::AddScene(const char* name, Scene* scene)
{
	auto it = m_sceneMap.find(name);
	if(it == m_sceneMap.end())
	{
		//Add new Scene if name doesn't already exist
		this->m_sceneMap.insert(std::make_pair(name,scene));
	}
}

void SceneManager::LoadScene(const char* name)
{
	ResourceManager::ShaderManagerInstance()->AddDefaultShaders();
	auto it = m_sceneMap.find(name);
	if (it == m_sceneMap.end())
	{
		Debug::Log(logERROR, "Scene doesn't exit in scene map");
	}
	else
	{
		this->m_currentScene = it->second;
		this->m_currentScene->load();
	}
}

void SceneManager::ReloadScene() const
{
	if (this->m_currentScene != nullptr)
	{
		this->m_currentScene->unload();
		ResourceManager::Destroy();
		this->m_currentScene->load();
	}
	else
		Debug::Log(LogLevel::logERROR, "No current Scene");
}

void SceneManager::UnloadScene()
{
	if (this->m_currentScene != nullptr)
	{
		this->m_currentScene->unload();
		this->m_currentScene = nullptr;
		ResourceManager::Destroy();
	}
	else
		Debug::Log(LogLevel::logERROR, "No current Scene");
}

void SceneManager::UpdateScene() const
{
	if (this->m_currentScene != nullptr)
	{
		this->m_currentScene->update();
	}
	else
		Debug::Log(LogLevel::logERROR, "No current Scene");
}

void SceneManager::RenderScene() const
{
	if (this->m_currentScene != nullptr)
	{
		this->m_currentScene->render();
		this->m_currentScene->lateUpdate();
	}
	else
		Debug::Log(LogLevel::logERROR, "No current Scene");
}

void SceneManager::Destroy()
{
	for (auto it = this->m_sceneMap.begin(); it != this->m_sceneMap.end();)
	{
		delete it->second;

		it = this->m_sceneMap.erase(it);
	}
	this->m_sceneMap.clear();
}

Scene& SceneManager::GetCurrentScene() const
{
	return *this->m_currentScene;
}

Scene& SceneManager::GetSceneFromSceneMap(const char* name)
{
	auto it = m_sceneMap.find(name);
	if (it == m_sceneMap.end())
	{
		Debug::Log(logERROR, "Scene doesn't exit in scene map");
	}
	else
	{
		return *it->second;
	}
}
