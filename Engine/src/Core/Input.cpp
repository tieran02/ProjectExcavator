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
	if (Instance()->m_state[key].currentState == STATE_RELEASE) {
		Instance()->m_state[key].currentState = STATE_NONE;
		return true;
	}

	return false;
}

void Input::SetState(int key, unsigned char action)
{
	if ((Instance()->m_state[key].lastState == STATE_NONE || Instance()->m_state[key].lastState == STATE_RELEASE) && action == STATE_PRESS)
		Instance()->m_state[key].currentState = STATE_PRESS;
	if (Instance()->m_state[key].lastState == STATE_PRESS && action == STATE_DOWN)
		Instance()->m_state[key].currentState = STATE_DOWN;

	if (Instance()->m_state[key].lastState == STATE_DOWN && action == STATE_RELEASE)
		Instance()->m_state[key].currentState = STATE_RELEASE;
	if (Instance()->m_state[key].lastState == STATE_PRESS && action == STATE_RELEASE)
		Instance()->m_state[key].currentState = STATE_RELEASE;



	Instance()->m_state[key].lastState = action;
}