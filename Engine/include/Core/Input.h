#pragma once
#include <Core/InputMarcros.h>

class Input{
public:
    static bool KeyPress(int key);
    static bool KeyDown(int key);
    static bool KeyUp(int key);
    static void SetState(int key, unsigned char);

    static Input* Instance(){
        if(!_instance)
            _instance = new Input();
        return _instance;
    }

private:
    unsigned char keyStates[350];
    static Input* _instance;
};
#pragma once