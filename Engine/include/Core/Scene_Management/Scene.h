#pragma once
#include "SceneGraph.h"

class Scene {
	friend class SceneManager;
public:
	Scene(const char* name);
	virtual ~Scene() {}

	virtual void OnLoad() {}
	virtual void OnUnload() {}
	virtual void OnUpdate() {}
	virtual void OnFixedUpdate() {};
	virtual void OnLateUpdate() {};
	virtual void OnRender() {}

	const char* GetSceneName() const { return m_sceneName; };
	SceneGraph& GetSceneGraph() { return m_sceneGrapth; }
private:
	void load();
	void unload();
	void update();
	void fixedUpdate();
	void lateUpdate();
	void render();

	SceneGraph m_sceneGrapth;
	const char* m_sceneName;
};
