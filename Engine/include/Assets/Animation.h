#pragma once
#include "Asset.h"
#include "Rendering/SpriteRegion.h"
#include <Assets/Sprite.h>
#include <vector>

struct Vector2;

class Animation : public Asset
{
public:
	Animation(const char* name, const char* textureName, int rows, int columns, int start, int end, float pixlesPerUnit = 100);
	~Animation() override;
	void Load() override;


	const int& Start() const { return m_start; }
	const int& End() const { return m_end; }
	const int& Rows() const { return m_rows; }
	const int& Columns() const { return m_columns; }
	std::vector<Sprite*> Sprites() const { return m_sprites; }

private:
	int m_start, m_end, m_rows, m_columns;
	float m_pixlesPerUnit;
	const char* m_name;
	const char* m_textureName;
	std::vector<Sprite*> m_sprites;
};
