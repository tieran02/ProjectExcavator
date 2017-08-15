#pragma once
#include <unordered_map>
#include "Core/Components/GameObject.h"

class SceneGraph
{
public:
	SceneGraph();
	virtual ~SceneGraph();

	GameObject* AddGameObject(const char* name);

	void RemoveGameObject(GameObject* gameObject);
	void RemoveGameObject(const char* name);
	void RemoveAllGameObjectsByName(const char* name);
	void RemoveAllGameObjects();

	GameObject* FindGameObject(GameObject* gameObject);
	GameObject* FindGameObject(const char* name);
	std::vector<GameObject*> FindAllGameObjectsByName(const char* name);

	void Destroy();

	void Awake();
	void Start();
	void FixedUpdate();
	void Update();
	void LateUpdate();

	void Render();
private:
	std::unordered_map<unsigned int, GameObject*> m_gameobjects;
	unsigned int gameObjectCount;

	// Find and delete a gameobject from the scene graph and clear the memory
	// Also delete and clears the children attached to the game object recurrsivly
	void DestroyGameobject(GameObject* gameObject);
};
