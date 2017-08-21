#pragma once
class Asset
{
public:
	enum AssetType
	{
		SHADER,
		TEXTURE,
		SPRITE,
		ANIMATION,
		SOUND,
		TEXT
	};

	Asset(AssetType type, const char* name);
	virtual ~Asset();

	virtual void Load(){}
	const char* GetName() const { return m_name; }
private:
	const char* m_name;
	AssetType m_type;
};