//
// Created by tieran on 31/07/17.
//

#include <Core/Input.h>

Input *Input::_instance = 0;

bool Input::KeyPress(int key) {

    if(Instance()->keyStates[key] == STATE_PRESS)
        return true;
    else
        return false;
}

bool Input::KeyDown(int key) {
    if(Instance()->keyStates[key] == STATE_PRESS || Instance()->keyStates[key] == STATE_DOWN)
        return true;
    else
        return false;
}

bool Input::KeyUp(int key) {
    if(Instance()->keyStates[key] == STATE_RELEASE)
        return true;
    else
        return false;
}

void Input::SetState(int key, unsigned char state) {
    Instance()->keyStates[key] = state;
}
