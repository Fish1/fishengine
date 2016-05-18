#ifndef RESOURCEMANAGER
#define RESOURCEMANAGER

#include <map>
#include <string>

class ResourceManager
{
private:

	std::map<std::string, void*> *m_resources;

private:

	ResourceManager();

	~ResourceManager();

public:

	static ResourceManager& instance()
	{
		static ResourceManager instance;

		return instance;
	}

	void* get(std::string key);

	void put(std::string key, void *object);
	
};

#endif
