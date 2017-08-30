#include <Assets/Animation.h>
#include <string>

Animation::Animation(const char* name, const char* textureName, int rows, int columns, int start, int end, float pixlesPerUnit) : Asset(AssetType::ANIMATION, name), m_start(start), m_end(end), m_rows(rows), m_columns(columns), m_pixlesPerUnit(pixlesPerUnit), m_name(name), m_textureName(textureName)
{
	m_sprites.resize(abs(end - start)+1);
}

Animation::~Animation()
{
	for (auto it = this->m_sprites.begin(); it != this->m_sprites.end(); ++it)
	{
		delete (*it);
	}
	this->m_sprites.clear();
}

void Animation::Load()
{
	for (unsigned int i = 0; i < this->m_sprites.size(); i++)
	{
		std::string name = this->m_name;
		name.append(std::to_string(i));
		this->m_sprites[i] = new Sprite(name.c_str(), this->m_textureName, SpriteRegion(this->m_start+i, this->m_rows, this->m_columns), this->m_pixlesPerUnit);
	}
}
