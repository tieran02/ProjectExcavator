#pragma once
enum class AssetType
{
	SHADER,
	TEXTURE,
	SPRITE,
	SOUND,
	TEXT
};

class Asset
{
public:
	Asset(AssetType type, const char* name);
	virtual ~Asset();

	virtual void Load(){}
	const char* GetName() const { return m_name; }
private:
	const char* m_name;
	AssetType m_type;
};