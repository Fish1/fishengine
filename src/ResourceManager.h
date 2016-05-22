#ifndef FE_RESOURCEMANAGER
#define FE_RESOURCEMANAGER

#include <map>

#include <string>

namespace sf
{
	class Font;
}

namespace fe
{
	class ResourceManager
	{
	private:

		std::map<std::string, void*> *m_resources;

	private:

		ResourceManager();

		~ResourceManager();

		void* get(std::string key);
		
		void put(std::string key, void *object);

	public:

		static ResourceManager& instance() 
		{
			static ResourceManager instance;

			return instance;
		}

		void loadFont(std::string key, std::string fileName);
	
		sf::Font& getFont(std::string key);

		void free(std::string key);
	
		void freeAll();
	};
}

#endif
