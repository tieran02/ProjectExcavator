#include <Core/Components/Component.h>

Component::Component()
{
	this->m_name = "Component";
	this->m_isEnabled = true;
	this->m_gameObject = nullptr;
	this->m_dependentComponent = nullptr;
	this->Component::Awake();
}

Component::Component(const char* name)
{
	this->m_name = name;
	this->m_isEnabled = true;
	this->m_gameObject = nullptr;
	this->m_dependentComponent = nullptr;
	this->Component::Awake();
}

Component::Component(const char* name,bool unique)
{
	this->m_name = name;
	this->m_isEnabled = true;
	this->m_gameObject = nullptr;
	this->m_dependentComponent = nullptr;
	this->m_unique = unique;
	this->Component::Awake();
}

Component::~Component()
{
	Destroy();
}

void Component::Awake()
{
}

void Component::Start()
{
}

void Component::FixedUpdate()
{
}

void Component::LateUpdate()
{
}

void Component::Render()
{
}

void Component::Destroy()
{
}
