#include "Asset.h"
#include "Texture.h"

class Sprite : public Asset
{
public:
	Sprite(const char* name, const char* textureName, float width, float height);
	~Sprite() override;

	Texture* GetTexture() const {
		return m_texture;
	}
	void SetTexture(Texture* texture)
	{
		this->m_texture = texture;
	}

	float Width() const
	{
		return m_width;
	}

	float Height() const
	{
		return m_height;
	}

private:
	Texture* m_texture;
	float m_width, m_height;
};
