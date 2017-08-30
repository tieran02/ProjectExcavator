#pragma once
#include "Assets/Sprite.h"

class Item
{
public:
	Item(){}
	~Item(){}

private:
	unsigned int m_uid;
	float m_sellPrice;
	unsigned int m_stacksize;
	Sprite* m_sprite;
};
