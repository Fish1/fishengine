#ifndef FE_RESOURCEMANAGER
#define FE_RESOURCEMANAGER

#include <map>

#include <string>

#include <memory>

namespace sf
{
	class Font;

	class SoundBuffer;
}

namespace fe
{
	class ResourceManager
	{
	private:

		std::map<std::string, std::shared_ptr<void>> *m_resources;

	private:

		ResourceManager();

		~ResourceManager();

		std::shared_ptr<void> get(std::string key);
		
		void put(std::string key, std::shared_ptr<void> object);

	public:

		static ResourceManager& instance() 
		{
			static ResourceManager instance;

			return instance;
		}

		void loadSoundBuffer(std::string key, std::string fileName);

		sf::SoundBuffer& getSoundBuffer(std::string key);

		void loadFont(std::string key, std::string fileName);
	
		sf::Font& getFont(std::string key);

		void free(std::string key);
	
		void freeAll();
	};
}

#endif
