#include <Assets/Asset.h>
#include "Debug/Debug.h"

Asset::Asset(AssetType type, const char* name): m_name(name), m_type(type)
{
}

Asset::~Asset()
{
}
