#include <Core/Scene_Management/SceneManager.h>
#include "Debug/Debug.h"
#include "Resources/AssetManager.h"
#include "Resources/Shader.h"

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
	auto it = m_sceneMap.find(name);
	if (it == m_sceneMap.end())
	{
		LOG_ERROR("Scene doesn't exit in scene map");
	}
	else
	{
		addDefaultAssets();
		this->m_currentScene = it->second;
		this->m_currentScene->load();
	}
}

void SceneManager::ReloadScene() const
{
	if (this->m_currentScene != nullptr)
	{
		this->m_currentScene->unload();
		this->m_currentScene->GetSceneGraph().Destroy();
		AssetManager::Instance()->Destroy();
		addDefaultAssets();
		this->m_currentScene->load();
	}
	else
		LOG_ERROR("No current Scene");
}

void SceneManager::UnloadScene()
{
	if (this->m_currentScene != nullptr)
	{
		this->m_currentScene->unload();
		this->m_currentScene->GetSceneGraph().Destroy();
		this->m_currentScene = nullptr;
		AssetManager::Instance()->Destroy();
		addDefaultAssets();
	}
	else
		LOG_ERROR("No current Scene");
}

void SceneManager::UpdateScene() const
{
	if (this->m_currentScene != nullptr)
	{
		this->m_currentScene->update();
	}
	else
		LOG_ERROR("No current Scene");
}

void SceneManager::RenderScene() const
{
	if (this->m_currentScene != nullptr)
	{
		this->m_currentScene->render();
		this->m_currentScene->lateUpdate();
	}
	else
		LOG_ERROR("No current Scene");
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
		LOG_ERROR("Scene doesn't exit in scene map");
	}
	else
	{
		return *it->second;
	}
}

void SceneManager::addDefaultAssets()
{
	const char* spriteVert = R""(
	#version 330 core
	layout (location = 0) in vec3 aPos;
	layout (location = 1) in vec2 aTexCoord;
	out vec2 TexCoord;
	uniform mat4 view;
	void main()
	{
		gl_Position = view * vec4(aPos, 1.0f);
		TexCoord = aTexCoord;
	}
	)"";

	const char* spriteFrag = R""(
	#version 330 core
	out vec4 FragColor;
	in vec2 TexCoord;
	uniform vec3 color = vec3(1,1,1);
	uniform sampler2D texture1;
	void main()
	{
		FragColor = texture(texture1, TexCoord) * vec4(color, 1.0);
	}
	)"";

	AssetManager::Instance()->Add(new Shader("sprite_shader", spriteVert, spriteFrag, false));
}
