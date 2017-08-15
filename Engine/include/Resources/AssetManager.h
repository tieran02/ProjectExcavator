#pragma once
#include <unordered_map>
#include "Asset.h"
#include <memory>

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	static AssetManager* Instance()
	{ 
		if (m_instance == nullptr)
			m_instance = new AssetManager();
		return m_instance;
	}

	void Add(Asset* asset);
	Asset* Get(const char* name);
	void Destroy();
	void DeleteAsset(const char* name);
private:
	static AssetManager* m_instance;

	std::unordered_map<const char*, std::shared_ptr<Asset>> m_assets;
};
