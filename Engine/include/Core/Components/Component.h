#pragma once

class Component {
	friend class GameObject;
public:
	Component();
	Component(const char* name);
	Component(const char* name, bool unique);
	virtual ~Component();

	virtual void Awake();
	virtual void Start();
	virtual void FixedUpdate();
	virtual void Update(){};
	virtual void LateUpdate();
	virtual void Render();
	virtual void Destroy();

	void SetGameObject(GameObject* game_object)
	{
		if (m_gameObject == nullptr)
			m_gameObject = game_object;
	}

	const char* GetName() const { return m_name; }
	GameObject& GetGameObject() const { return *m_gameObject; }
	bool IsUnique() const { return m_unique; }
	bool& Enabled() { return m_isEnabled; }

private:
	const char* m_name;
	GameObject* m_gameObject;
	Component* m_dependentComponent;
	bool m_isEnabled;
	bool m_unique;
};
