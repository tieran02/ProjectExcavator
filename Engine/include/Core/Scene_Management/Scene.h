#pragma once
#include <Core/Scene_Management/SceneGraph.h>
#include "Rendering/SpriteBatch.h"
#include "Core/Time.h"

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
	SpriteBatch* GetSpriteBatch() { return &m_spriteBatch; }
	double ElapsedSceneTime() const { return Time::ElpasedTime - m_startTime; }
	Color& SceneColor() { return m_sceneColor; }
private:
	void load();
	void unload();
	void update();
	void fixedUpdate();
	void lateUpdate();
	void render();

	SceneGraph m_sceneGrapth;
	SpriteBatch m_spriteBatch;
	const char* m_sceneName;
	double m_startTime;;
	Color m_sceneColor;
};
