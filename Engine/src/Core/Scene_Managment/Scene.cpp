#include <Core/Scene_Management/Scene.h>
#include <Rendering/SpriteBatch.h>

Scene::Scene(const char* name) {
	this->m_sceneName = name;
}

void Scene::load() {
	//Create b2world with earths gravity
	b2Vec2 gravity(0.0f, static_cast<float>(-M_GRAVITY));
	m_world = std::make_unique<b2World>(gravity);

	this->OnLoad();
	m_spriteBatch.Init();
	m_sceneGrapth.Awake();
	m_sceneGrapth.Start();
	this->m_startTime = Time::ElpasedTime;
}

void Scene::unload() {
	this->OnUnload();
}

void Scene::update() {
	//Update Components
	this->OnUpdate();

}

void Scene::fixedUpdate()
{
	this->OnFixedUpdate();
	m_sceneGrapth.FixedUpdate();
	this->m_world.get()->Step(1.0f / 60.0f, 5, 5);


}

void Scene::lateUpdate()
{
	this->OnLateUpdate();
}

void Scene::render() {
	m_spriteBatch.Begin();
	//Update Render LateUpdate for components
	m_sceneGrapth.Update();
	m_spriteBatch.End();
	m_spriteBatch.Render();

}
