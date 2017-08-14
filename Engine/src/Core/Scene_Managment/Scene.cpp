#include <Core/Scene_Management/Scene.h>

Scene::Scene(const char* name) {
	this->m_sceneName = name;
}

void Scene::load() {
	this->OnLoad();
	m_sceneGrapth.Awake();
	m_sceneGrapth.Start();
}

void Scene::unload() {
	this->OnUnload();
}

void Scene::update() {
	//Update Components
	this->OnUpdate();
	m_sceneGrapth.Update();
}

void Scene::fixedUpdate()
{
	this->OnFixedUpdate();
	m_sceneGrapth.FixedUpdate();
}

void Scene::lateUpdate()
{
	this->OnLateUpdate();
	m_sceneGrapth.LateUpdate();
}

void Scene::render() {
	this->OnRender();
	m_sceneGrapth.Render();

}