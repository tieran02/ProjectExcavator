#include <Core/Scene_Management/SceneManager.h>
#include "Debug/Debug.h"
#include "Assets/AssetManager.h"
#include "Assets/Shader.h"
#include "Core/Scene_Management/Scene.h"
#include <chrono>
#include <thread>

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
		if (this->m_currentScene != nullptr)
		{
			this->m_currentScene->unload();
			this->m_currentScene->GetSceneGraph().Destroy();
			AssetManager::Instance()->Destroy();
		}
		addDefaultAssets();
		this->m_currentScene = it->second;
		this->m_currentScene->load();
		Time::FixedDeltaTime = 0;
		Time::DeltaTime = 0;
	}
}

void SceneManager::ReloadScene() const
{
	if (this->m_currentScene != nullptr)
	{
		this->m_currentScene->unload();
		this->m_currentScene->GetSceneGraph().Destroy();
		AssetManager::Instance()->Destroy();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		addDefaultAssets();
		this->m_currentScene->load();
		Time::FixedDeltaTime = 0;
		Time::DeltaTime = 0;
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
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		Time::FixedDeltaTime = 0;
		Time::DeltaTime = 0;
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

void SceneManager::FixedUpdateScene() const
{
	if (this->m_currentScene != nullptr)
	{
		this->m_currentScene->fixedUpdate();
	}
	else
		LOG_ERROR("No current Scene");
}

void SceneManager::RenderScene() const
{
	if (this->m_currentScene != nullptr)
	{
		this->m_currentScene->render();
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

Scene* SceneManager::GetSceneFromSceneMap(const char* name)
{
	auto it = m_sceneMap.find(name);
	if (it == m_sceneMap.end())
	{
		LOG_ERROR("Scene doesn't exit in scene map");
		return nullptr;
	}

	return it->second;
}

void SceneManager::addDefaultAssets()
{
	const char* spriteVert = R""(
	#version 330 core
	layout (location = 0) in vec3 aPos;
	layout (location = 1) in vec2 aTexCoord;
	layout (location = 2) in vec4 aColor;
	out vec2 TexCoord;
	out vec4 Color;
	uniform mat4 view;
	void main()
	{
		gl_Position = view * vec4(aPos, 1.0f);
		TexCoord = aTexCoord;
		Color = aColor;
	}
	)"";

	const char* spriteFrag = R""(
	#version 330 core
	out vec4 FragColor;
	in vec2 TexCoord;
	in vec4 Color;
	uniform sampler2D texture1;
	void main()
	{
		vec4 texColor = texture(texture1, TexCoord) * Color;
		FragColor = texColor;
	}
	)"";

	AssetManager::Instance()->Add(new Shader("sprite_shader", spriteVert, spriteFrag, false));
}
