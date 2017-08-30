#pragma once
#include <Core/Game.h>
#include <unordered_map>
#include <Core/Scene_Management/Scene.h>

class SceneManager{
public:
	static SceneManager* Instance()
	{
		if(m_instance == nullptr)
			m_instance = new SceneManager;
		return m_instance;
	}

    void AddScene(const char* name, Scene* scene);
    void LoadScene(const char* name);
    void ReloadScene() const;
    void UnloadScene();
    void UpdateScene() const;
	void FixedUpdateScene() const;
    void RenderScene() const;

    void Destroy();

    Scene& GetCurrentScene() const;
    Scene* GetSceneFromSceneMap(const char* name);

private:
    Scene* m_currentScene;
    std::unordered_map<const char*,Scene*> m_sceneMap;
	static SceneManager* m_instance;

	static void addDefaultAssets();

};
