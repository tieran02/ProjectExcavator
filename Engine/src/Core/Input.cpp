#include <Core/Input.h>

Input *Input::_instance = 0;

bool Input::KeyPress(int key) {

    if(Instance()->m_state[key].currentState == STATE_PRESS)
        return true;

	return false;
}

bool Input::KeyDown(int key) {
    if(Instance()->m_state[key].currentState == STATE_PRESS || Instance()->m_state[key].currentState == STATE_DOWN)
        return true;

	return false;
}

bool Input::KeyUp(int key) {
    if(Instance()->m_state[key].currentState == STATE_RELEASE)
        return true;

	return false;
}

void Input::SetState(int key, bool press) 
{
		Instance()->m_state[key].press = press;
}

void Input::Update()
{
	for (int i = 0; i < Instance()->m_state.size(); i++)
	{
		if (Instance()->m_state[i].lastState == STATE_NONE && Instance()->m_state[i].press)
			Instance()->m_state[i].currentState = STATE_PRESS;
		else if (Instance()->m_state[i].lastState == STATE_PRESS && Instance()->m_state[i].press)
			Instance()->m_state[i].currentState = STATE_DOWN;

		if(!Instance()->m_state[i].press && Instance()->m_state[i].lastState != STATE_RELEASE && Instance()->m_state[i].lastState != STATE_NONE)
			Instance()->m_state[i].currentState = STATE_RELEASE;
		else if(!Instance()->m_state[i].press && Instance()->m_state[i].lastState == STATE_RELEASE && Instance()->m_state[i].lastState != STATE_NONE)
			Instance()->m_state[i].currentState = STATE_NONE;

		Instance()->m_state[i].lastState = Instance()->m_state[i].currentState;
	}
}
