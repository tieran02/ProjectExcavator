#pragma once
#include <Core/InputMarcros.h>
#include <vector>

struct InputState
{
	bool press;
	unsigned char currentState;
	unsigned char lastState;
};

class Input{
public:
    static bool KeyPress(int key);
    static bool KeyDown(int key);
    static bool KeyUp(int key);
    static void SetState(int key, bool press);
	static void Update();

    static Input* Instance(){
		if (!_instance)
		{
			_instance = new Input();
			_instance->m_state.resize(350);
		}
        return _instance;
    }
	
private:
	std::vector<InputState> m_state;
	static Input* _instance;
};
#pragma once