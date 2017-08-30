#include <Assets/AssetManager.h>

AssetManager* AssetManager::m_instance = 0;

AssetManager::AssetManager()
{

}

AssetManager::~AssetManager()
{
	Destroy();
}

Asset* AssetManager::Add(Asset* asset)
{
	if (asset != nullptr) {
		this->m_assets.insert(std::pair<const char*, Asset*>(asset->GetName(), static_cast<Asset*>(asset)));
		asset->Load();
		return asset;
	}
	return nullptr;
}

void AssetManager::Destroy()
{
	m_assets.clear();
}

void AssetManager::DeleteAsset(const char* name)
{
	if(this->m_assets[name] != nullptr)
	{
		this->m_assets.erase(name);
	}
}

Asset* AssetManager::Get(const char* name)
{
	return  this->m_assets[name].get();
}
