#include "ResourceManager.h"

ResourceManager::ResourceManager()
{
	m_resources = new std::map<std::string, void*>;
}

ResourceManager::~ResourceManager()
{
	delete m_resources;
}

void* ResourceManager::get(std::string key)
{
	return m_resources->at(key);
}

void ResourceManager::put(std::string key, void *object)
{
	m_resources->emplace(key, object);
}
